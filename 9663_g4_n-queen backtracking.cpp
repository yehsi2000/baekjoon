#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int cnt = 0, n;
vector<int> row;

bool place(int rownum){
    for(int i=0; i<rownum; ++i){
        if(row[i] == row[rownum] || abs(row[i]-row[rownum]) == (rownum-i)){
            return false;
        }
    }
    return true;
}

void find(int rownum){
    if(n==rownum) cnt++;
    else {
        for(int i=0; i<n; ++i){
            row[rownum] = i;
            if(place(rownum)) {
                find(rownum+1);
            }
        }
    }
}

int main(){
    scanf("%d", &n);
    row = vector<int>(n);
    find(0);
    printf("%d", cnt);
}