#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

vector<pair<int,int>> chicken;
vector<pair<int,int>> house;
vector<vector<int>> combs;

int dist(pair<int,int> a, pair<int,int> b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}

void combination(int idx, int depth, vector<int>comb){
    if(comb.size()==depth){
        combs.push_back(comb);
        return;
    }
    else {
        for(int i=idx; i<chicken.size(); ++i){
            comb[depth] = i;
            combination(i+1,depth+1,comb);
        }
    }
}


int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            int temp;
            scanf("%d",&temp);
            if(temp==2) {
                chicken.push_back(make_pair(i,j));
            } else if(temp==1){
                house.push_back(make_pair(i,j));
            }
        }
    }

    combination(0,0,vector<int>(m));
    int smallest_comb = 1000000000;
    for(int i=0;i<combs.size();++i){
        int sum=0;
        for(int j=0;j<house.size();++j){
            int nearest=1000000000;
            for(int l=0;l<combs[i].size();++l){
                int len = dist(house[j],chicken[combs[i][l]]);
                if(nearest>len) nearest = len;
            }
            sum += nearest;
        }
        if(smallest_comb > sum) {
            smallest_comb = sum;
        }
    }
    printf("%d", smallest_comb);
}