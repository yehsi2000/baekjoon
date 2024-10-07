#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> gems(n);
  vector<int> bags(k);
  for (int i = 0; i < n; ++i) {
    int mass, value;
    cin >> mass >> value;
    gems[i] = {mass, value};
  }
  for (int i = 0; i < k; ++i)
    cin >> bags[i];
  sort(gems.begin(), gems.end());
  sort(bags.begin(), bags.end());
  long long totalval = 0;
  priority_queue<int> pq;
  for (int bagidx = 0, gemidx = 0; bagidx < k; bagidx++) {
    for (; gemidx < n && gems[gemidx].first <= bags[bagidx]; ++gemidx) {
      pq.push(gems[gemidx].second);
    }

    if (!pq.empty()) {
      totalval += pq.top();
      pq.pop();
    }
  }

  cout << totalval;
}