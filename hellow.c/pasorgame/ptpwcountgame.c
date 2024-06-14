#include <stdio.h>
#include <stdbool.h>

// 백트래킹을 통해 가능한 패턴을 찾는 함수
int dfs(bool 방문여부[], int 시작점, int 남은점갯수);
// 주 함수: m에서 n까지의 길이를 가지는 패턴의 수를 계산
int countPatterns(int m, int n);

int main() {
	int m = 4 ,n; // 최소 패턴 길이와 최대 패턴 길이
	printf("몇칸 움직이시겠습니까(최소4칸이상) : ");
	scanf("%d",&n);
	int 최종갯수 = countPatterns(m, n); // 패턴 수 계산
	printf("패턴 경우의 수 : %d\n", 최종갯수); // 결과 출력
	if(7<n&&n<=9){
	    printf("완벽해요!");
	}
	else if(5<n&&n<8){
	    printf("적당해요!");
	}
	else if(3<n&&n<6){
	    printf("조금 위험해요!");
	}
	return 0;
}

int skip[10][10];

// 두 점 사이의 중간 점을 설정하는 함수
void initializeSkip() {
	skip[1][3] = skip[3][1] = 2; // 1과 3 사이에는 2가 중간 점
	skip[1][7] = skip[7][1] = 4; // 1과 7 사이에는 4가 중간 점
	skip[3][9] = skip[9][3] = 6; // 3과 9 사이에는 6이 중간 점
	skip[7][9] = skip[9][7] = 8; // 7과 9 사이에는 8이 중간 점
	skip[1][9] = skip[9][1] = 5; // 1과 9 사이에는 5가 중간 점
	skip[2][8] = skip[8][2] = 5; // 2와 8 사이에는 5가 중간 점
	skip[3][7] = skip[7][3] = 5; // 3과 7 사이에는 5가 중간 점
	skip[4][6] = skip[6][4] = 5; // 4와 6 사이에는 5가 중간 점
}


int countPatterns(int m, int n) {
	
	bool 방문여부[10] = {false}; // 모든 점을 방문하지 않은 상태로 초기화
	int 최종갯수 = 0;
	for (int i = m; i <= n; i++) { // 최소 길이 m에서 최대 길이 n까지 반복
			// 1, 3, 7, 9는 대칭적이므로 한 번의 계산에 4배 곱함
			최종갯수 += dfs(방문여부, 1, i - 1) * 4;
			// 2, 4, 6, 8은 대칭적이므로 한 번의 계산에 4배 곱함
			최종갯수 += dfs(방문여부, 2, i - 1) * 4;
			// 5는 중심점이므로 그대로 더함
			최종갯수 += dfs(방문여부, 5, i - 1);
	}
	return 최종갯수;
}

int dfs(bool 방문여부[], int 시작점, int 남은점갯수) {
	if (남은점갯수 == 0) return 1;  // 남은 점의 수가 0이면 유효한 패턴
	initializeSkip(); // 점사이중간함수를 여기서 사용하겠음
	방문여부[시작점] = true; // 현재 점을 방문으로 표시
	int sum = 0;
	for (int i = 1; i <= 9; i++) { // 모든 점에 대해 반복
			int skip_num = skip[시작점][i];
			// 다음 점이 방문되지 않았고, 중간 점 조건을 만족하는 경우
			if (!방문여부[i] && (skip_num  == 0 || 방문여부[skip_num])) { //1-2-1 x 1-3-2x 1-2-3o
					sum += dfs(방문여부, i, 남은점갯수 - 1); // 재귀 호출로 다음 점으로 이동
			}
	}
	방문여부[시작점] = false; // 현재 점을 방문 취소
	return sum; // 가능한 패턴의 수 반환
}
