#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef pair<long long, long long> pll;

pll operator-(pll a, pll b) { return {a.first - b.first, a.second - b.second}; }

pll operator+(pll a, pll b) { return {a.first + b.first, a.second + b.second}; }

int CCW(pll a, pll b, pll c) {
  pll atob = b - a;
  pll atoc = c - a;
  long long f = (atob.second * atoc.first);
  long long s = (atob.first * atoc.second);
  if (f > s)
    return 1;
  else if (f == s)
    return 0;
  else
    return -1;
}

vector<int> parent;

int findPar(int idx) {
  if (parent[idx] != idx)
    return parent[idx] = findPar(parent[idx]);
  else
    return idx;
}

void unionPar(int a, int b) {
  int parA = findPar(parent[a]);
  int parB = findPar(parent[b]);
  if (parA != parB) {
    if (parA < parB)
      parent[parB] = parent[parA];
    else
      parent[parA] = parent[parB];
  }
}

bool isIntersecting(pair<pll,pll> &l1, pair<pll,pll> &l2) {
  int l1to2 = CCW(l1.first, l1.second, l2.first) * CCW(l1.first, l1.second, l2.second);
  int l2to1 = CCW(l2.first, l2.second, l1.first) * CCW(l2.first, l2.second, l1.second);

  if (l1to2 <= 0 && l2to1 <= 0) {
    if (l1to2 == 0 && l2to1 == 0) {
      return l2.first <= l1.second && l1.first <= l2.second;
    } else {
      return true;
    }
  } else {
    return false;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  int n;
  cin >> n;
  vector<pair<pll, pll>> linelist(n);
  parent = vector<int>(n);
  for (int i = 0; i < n; ++i) parent[i] = i;

  for (int i = 0; i < n; ++i) {
    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    pll a = {ax, ay};
    pll b = {bx, by};
    if (a > b)
      linelist[i] = {b, a};
    else
      linelist[i] = {a, b};
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if(isIntersecting(linelist[i],linelist[j])){
        unionPar(i,j);
      }
    }
  }
  int maxgroupsize=0;
  int totalgroups=0;
  vector<int> groups(n);
  for (int i = 0; i < n; ++i) {
    int iPar = findPar(i);
    if(groups[iPar]++==0) totalgroups++;
    if(groups[iPar]>maxgroupsize){
      maxgroupsize = groups[iPar];
    }
  }

  cout<<totalgroups<<"\n";
  cout<<maxgroupsize;
  
}

