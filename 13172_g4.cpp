#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
const long long MOD = 1'000'000'007;

long long Pow(long long base, long long exp) {
  if (exp == 1) return base % MOD;
  if (exp % 2) return base * Pow(base, exp - 1) % MOD;
  long long ret = Pow(base, exp / 2);
  return ret * ret % MOD;
}

long long InverseMod(const long long &num) { return Pow(num, MOD - 2); }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  int m;
  cin >> m;
  long long num, sum;
  long long div{}, E{};
  for (int i = 0; i < m; ++i) {
    cin >> num >> sum;
    div = gcd(num, sum);
    num /= div;
    sum /= div;
    E += (sum * InverseMod(num)) % MOD;
    E %= MOD;
  }
  cout << E;
  return 0;
}