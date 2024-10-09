#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int n;
int maxnum;

void move(int dir, vector<vector<int>> board, int depth) {
  if(depth==5){
    return;
  }
  // 0 up 1 down 2 left 3 right
  if (dir == 0) {//up
    for (int i = 0; i < n - 1; ++i) {
      for (int j = 0; j < n; ++j) {
        int down = i + 1;
        while (down < n-1 && !board[down][j])
          down++;
        if (board[i][j] == 0) {
          board[i][j] = board[down][j];
          board[down][j] = 0;
          maxnum = max(board[i][j],maxnum);
        }
        down = i + 1;
        while (down < n-1 && !board[down][j])
          down++;
        if (board[i][j] && board[i][j] == board[down][j]) {
          board[i][j] *= 2;
          board[down][j] = 0;
          maxnum = max(board[i][j],maxnum);
        }
      }
    }
  } else if (dir == 1) {//down
    for (int i = n - 1; i > 0; --i) {
      for (int j = 0; j < n; ++j) {
        int up = i - 1;
        while (up > 0 && !board[up][j])
          up--;
        if (board[i][j] == 0) {
          board[i][j] = board[up][j];
          board[up][j] = 0;
          maxnum = max(board[i][j],maxnum);
        }
        up = i - 1;
        while (up > 0 && !board[up][j])
          up--;
        if (board[i][j] && board[i][j] == board[up][j]) {
          board[i][j] *= 2;
          board[up][j] = 0;
          maxnum = max(board[i][j],maxnum);
        }
      }
    }
  } else if(dir == 2){//left
    for (int i = 0; i < n-1; ++i) {
      for (int j = 0; j < n; ++j) {
        int right = i + 1;
        while (right < n-1 && !board[j][right])
          right++;
        if (board[j][i] == 0) {
          board[j][i] = board[j][right];
          board[j][right] = 0;
          maxnum = max(board[j][i],maxnum);
        }
        right = i + 1;
        while (right < n-1 && !board[j][right])
          right++;
        if (board[j][i] && board[j][i] == board[j][right]) {
          board[j][i] *= 2;
          board[j][right] = 0;
          maxnum = max(board[j][i],maxnum);
        }
      }
    }
  } else if(dir==3){ //right
    for (int i = n-1; i > 0; --i) {
      for (int j = 0; j < n; ++j) {
        int left = i - 1;
        while (left > 0 && !board[j][left])
          left--;
        if (board[j][i] == 0) {
          board[j][i] = board[j][left];
          board[j][left] = 0;
          maxnum = max(board[j][i],maxnum);
        }
        left = i - 1;
        while (left > 0 && !board[j][left])
          left--;
        if (board[j][i] && board[j][i] == board[j][left]) {
          board[j][i] *= 2;
          board[j][left] = 0;
          maxnum = max(board[j][i],maxnum);
        }
      }
    }
  }
  for(int i=0; i<4;++i){
    move(i,board,depth+1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  cin >> n;
  vector<vector<int>> board(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> board[i][j];
      maxnum = max(maxnum,board[i][j]);
    }
  }
  move(-1, board, -1);
  cout<<maxnum;
}