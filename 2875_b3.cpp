#include <cstdio>
#include <algorithm>
using namespace std;
int solve(int n, int m, int k){
    int leftover = 0;
    int maxteam = 0;
    if(n/2>m) {
        maxteam = m;
        leftover = n-2*maxteam;
    } else {
        maxteam = n/2;
        leftover = m-maxteam + n-maxteam*2;
        
    }
    if(leftover < k){
        int more = k-leftover;
        if(more%3 && more>3) more = more/3 + 1;
        else if(more>3) more /= 3;
        else more = 1;
        maxteam = max(maxteam - more, 0);
    }
    return maxteam;
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    printf("%d" , solve(n,m,k));
}