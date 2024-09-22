#include <cstdio>
#include <cstdlib>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int list[100];
int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;++i) scanf("%d", list+i);
    vector<int> b(n,0);
    b[0]=1;b[1]=1;b[2]=1;
    int ressum = 0;
    int diff = INT_MAX;
    do{
        int sum = 0;
        for(int i=0; i<n; ++i){
            if(b[i]) sum+=list[i];
        }
        int thisdiff = m-sum;
        if(thisdiff < diff && thisdiff>=0){
            diff = thisdiff;
            ressum = sum;
        }
    } while(prev_permutation(b.begin(),b.end()));
    printf("%d", ressum);
}