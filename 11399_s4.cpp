#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> time(n);
    for(int i=0;i<n;++i)
        scanf("%d",&time[i]);
    
    sort(time.begin(),time.end());
    int sum =0;
    for(int i=0; i<n; ++i){
        sum += time[i]*(n-i);
    }
    printf("%d", sum);
    
}