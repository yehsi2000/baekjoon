#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    int maxsum=0;
    sort(nums.begin(),nums.end());
    do{
        int sum=0;
        for(int i=0; i<n-1; i++){
            sum+=abs(nums[i]-nums[i+1]);
        }
        if(sum>maxsum) maxsum=sum;
    } while(next_permutation(nums.begin(),nums.end()));
    cout<<maxsum;

}