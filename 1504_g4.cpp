#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>


using namespace std;

const int MAX = 200'000'001;
int n, e;

void findDist(int start, const vector<vector<pair<int, int>>> &linkList, vector<int> &dist) {
  dist[start] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, start});
  while (!pq.empty()) {
    int weight = pq.top().first;
    int idx = pq.top().second;
    pq.pop();
    for (const pair<int,int> e : linkList[idx]) {
      if (dist[e.first] > weight + e.second) {
        dist[e.first] = weight + e.second;
        pq.push({dist[e.first], e.first});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);

  cin >> n >> e;

  vector<vector<pair<int, int>>> link(n + 1);
  for (int i = 0; i < e; ++i) {
    int a, b, c;
    cin>>a>>b>>c;
    link[a].push_back({b, c});
    link[b].push_back({a, c});
  }
  int v1,v2;
  cin>>v1>>v2;
  vector<int> distfromstart(n + 1, MAX);
  vector<int> distfromv1(n + 1, MAX);
  vector<int> distfromv2(n + 1, MAX);
  findDist(1, link, distfromstart);
  findDist(v1, link, distfromv1);
  findDist(v2, link, distfromv2);
  int res = min((distfromstart[v1] + distfromv2[n]),distfromstart[v2] + distfromv1[n]) + distfromv1[v2];
  if (res>=MAX) cout<<-1;
  else cout<<res;
}