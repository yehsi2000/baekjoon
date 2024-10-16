#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int n;
vector<vector<char>> buffer;

void ChangeStar(int size, int r, int c) {
  if (size == 3) {
    buffer[r][c + 2] = '*';
    buffer[r + 1][c + 1] = '*';
    buffer[r + 1][c + 3] = '*';
    for (int i = 0; i < 5; ++i) {
      buffer[r + 2][c + i] = '*';
    }
    return;
  }
  ChangeStar(size / 2, r, c + size / 2);
  ChangeStar(size / 2, r + size /2, c);
  ChangeStar(size / 2, r + size /2, c + size);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);

  cin >> n;
  buffer = vector<vector<char>>(n, vector<char>(n * 2, ' '));
  ChangeStar(n, 0, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n * 2; ++j) {
      cout << buffer[i][j];
    }
    cout << "\n";
  }
}