#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    long long s;
    cin >> n >> s;
    vector<int> list(n);
    for(int i=0; i<n; ++i){
        cin>>list[i];
    }
    int start = 0; int end = 1;
    long long sum=list[0];
    int shortest = n+1;
    while(end<=n){
        if(sum>=s) {
            shortest = min(shortest, end-start);
            sum-=list[start];
            if(start<end-1){
                start++;
            }
            else {
                start++;
                end++;
            }
        }
        else {
            end ++;
            sum+=list[end-1];
        }
    }
    if(shortest==n+1) cout<<0;
    else cout<<shortest;

}   