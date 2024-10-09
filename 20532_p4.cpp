#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
vector<int> parent[100010];
int freq[100010];
int parents_divisors[100010];
int parent_freq[100010];

long long res;
void dfs(int num) {
  res += parents_divisors[freq[num]];
  vector<int> divide;
  for (int i = 1; i * i <= freq[num]; ++i) {
    if (freq[num] % i == 0) {
      parents_divisors[i]++;
      divide.push_back(i);
      res += parent_freq[i];
      if (i * i != freq[num]) {
        parents_divisors[freq[num] / i]++;
        res += parent_freq[freq[num] / i];
      }
    }
  }
  res -= parent_freq[freq[num]];
  parent_freq[freq[num]]++;
  for (const int &child : parent[num]) {
    dfs(child);
  }
  parent_freq[freq[num]]--;

  for (const int &e : divide) {
    parents_divisors[e]--;
    if (e * e != freq[num])
      parents_divisors[freq[num] / e]--;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> freq[i];
  }
  int cnt{};
  for (int i = 2; i <= n; ++i) {
    int tmp;
    cin >> tmp;
    parent[tmp].push_back(i);
  }
  dfs(1);
  cout << res << "\n";
}