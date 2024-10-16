#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int list[10];
int printlist[10];

int n, m;

void SelectNum(int depth, int idx) {
  printlist[depth] = list[idx];
  if (depth == m-1) {
    for (int i = 0; i < m; ++i) {
      cout << printlist[i] << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = idx; i < n; i++) {
    SelectNum(depth+1, i);
    while (list[i + 1] == list[i]) i++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> list[i];
  }

  sort(list, list + n);

  for (int i = 0; i < n; ++i) {
    SelectNum(0, i);
    while (list[i + 1] == list[i]) i++;
  }
}