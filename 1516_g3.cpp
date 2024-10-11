#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  int n;
  cin>>n;
  vector<pair<int,int>> buildtime(n);
  vector<int> incnt(n);
  vector<vector<int>> opens(n);
  for(int i=0; i<n; ++i) {
    cin>>buildtime[i].first;
    while(1){
      int j;
      cin>>j;
      if(j==-1) break;
      incnt[i]++;
      opens[j-1].push_back(i);
    }
  }
  queue<int> zero_require;
  for(int i=0; i<n; ++i){
    if(incnt[i]==0){
      zero_require.push(i);
    }
  }
  vector<int> topolsorted;
  while(!zero_require.empty()){
    int front = zero_require.front();
    topolsorted.push_back(front);
    zero_require.pop();
    for(int e : opens[front]){
      buildtime[e].second = max(buildtime[e].second,buildtime[front].first+buildtime[front].second);
      if(--incnt[e]==0){
        zero_require.push(e);
      }
    }
  }

  for(int i=0; i<n; ++i){
    cout<<buildtime[i].first+buildtime[i].second<<"\n";
  }
}