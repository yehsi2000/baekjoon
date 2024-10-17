#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>


using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  string input, bomb;
  cin >> input >> bomb;
  deque<pair<char, int>> dq;
  int idx = 0;
  for (char e : input) {
    if (!dq.empty() && e == bomb[dq.back().second])
      dq.push_back({e, dq.back().second + 1});
    else
      dq.push_back({e, e == bomb[0] ? 1 : 0});
    if (dq.back().second == bomb.size()) {
      for (int i = 0; i < bomb.size(); ++i) {
        dq.pop_back();
      }
    }
  }
  if (dq.empty())
    cout << "FRULA";
  else
    for (auto c : dq) cout << c.first;
}