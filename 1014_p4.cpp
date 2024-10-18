#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>


using namespace std;
int n, m;
vector<vector<bool>> desk;
vector<vector<int>> dp;

int bitcnt[1 << 11];

bool IsDeskBroken(int row, int colbit) {
  for (int i = 0; i < m; ++i) {
    if ((colbit & (1 << i)) && !desk[row][i]) return true;
  }
  return false;
}

bool adjcheck(int bit) {
  for (int i = 0; i < m - 1; ++i)
    if ((bit & (3 << i)) == (3 << i)) return true;
  return false;
}

bool CanCheat(int frontbit, int backbit) {
  for (int i = 0; i < m ; ++i) {
    if (i > 0 && (frontbit & (1 << i - 1)) && (backbit & (1 << i))) return true;
    if ((frontbit & (1 << i + 1)) && (backbit & (1 << i))) return true;
  }
  return false;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  int tc;
  string str;
  cin >> tc;
  for (int i = 0; i < (1 << 11); ++i) {
    bitset<11> ibt(i);
    bitcnt[i] = ibt.count();
  }
  while (tc--) {
    int maxcnt{};
    cin >> n >> m;
    desk = vector<vector<bool>>(n, vector<bool>(m, false));
    dp = vector<vector<int>>(n+1, vector<int>(1 << m+1, 0));
    for (int i = 0; i < n; ++i) {
      cin >> str;
      for (int j = 0; j < m; ++j) {
        if (str[j] == '.') desk[i][j] = true;
      }
    }
    // row에 cbit로 채웠을때
    for (int row = 0; row < n; ++row) {
      for (int cbit = 0; cbit < (1 << m); ++cbit) {
        if (IsDeskBroken(row, cbit) || adjcheck(cbit)) continue;
        if (row == 0){
          dp[row][cbit] = bitcnt[cbit];
          maxcnt = max(maxcnt, dp[row][cbit]);
        }
        else {
          for (int frontbit = 0; frontbit < (1 << m); ++frontbit) {
            if (CanCheat(frontbit, cbit)) continue;
            dp[row][cbit] = max(dp[row][cbit], dp[row - 1][frontbit] + bitcnt[cbit]);
            maxcnt = max(maxcnt, dp[row][cbit]);
          }
        }
      }
    }
    cout<<maxcnt<<'\n';
  }
}
