#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n,k;
vector<int> list;


int main(){
    scanf("%d %d", &n, &k);
    list.resize(n);
    int maxlen = 0;
    for(int i=0; i<n; ++i){
        scanf(" %d", &list[i]);
        maxlen = max(maxlen, list[i]);
    }
    int start=1, end = maxlen;
    while(start<end){
        int cnt = 0 ;
        int pivot = (start>>1) + (end>>1) + ((start&1) ^ (end&1)) + ((start&1) & (end&1)); //ceil (start+end)/2
        for(int e : list) cnt += (e/pivot);
        if(cnt<k) end = pivot-1;
        else start = pivot;
    }

    printf("%d" ,start);
}