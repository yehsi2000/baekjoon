#include <cstdio>
#include <vector>

using namespace std;

int main(){
    int n,m, min=2000000000, max=0;
    scanf("%d %d", &n, &m);
    vector<int> trees(n);
    for(int i=0; i<n; ++i){
        scanf("%d",&trees[i]);
        if(min>trees[i]) min = trees[i];
        if(max<trees[i]) max = trees[i];
    }
    int begin = 0, end = max, appr = (begin+end)/2;
    while(appr != begin && appr!=end){
        long long take = 0;
        
        for(int i=0; i<n; ++i){
            if(trees[i]>appr) take += (trees[i] - appr);
            if(take>2000000000) break;
        }
        if(take==m) break;
        if(take>m)  begin = appr;
        if(take<m) end = appr;
        appr = (begin+end)/2;
    }
    printf("%d", appr);

}