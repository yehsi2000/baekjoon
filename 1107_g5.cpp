#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool broken[10] = {false,};

bool hasbroken(int target){
    if(target==0){
        if(broken[0]) return true;
        else return false;
    }
    while(target){
        if(broken[target%10]) return true;
        target/=10;
    }
    return false;
}
int solve(int target){
    int ans = abs(target-100);
    if(!broken[0]) min(target+1,ans);
    int flag = true;
    for(bool e : broken){
        if(e == false){
            flag=false;
            break;
        }
    }
    if(flag) return ans; //every button 🅱roke
    int up=target; int down=target;
    int newans=0;
    int found = 0;
    while(1){
        if(down>=0){
            if(!hasbroken(down)) {
                found = down;
                break;
            }
            down--;
        }
        if(!hasbroken(up)){
            found = up;
            break;
        }
        up++;
        newans++;
    }
    if(found==0) newans++;
    while(found>0){
        newans++;
        found/=10;
    }
    return min(newans,ans);
}

int main(){
    int target, n;
    scanf(" %d %d", &target, &n);
    
    for(int i=0; i<n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        broken[tmp] = true;
    }
    printf("%d",solve(target));
}