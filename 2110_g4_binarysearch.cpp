#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int housenum, routernum;
    scanf("%d %d", &housenum, &routernum);
    vector<int> houses(housenum);
    for(int i=0; i<housenum; ++i){
        scanf("%d", &houses[i]);
    }
    sort(houses.begin(),houses.end());
    int maxlen = houses[housenum-1]-houses[0];
    int start = 1, end = maxlen;
    while(start+1<end){
        int cnt=1;
        int mid = (start+end)/2;
        int init = houses[0];
        for(int i=1; i<housenum; ++i){
            if(houses[i] >= init + mid){
                cnt++;
                init = houses[i];
            }
        }
        if(cnt < routernum) end = mid;
        else start = mid;
        
    }
    printf("%d", start);
    

}