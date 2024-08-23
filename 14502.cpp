//연구소 골4
#include <cstdio>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
int lab[8][8];
vector<int> space;
vector<int> virus;


void dfs(int v, vector<int> &vtest, unordered_set<int> &sprd){
    if(v%m!=m-1 && sprd.erase(v+1)){ //오른
        vtest.push_back(v+1);
        dfs(v+1,vtest,sprd);
    }
    if(v%m!=0 && sprd.erase(v-1)){ //왼
        vtest.push_back(v-1);
        dfs(v-1,vtest,sprd);
    }
    if(v!=n*m && sprd.erase(v+m)){ //아래
        vtest.push_back(v+m);
        dfs(v+m,vtest,sprd);
    }
    if(v!=0 && sprd.erase(v-m)){ //위
        vtest.push_back(v-m);
        dfs(v-m,vtest,sprd);
    }
}

int main(){
    scanf("%d %d", &n, &m);
    int input;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%d",&input);
            if(input==0) space.push_back(i*m+j);
            if(input==2) virus.push_back(i*m+j);
            lab[i][j]=input;
        }
    }

    int largest = 0;

    for(int i=0;i<space.size()-2;++i){
        for(int j=i+1;j<space.size()-1;++j){
            for(int k=j+1;k<space.size();++k){
                unordered_set<int> spread; //퍼지는 공간
                for(int e: space){
                    if(e!=space[i] && e!=space[j] && e!=space[k])
                        spread.insert(e); //벽 세개빼고 빈공간을 퍼질수있는 공간으로
                }
                bool flag = true; //한번이라도 퍼졌는지
                vector<int> virusexp(virus);
                for(int v: virus){
                    dfs(v, virusexp, spread);
                }
                
                if(spread.size()>largest) 
                    largest = spread.size();
            }
        }
    }
    printf("%d", largest);

    return 0;
}