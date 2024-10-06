#include <iostream>
#include <vector>
#include <cstdlib>
#include <array>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("E:\\dev\\cpptest\\baekjoon\\input.txt","r",stdin);
    int n;
    cin>>n;
    vector<long long> chems(n);
    for(int i=0; i<n; ++i){
        cin>>chems[i];
    }
    sort(chems.begin(),chems.end());
    long long minsum=3000000000001LL;
    array<int,3> chemmix;
    for(int i=0; i<n-2; ++i){
        int start=i+1, end=n-1;
        while(start<end){
            long long sum = chems[i] + chems[start] + chems[end];
            if(sum>0){
                if(abs(sum) < minsum){
                    minsum = abs(sum);
                    chemmix = {i,start,end};
                }
                end--;
            } else if (sum<0){
                if(abs(sum) < minsum){
                    minsum = abs(sum);
                    chemmix = {i,start,end};
                }
                start++;
            } else {
                cout<< chems[i] << " " << chems[start] << " " << chems[end];
                return 0;
            }
        }
    }
    for(int i=0;i<3;++i){
        cout<< chems[chemmix[i]] << " ";
    }
}