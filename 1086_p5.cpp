//string 나눗셈, gcd, 비트필드 dp

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int powof10[51];
long long dp[1 << 15][100];

long long Factorial(int n) {
  long long ret = 1;
  while (n > 1) {
    ret *= n--;
  }
  return ret;
}

long long Remainder(string root, int divide) {
  long long rem = 0;
  for (int i = 0; i < root.length(); ++i) {
    rem *= 10;
    rem += root[i] - '0';
    rem %= divide;
  }
  return rem;
}

long long GCD(long long big, long long small) {
  long long r;
  while (small != 0) {
    r = big % small;
    big = small;
    small = r;
  }
  return big;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  int n, k;
  cin >> n;
  vector<string> list(n + 1);
  vector<int> rlist(n + 1);
  for (int i = 0; i < n; ++i) cin >> list[i];
  cin >> k;
  dp[0][0] = 1;
  powof10[0] = 1 % k;
  for (int i = 1; i < 51; ++i) powof10[i] = (powof10[i - 1] * 10) % k;
  for (int i = 0; i < n; ++i) rlist[i] = Remainder(list[i], k);
  
  for (int bit = 0; bit < (1 << n); ++bit) {
    // ith bit on = used ith element
    for (int curidx = 0; curidx < n; ++curidx) {
      if ((bit & (1 << curidx)) == 0) {
        int withcur = bit | (1 << curidx);
        for (int r = 0; r < k; ++r) {
          // new remainder for concatenating current number on the back
          int nr = ((r * powof10[list[curidx].length()]) % k + rlist[curidx]) % k;
          dp[withcur][nr] += dp[bit][r];
        }
      }
    }
  }
  long long bottom = Factorial(n);
  long long top = dp[(1 << n) - 1][0];
  long long gcd = GCD(bottom, top);

  cout << (top / gcd) << "/" << (bottom / gcd);
}