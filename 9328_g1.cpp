#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

char board[101][101];
bool visited[101][101];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  int t, h, w;
  cin >> t;
  while (t--) {
    cin >> h >> w;
    for (int i = 0; i < h; ++i) {
      string tmp;
      cin >> tmp;
      for (int j = 0; j < w; ++j) {
        board[i][j] = tmp[j];
        visited[i][j] = false;
      }
    }
    vector<bool> keyset(26);
    string keys;
    cin >> keys;
    if (keys[0] != '0') {
      for (int i = 0; i < keys.length(); ++i) {
        keyset[keys[i]-'a'] =true;
      }
    }
    int stolendoc{};
    queue<pair<int, int>> doors[26];
    queue<pair<int, int>> q;
    for (int i = 0; i < h; ++i) {
      q.push({i, 0});
      q.push({i, w - 1});
    }
    for (int i = 0; i < w; ++i) {
      q.push({0, i});
      q.push({h - 1, i});
    }
    while (!q.empty()) {
      int r = q.front().first;
      int c = q.front().second;
      char curpos = board[r][c];
      q.pop();
      if ((visited[r][c]) || curpos == '*') {
        continue;
      }
      if (curpos >= 'A' && curpos <= 'Z' &&
          !keyset[curpos - 'A']) {
          doors[curpos-'A'].push({r,c});
          continue;
      }
      visited[r][c] = true;
      if (curpos == '$') {
        stolendoc++;
        board[r][c] = '.';
      }
      if (curpos >= 'a' && curpos <= 'z' && !keyset[curpos-'a']){
        keyset[curpos - 'a'] = true;
        while(!doors[curpos-'a'].empty()){
          q.push(doors[curpos-'a'].front());
          doors[curpos-'a'].pop();
        }
      }
      if (r > 0 && !visited[r - 1][c])
        q.push({r-1,c});
      if (c > 0 && !visited[r][c - 1])
        q.push({r,c-1});
      if (r < h - 1 && !visited[r + 1][c])
        q.push({r+1,c});
      if (c < w - 1 && !visited[r][c + 1])
        q.push({r,c+1});
    }
    cout << stolendoc << "\n";
  }
}