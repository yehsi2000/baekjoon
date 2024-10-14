#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>


using namespace std;

int n, w;
int dp[1001][1001];
int trace[1001][1001];
vector<pair<int, int>> casepos;

int Manhatdist(const pair<int, int> &a, const pair<int, int> &b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

int Find(int p1_lastcase, int p2_lastcase){
  if(p1_lastcase == w || p2_lastcase == w) return 0;
  pair<int,int> p1pos, p2pos;
  if(dp[p1_lastcase][p2_lastcase]!=-1) return dp[p1_lastcase][p2_lastcase];

  p1pos = p1_lastcase ? casepos[p1_lastcase] : make_pair(1,1);
  p2pos = p2_lastcase ? casepos[p2_lastcase] : make_pair(n,n);

  int nextcase = max(p1_lastcase,p2_lastcase)+1;
  int next1 = Find(nextcase, p2_lastcase) + Manhatdist(casepos[nextcase],p1pos);
  int next2 = Find(p1_lastcase, nextcase) + Manhatdist(casepos[nextcase],p2pos);
  if(next1<next2){
    trace[p1_lastcase][p2_lastcase] = 1;
    return dp[p1_lastcase][p2_lastcase] = next1;
  } else {
    trace[p1_lastcase][p2_lastcase] = 2;
    return dp[p1_lastcase][p2_lastcase] = next2;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  cin >> n >> w;
  casepos = vector<pair<int, int>>(w+1);
  int tmp1, tmp2;
  fill(&dp[0][0],&dp[w][w],-1);
  for (int i = 1; i <= w; ++i) {
    cin >> tmp1 >> tmp2;
    casepos[i] = {tmp1, tmp2};
  }
  int mindist = Find(0,0);
  cout<<mindist<<"\n";
  int p1{}, p2{};
  for(int i=1; i<=w; ++i){
    if(trace[p1][p2] == 1){
      cout<<"1"<<"\n";
      p1=i;
    } else {
      cout<<"2"<<"\n";
      p2=i;
    }
  }
}