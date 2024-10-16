//다익스트라 기본
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#define INF 100000001

using namespace std;


vector<pair<int,int>> roadFromTo[100001];
int n,m;
vector<int> dist;

void Dijikstra(int start){
  dist = vector<int>(n+1,INF);
  dist[start] = 0;
  priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
  pq.push({0,start});
  while(!pq.empty()){
    auto[weight,idx] = pq.top();
    pq.pop();
    if(weight>dist[idx]) continue;
    for(pair<int,int> ew : roadFromTo[idx]){
      if(dist[ew.first] > weight + ew.second){
        dist[ew.first] = weight + ew.second;
        pq.push({dist[ew.first],ew.first});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  
  cin>>n>>m;
  for(int i=0; i<m; ++i){
    int s, e, w;
    cin>>s>>e>>w;
    roadFromTo[s].push_back({e,w});
  }
  int start,end;
  cin>>start>>end;
  Dijikstra(start);
  cout<<dist[end];
}