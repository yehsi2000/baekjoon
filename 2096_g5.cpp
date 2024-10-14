#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int mindp[2][3];
int maxdp[2][3];


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  int n;
  cin>>n;
  for(int i=1; i<=n; ++i){
    int a,b,c;
    cin>>a>>b>>c;
    mindp[i%2][0] = min(mindp[(i+1)%2][0], mindp[(i+1)%2][1]) + a;
    maxdp[i%2][0] = max(maxdp[(i+1)%2][0], maxdp[(i+1)%2][1]) + a;

    mindp[i%2][1] = min(mindp[(i+1)%2][0], min(mindp[(i+1)%2][1],mindp[(i+1)%2][2])) + b;
    maxdp[i%2][1] = max(maxdp[(i+1)%2][0], max(maxdp[(i+1)%2][1],maxdp[(i+1)%2][2])) + b;

    mindp[i%2][2] = min(mindp[(i+1)%2][1], mindp[(i+1)%2][2]) + c;
    maxdp[i%2][2] = max(maxdp[(i+1)%2][1], maxdp[(i+1)%2][2]) + c;
  }
  cout<<max(maxdp[n%2][0],max(maxdp[n%2][1],maxdp[n%2][2])) << " "
    << min(mindp[n%2][0],min(mindp[n%2][1],mindp[n%2][2]));
}