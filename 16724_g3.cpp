#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<int> parent;
int board[1001][1001];
vector<bool> groupexist;

int findPar(int idx) {
  if (parent[idx] != idx) return parent[idx] = findPar(parent[idx]);
  return idx;
}

void unionPar(int a, int b) {
  int parA = findPar(parent[a]);
  int parB = findPar(parent[b]);
  if (parA != parB) {
    if (parA < parB)
      parent[parB] = parent[parA];
    else
      parent[parA] = parent[parB];
  }
}

void searchDir(int r, int c) {
  int nr = r + dir[board[r][c]][0];
  int nc = c + dir[board[r][c]][1];
  if (parent[r * m + c] == parent[nr * m + nc]) return;
  unionPar(r * m + c, nr * m + nc);
  searchDir(nr, nc);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);

  cin >> n >> m;
  parent = vector<int>(n * m);
  groupexist = vector<bool>(n * m);
  for (int i = 0; i < n; ++i) {
    string instr;
    cin >> instr;
    for (int j = 0; j < m; ++j) {
      parent[i * m + j] = i * m + j;
      if (instr[j] == 'U') board[i][j] = 0;
      if (instr[j] == 'R') board[i][j] = 1;
      if (instr[j] == 'D') board[i][j] = 2;
      if (instr[j] == 'L') board[i][j] = 3;
    }
  }
  int group = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (parent[i * m + j] != i * m + j) continue;
      searchDir(i, j);
    }
  }
  int cnt{};
  for (int i = 0; i < n * m; ++i) {
    int curgroup = findPar(i);
    if (!groupexist[curgroup]) {
      cnt++;
      groupexist[curgroup] = true;
    }
  }
  cout << cnt;
}