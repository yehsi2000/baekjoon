#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;
int n, k;
int find(int pos){
    if(pos==n) {
        return 0;
    }
    if (pos%2==0 && pos>n && abs(pos - n) > abs(pos/2 - n)) { //2의 배수고 n보다 크고 2로 나눠야 n에 가까워질때
        while(pos%2==0 && pos>n) {
            pos>>=1;
            if(pos==n) return 0;
            if(pos==1) return 1;
        } //2로 나눠떨어지지않거나 n보다 작아질때까지
        pos = abs(pos-n) < abs(pos*2-n) ? pos : pos*2; //마지막에 나눠서 더 멀어진거 보정
    }
    if(pos<n){
        return n-pos;//n보다 작으면 앞으로 걷는수밖에 없음
    }
    int plus = find(pos+1);
    int minus = find(pos-1);
    return min(plus,minus)+1;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int j=0; j<n; ++j)
        for(int i=0; i<k; ++i)
            find(i);
    
    
}