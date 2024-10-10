#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
int n, m;
char board[10][10];

pair<int, int> dir[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int abs(int a){
  if(a<0) return -a;
  return a;
}

pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
  return {a.first + b.first, a.second + b.second};
}

pair<int, int> operator-(pair<int, int> a, pair<int, int> b) {
  return {a.first - b.first, a.second - b.second};
}

struct status {
  pair<int, int> bpos;
  pair<int, int> rpos;
  int depth;
  int lastmove;
};

pair<int, int> MoveBall(const pair<int, int> &curpos, const pair<int, int> &another, int d) {
  pair<int, int> cursor = curpos;
  pair<int,int> nextcursor = cursor + dir[d];
  pair<int, int> padding = {0, 0};
  while (cursor > make_pair(0, 0) && cursor < make_pair(n, n) &&
         board[nextcursor.first][nextcursor.second] != '#') {
    if (another == make_pair(nextcursor.first, nextcursor.second))
      padding = padding - dir[d];
    if (board[nextcursor.first][nextcursor.second] == 'O')
      return {nextcursor.first, nextcursor.second};
    cursor = nextcursor;
    nextcursor = nextcursor + dir[d];
  }

  return {cursor.first + padding.first, cursor.second + padding.second};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  pair<int, int> redpos, bluepos, holepos;
  for (int i = 0; i < n; ++i) {
    string tmp;
    cin >> tmp;
    for (int j = 0; j < m; ++j) {
      board[i][j] = tmp[j];
      if (board[i][j] == 'B') {
        bluepos = {i, j};
        board[i][j] = '.';
      }
      if (board[i][j] == 'R') {
        redpos = {i, j};
        board[i][j] = '.';
      }
      if (board[i][j] == 'O') holepos = {i, j};
    }
  }
  queue<status> q;
  q.push({bluepos, redpos, 0, -9});
  int ret = -1;
  bool found = false;
  while (!q.empty() && !found) {
    status cur = q.front();
    q.pop();
    if (cur.depth > 9) break;
    for (int i = 0; i < 4; ++i) {
      if(abs(i-cur.lastmove) == 2)
        continue;
      pair<int, int> nr = cur.rpos + dir[i];
      pair<int, int> nb = cur.bpos + dir[i];
      if (board[nr.first][nr.second] == '#' && board[nb.first][nb.second] == '#')
        continue;
      pair<int, int> bluemoved = MoveBall(cur.bpos, cur.rpos, i);
      pair<int, int> redmoved = MoveBall(cur.rpos, cur.bpos, i);
      if(bluemoved == holepos){
        continue;
      }
      else if (redmoved == holepos) {
        ret = cur.depth + 1;
        found = true;
        break;
      } else {
        q.push({bluemoved, redmoved, cur.depth + 1, i});
      }
    }
  }
  cout << ret;
}