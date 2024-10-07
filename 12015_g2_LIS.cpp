#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  int n;
  cin >> n;
  vector<int> list(n);
  for (int i = 0; i < n; ++i)
    cin >> list[i];
  vector<int> res{list[0]};
  for (int i = 1; i < n; ++i) {
    if (res.back() < list[i])
      res.push_back(list[i]);
    else {
      int start = -1, end = res.size();
      while (start + 1 < end) {
        int mid = (start + end) / 2;
        if (res[mid] < list[i]) {
          start = mid;
        } else {
          end = mid;
        }
      }
      res[end] = list[i];
    }
  }
  cout<<res.size();
}