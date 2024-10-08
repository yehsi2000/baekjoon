#include <algorithm>
#include <iostream>
#include <random>
#include <set>
#include <vector>

using namespace std;

int n, lowlimit, highlimit;
int land[50 * 50];
int opendir[50 * 50];
int findroot(int a) {
  int thisroot = opendir[a];
  if (thisroot == 0)
    return a;
  else
    return findroot(thisroot);
}

bool OpenGate() {
  bool flag = true;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (j < n - 1) {
        int rightdiff = abs(land[i * n + j] - land[i * n + j + 1]);
        if (rightdiff >= lowlimit && rightdiff <= highlimit) {
          opendir[i * n + j + 1] |= 1<<2; //left
          opendir[i * n + j] |= 1; // right
          flag = false;
        }
      }
      if (i < n - 1) {
        int lowdiff = abs(land[i * n + j] - land[(i + 1) * n + j]);
        if (lowdiff >= lowlimit && lowdiff <= highlimit) {
          opendir[(i + 1) * n + j] |= 1<<3;//up
          opendir[i * n + j] |= 1 << 1; // down
          flag = false;
        }
      }
    }
  }
  return flag;
}

void GetConnected(int idx, vector<int> &connected, vector<bool> &visited) {
  if (visited[idx])
    return;
  visited[idx] = true;
  connected.push_back(idx);
  if (opendir[idx] & 1)
    GetConnected(idx + 1, connected, visited);
  if (opendir[idx] & 2)
    GetConnected(idx + n, connected, visited);
  if (opendir[idx] & 4)
    GetConnected(idx - 1, connected, visited);
  if (opendir[idx] & 8)
    GetConnected(idx - n, connected, visited);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dis(1, 100);

  cin >> n >> lowlimit >> highlimit;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      //cin >> land[i * n + j];
      land[i*n+j] = dis(gen);
  int cnt = 0;
  while (cnt <= 2000) {
    if (OpenGate())
      break;
    vector<vector<int>> connect_list;
    int groupcnt{};
    vector<bool> visited(n * n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (visited[i * n + j]){
          opendir[i * n + j] = 0;
          continue;
        }
        if (opendir[i * n + j]) {
          groupcnt++;
          vector<int> cur_connected;
          GetConnected(i * n + j, cur_connected, visited);
          connect_list.push_back(cur_connected);
        }
        opendir[i * n + j] = 0;
      }
    }
    for (vector<int> connect : connect_list) {
      int sum = 0;
      for (int e : connect)
        sum += land[e];
      for (int e : connect)
        land[e] = sum / connect.size();
    }
    cnt++;
  }
  cout << cnt;
}