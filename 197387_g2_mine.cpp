#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// cross
int operator^(const pair<long long, long long> &a,
              const pair<long long, long long> &b) {
  if (a.first * b.second > a.second * b.first)
    return 1;
  if (a.first * b.second == a.second * b.first)
    return 0;
  else
    return -1;
}

pair<int, int> operator-(const pair<int, int> &a, const pair<int, int> &b) {
  return {a.first - b.first, a.second - b.second};
}

bool checkIntersect(const pair<long long, long long> &p1,
                    const pair<long long, long long> &p2,
                    const pair<long long, long long> &p3,
                    const pair<long long, long long> &p4) {
  pair<long long, long long> vec12 = p2 - p1;
  pair<long long, long long> vec13 = p3 - p1;
  pair<long long, long long> vec14 = p4 - p1;

  pair<long long, long long> vec34 = p4 - p3;
  pair<long long, long long> vec31 = p3 - p1;
  pair<long long, long long> vec32 = p3 - p2;

  int check12 = (vec13 ^ vec12) * (vec12 ^ vec14);
  int check34 = (vec31 ^ vec34) * (vec34 ^ vec32);
  if (check12 >= 0 && check34 >= 0) {
    if (check12 == 0 && check34 == 0) {
      return p3 <= p2 && p1 <= p4;
    } else {
      return true;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  long long x1, y1, x2, y2, x3, y3, x4, y4;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  pair<long long, long long> p1 = {x1, y1}, p2 = {x2, y2}, p3 = {x3, y3},
                             p4 = {x4, y4};
  if (p1 > p2)
    swap(p1, p2);
  if (p3 > p4)
    swap(p3, p4);
  if (checkIntersect(p1, p2, p3, p4)) {
    cout << 1;
  } else {
    cout << 0;
  }
}