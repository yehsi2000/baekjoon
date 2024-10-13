#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int find(int idx, vector<int>& player){
  if(player[idx]==-1) return idx;
  return player[idx] = find(player[idx], player);
}

int solve(int pnum, int turns){
  vector<int> board(pnum,-1);
  int a,b, apar, bpar;
  for(int i=1; i<=turns; ++i){
    cin>>a;
    cin>>b;
    if(i%2){  
      apar = find(a,board);
      bpar = find(b,board);
      if(apar == bpar){
        return i;
      } else {
        board[bpar] = apar;
      }
    } else {
      apar = find(a,board);
      bpar = find(b,board);
      if(apar == bpar){
        return i;
      } else {
        board[bpar] = apar;
      }
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  int pnum, turns;
  cin>>pnum >> turns;
  cout<<solve(pnum,turns);
  
}