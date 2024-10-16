#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int peoplecnt,partycnt;
int parent[51];

int findPar(int idx){
  if(parent[idx]!=idx) return parent[idx] = findPar(parent[idx]);
  else return parent[idx];
}

void Union(int a, int b){
  int parA = findPar(parent[a]);
  int parB = findPar(parent[b]);
  if(parA != parB){
    if(parA<parB) parent[parB] = parent[parA];
    else parent[parA] = parent[parB];
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  cin>>peoplecnt>>partycnt;
  int knowtruecnt;
  cin>>knowtruecnt;
  for(int i=1; i<=peoplecnt; ++i){
    parent[i] = i;
  }
  
}