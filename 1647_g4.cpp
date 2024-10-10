#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int parent[10];

int FindParent(int idx){
  if(parent[idx]) return parent[idx] = FindParent(parent[idx]);
  return idx;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);

  int n,m;
  vector<pair<int,pair<int,int>>> lines;
  cin>>n>>m;
  for(int i=0; i<m; ++i){
    int a,b,c;
    cin>>a>>b>>c;
    lines.push_back({c,{a,b}});
  }
  sort(lines.begin(), lines.end());
  int totalweight = 0;
  int maxweight = 0;
  int linecnt=0;
  for(int i=0; i<m && linecnt<n-1; ++i){
    auto top = lines[i];
    int a = top.second.first;
    int b= top.second.second;
    int c = top.first;
    if(FindParent(a) == FindParent(b)) continue;
    parent[FindParent(b)] = FindParent(a);
    totalweight += c;
    maxweight = max(maxweight,c);
    linecnt++;
  }
  cout<<totalweight - maxweight;
}