#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int ccw(pair<long long, long long> &p1, pair<long long, long long> &p2,
        pair<long long, long long> &p3) {
  long long res = (p1.first*p2.second + p2.first*p3.second + p3.first*p1.second) -
              (p2.first*p1.second + p3.first*p2.second + p1.first*p3.second);
  if (res > 0)
    return 1;
  else if (res == 0)
    return 0;
  else
    return -1;
}

bool isIntersecting(pair<long long, long long> &p1,
                    pair<long long, long long> &p2,
                    pair<long long, long long> &p3,
                    pair<long long, long long> &p4) {
  int p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
  int p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

  if (p1p2 <= 0 && p3p4 <= 0) {
    if (p1p2 == 0 && p3p4 == 0) {
      if (p1 > p2)
        swap(p1, p2);
      if (p3 > p4)
        swap(p3, p4);

      return p3 <= p2 && p1 <= p4;
    } else {
      return true;
    }
  } else {
    return false;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long x1, y1, x2, y2, x3, y3, x4, y4;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  pair<long long, long long> p1 = {x1, y1};
  pair<long long, long long> p2 = {x2, y2};
  pair<long long, long long> p3 = {x3, y3};
  pair<long long, long long> p4 = {x4, y4};
  if (isIntersecting(p1, p2, p3, p4)) {
    cout << 1;
  } else {
    cout << 0;
  }
}