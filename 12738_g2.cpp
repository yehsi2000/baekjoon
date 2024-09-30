#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    vector<int> dp;
    for(int i=0; i<n; ++i){
        int tmp;
        scanf("%d", &tmp);
        if(!dp.empty() && dp.back() >= tmp){
            *lower_bound(dp.begin(),dp.end(),tmp) = tmp;
        } else {
            dp.push_back(tmp);
        }
    }
    printf("%d", dp.size());
}