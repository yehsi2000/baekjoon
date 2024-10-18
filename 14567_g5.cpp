#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>


using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  int n, m;
  cin >> n >> m;
  int a, b;
  vector<vector<int>> opens(n + 1);
  vector<int> incnt(n + 1, 0);
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    opens[a].push_back(b);
    incnt[b]++;
  }
  deque<int> zeroins;
  for (int i = 1; i <= n; ++i) {
    if (incnt[i] == 0) {
      zeroins.push_back(i);
    }
  }
  vector<int> takes(n + 1);
  int term = 0;
  while (!zeroins.empty()) {
    term++;
    int size = zeroins.size();
    for (int i = 0; i < size; ++i) {
      int front = zeroins.front();
      zeroins.pop_front();
      takes[front] = term;
      for (int e : opens[front]) {
        incnt[e]--;
        if (incnt[e] == 0) {
          zeroins.push_back(e);
        }
      }
    }
  }

  for(int i=1; i<=n; ++i){
    cout<<takes[i]<<' ';
  }
}