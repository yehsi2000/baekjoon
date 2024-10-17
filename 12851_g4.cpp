#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dp[100001];


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  int n,k;
  for(int i=0; i<=100001; ++i){
    dp[i]=0x7fffffff;
  }
  cin>>n>>k;
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  pq.push({0,k});
  int mintime = 0x7fffffff;
  int cnt=0;
  while(!pq.empty()){
    int time = pq.top().first;
    int pos = pq.top().second;
    pq.pop();
    if(dp[pos]<time || time>mintime) continue;
    dp[pos] = time;
    if(pos==n) {
      if(mintime>time){
        mintime = time;
        cnt = 1;
      } else  if(mintime==time){
        cnt++;
      }
    } 
    if(pos>0 && pos%2==0 && dp[pos/2] >= time+1)
      pq.push({time+1,pos/2});
    if(pos<100000 && dp[pos+1] >=time+1)
      pq.push({time+1,pos+1});
    if(pos>0 && dp[pos-1] >= time+1)
      pq.push({time+1, pos-1});
  }
  cout<<mintime<<'\n'<<cnt;

}