#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

struct State{
    vector<int> water;
};

bool operator<(const State one, const State other){
    if(one.water[0]<other.water[0]) return true;
    else if(one.water[0]==other.water[0]) {
        if(one.water[1]<other.water[1]) return true;
        else if(one.water[1]==other.water[1]) {
            if(one.water[2]<other.water[2]) return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<int> bottleSize(3);
    cin>>bottleSize[0]; cin>>bottleSize[1]; cin>>bottleSize[2];
    State init = {{0,0,bottleSize[2]}};
    int movemap[3][2] = {{1,2},{0,2},{0,1}};
    set<State> stset;
    stset.insert(init);
    queue<State> stq;
    stq.push(init);
    while(!stq.empty()){
        State front = stq.front();
        stq.pop();
        for(int i=0; i<3; ++i){
            if(front.water[i]!=0){
                for(int j=0; j<2; ++j){
                    int movebottle = movemap[i][j];
                    if(front.water[movebottle]!=bottleSize[movebottle]){
                        int pourAmount = min(front.water[i] ,bottleSize[movebottle] - front.water[movebottle]);
                        vector<int> nwater(front.water);
                        nwater[i] = front.water[i] - pourAmount;
                        nwater[movebottle] = front.water[movebottle] + pourAmount;
                        State ns = {nwater};
                        if(stset.find(ns)==stset.end()){
                            stset.insert(ns);
                            stq.push(ns);
                        }
                    }
                }
            }
        }
    }
    set<int> amtset;
    for(State st : stset){
        if(st.water[0]==0) amtset.insert(st.water[2]);
    }
    for(int e : amtset){
        if(e!=*amtset.begin()) cout<<" ";
        cout<<e;
    }



}