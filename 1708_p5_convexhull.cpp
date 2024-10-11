#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;

pair<int, int> points[100001];

int CCW(const pair<int, int> &a, const pair<int, int> &b, const pair<int, int> &c) {
  long long res1 = static_cast<ll>(b.first - a.first) * (c.second - a.second);
  long long res2 = static_cast<ll>(c.first - a.first) * (b.second - a.second);
  if (res1 > res2)
    return 1;
  else if (res1 == res2)
    return 0;
  else
    return -1;
}

long long Dist(const pair<int, int> &a, const pair<int, int> &b) {
  return static_cast<ll>(a.first - b.first) * (a.first - b.first) +
         static_cast<ll>(a.second - b.second) * (a.second - b.second);
}

bool CompRotate(const pair<int, int> &a, const pair<int, int> &b) {
  int res = CCW(a, b, points[0]);
  if (res == 0) return Dist(points[0], a) < Dist(points[0], b);
  return res > 0;
}

bool Comp(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second == b.second ? a.first < b.first : a.second < b.second;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    points[i] = {tmp1, tmp2};
  }

  sort(points, points + n, Comp);
  sort(points + 1, points + n, CompRotate);

  vector<int> st;
  st.push_back(0);
  st.push_back(1);
  for (int i = 2; i < n; ++i) {
    int a = *(st.end() - 2);
    int b = *(st.end() - 1);
    if (CCW(points[a], points[b], points[i]) > 0) {
      st.push_back(i);
    } else {
      while (st.size() > 1 && CCW(points[*(st.end() - 2)], points[*(st.end() - 1)], points[i]) <= 0) st.pop_back();
      st.push_back(i);
    }
  }
  cout << st.size();
}