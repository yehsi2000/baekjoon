#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int input=0, sum=0, ret=-100000001;
    for(int i=0; i<n; ++i){
        cin>>input;
        sum+=input;
        ret = max(ret,sum);
        sum = max(sum,0);
    }
    cout<<ret;
}