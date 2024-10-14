#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

map<long long,long long> dp;
long long n,p,q;

long long calc(long long idx){
  if(dp.find(idx)!=dp.end()){
    return dp[idx];
  }
  return dp[idx] = calc(idx/p) + calc(idx/q);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  
  cin>>n>>p>>q;
  dp[0]=1;
  cout << calc(n);

}