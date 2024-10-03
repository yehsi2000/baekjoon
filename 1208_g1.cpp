#include <iostream>
#include <algorithm>
using namespace std;

int n, s;
int sumcnt[4000003] = {};
long long cnt;
const int OFFSET = 2000000;
int list[40];

void left(int idx, int sum){
    if(idx==n/2){
        ++sumcnt[OFFSET+sum];
        return;
    }
    left(idx+1, sum+list[idx]);
    left(idx+1, sum);
}

void right(int idx, int sum){
    if(idx==n){
        if(OFFSET+s-sum<=4000000)
            cnt += sumcnt[OFFSET+s-sum];
        return;
    }
    right(idx+1, sum+list[idx]);
    right(idx+1, sum);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("E:\\dev\\cpptest\\baekjoon\\input.txt","r",stdin);
    cin>>n>>s;
    for(int i=0; i<n; ++i) cin>>list[i];
    left(0,0);
    right(n/2,0);
    if(s==0) cnt--;
    cout<< cnt;    
}