#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string init="";
    set<string> history;
    queue<pair<string,int>> statecntq;
    char c;
    for(int i=0; i<9; ++i) {
        cin>>c;
        init+=c;
    }
    history.insert(init);
    statecntq.push({init,0});
    int ret=-1;
    

    while(!statecntq.empty()){
        string curstr = statecntq.front().first;
        int cnt = statecntq.front().second;
        statecntq.pop();
        if(curstr == "123456780") {
            if(ret==-1) ret=cnt;
            else ret=min(ret,cnt);
            continue;
        }
        if(ret!=-1 && cnt>ret) continue;
        int zeroplace = curstr.find('0');
        int x = zeroplace%3, y = zeroplace/3;
        if(x<2){
            string moved = curstr;
            swap(moved[y*3+x],moved[y*3+x+1]);
            if(history.find(moved)==history.end()){
                history.insert(moved);
                statecntq.push({moved, cnt+1});
            }
        }
        if(x>0){
            string moved = curstr;
            swap(moved[y*3+x],moved[y*3+x-1]);
            if(history.find(moved)==history.end()){
                history.insert(moved);
                statecntq.push({moved, cnt+1});
            }
        }
        if(y>0){
            string moved = curstr;
            swap(moved[y*3+x],moved[y*3+x-3]);
            if(history.find(moved)==history.end()){
                history.insert(moved);
                statecntq.push({moved, cnt+1});
            }
        }
        if(y<2){
            string moved = curstr;
            swap(moved[y*3+x],moved[y*3+x+3]);
            if(history.find(moved)==history.end()){
                history.insert(moved);
                statecntq.push({moved, cnt+1});
            }
        }
    }

    cout<<ret;
    
    
}