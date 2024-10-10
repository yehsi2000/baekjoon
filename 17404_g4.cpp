#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int main() {
	int i, j, k, n, arr[1000][3], dp[1001][3];
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < 3; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int ret = INF;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			dp[0][j] = INF;
		}
		dp[0][i] = arr[0][i]; //시작 색 정하기

    //0으로 초기화
		for (j = 1; j < 1001; j++) {
			for (k = 0; k < 3; k++) {
				dp[j][k] = 0;
			}
		}

    //두번째 집부터 n번째까지
		for (j = 1; j < n; j++) {
			for (k = 0; k < 3; k++) {
        //j번째집을 k색으로 칠하는비용 = k색칠하는비용 + 그전집을 k가아닌색으로 칠하는 비용
				dp[j][k] = arr[j][k] + min(dp[j - 1][(k + 1) % 3], dp[j - 1][(k + 2) % 3]);
			}
		}
		for (j = 0; j < 3; j++) {
			if (j == i) continue;
			ret = min(ret, dp[n - 1][j]);
		}
	}
	printf("%d\n", ret);
}