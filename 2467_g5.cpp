#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    vector<int> list(n);
    for(int i=0; i<n; ++i) scanf("%d", &list[i]);
    pair<int,int> minpair;
    int minval=2'000'000'000;
    int top = list.size()-1;
    int bottom = 0;
    while(bottom<top) {
        int sum = list[bottom] + list[top];
        if(abs(sum) < minval) {
            minval = abs(sum);
            minpair = {list[bottom], list[top]};
        }
        if(sum>0) {
            top--;
        } else if(sum<0) {
            bottom++;
        } else {
            minpair = {list[bottom], list[top]};
            break;
        }
    }
    printf("%d %d", minpair.first, minpair.second);
}