#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 1000000001
using namespace std;
int a,b;

int cnt = MAX;

void Find(int num, int depth){
  if(num==a) {
    cnt = min(cnt,depth);
    return;
  }
  if(num<1) return;
  if(num%2==0) Find(num/2,depth+1);
  if(num%10==1) Find(num/10, depth+1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  
  cin>>a>>b;
  Find(b,1);
  if(cnt==MAX) cout<<-1;
  else cout<<cnt;
}