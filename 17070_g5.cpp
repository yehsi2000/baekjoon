#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
  int n, room[17][17] = {}, dp[17][17][5] = {}; //r,c,모양

  scanf("%d", &n);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &room[i][j]);

  dp[0][1][1] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 2; j < n; j++) {
      if (room[i][j]) continue;
      dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][2];  //가로
      if (!room[i - 1][j] && !room[i][j - 1]) //대각선
        dp[i][j][2] = dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2] + dp[i - 1][j - 1][3];
      dp[i][j][3] = dp[i - 1][j][2] + dp[i - 1][j][3];
    }
  }

  printf("%d", dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2] + dp[n - 1][n - 1][3]);
  return 0;
}