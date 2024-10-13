#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int cnt{};
int n, m;
bool visited[500][500]={true,false,};
int dp[500][500] = {0,};
vector<vector<int>> board;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int dfs(int r, int c) {
  if (r == n - 1 && c == m -1) {
    return 1;
  }
  int start = board[r][c];
  int curcnt = 0;
  for (int i = 0; i < 4; ++i) {
    int nr = r+dir[i][0];
    int nc = c+dir[i][1];
    if (nr >= 0 && nr < n && nc >= 0 && nc < m && board[nr][nc] < start) {
      if(dp[nr][nc]>0) 
        curcnt+=dp[nr][nc];
      else if(dp[nr][nc]<0){
        continue;
      }
      else {
        visited[nr][nc] = true;
        curcnt += dfs(nr, nc);
        visited[nr][nc] = false;
      }
    }
  }
  if(curcnt)
    dp[r][c] = curcnt;
  else
    dp[r][c] = -1;
  return curcnt;
}

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  
  cin >> n >> m;
  //n=3; m=3;
  board = vector<vector<int>>(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> board[i][j];
      //board[i][j] = 1000-i-j;
    }
  }
  
  cout<<dfs(0, 0);
}