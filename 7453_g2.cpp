#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> abpos[256];
vector<int> abneg[256];
vector<int> cdpos[256];
vector<int> cdneg[256];
int visitcnt[(1<<21)+1];
short visited[(1<<21)+1];
int a[4001];
int b[4001];
int c[4001];
int d[4001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("E:\\dev\\cpptest\\baekjoon\\input.txt","r",stdin);
    
    int n;
    long long cnt=0;
    cin>>n;
    
    for(int i=0; i<n; ++i){
        cin>>a[i];
        cin>>b[i];
        cin>>c[i];
        cin>>d[i];
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            int absum = a[i]+b[j];
            int cdsum = c[i]+d[j];
            if(absum>0) abpos[absum&255].push_back(absum>>8);
            else abneg[(-absum)&255].push_back((-absum)>>8);
            if(cdsum>=0) cdpos[cdsum&255].push_back(cdsum>>8);
            else cdneg[(-cdsum)&255].push_back((-cdsum)>>8);
        }
    }
    long long curiter=0;
    for(int i=0; i<256; ++i){
        curiter++;
        for(int e :abpos[i]){
            if(visited[e]>0 && visited[e]!=curiter) visitcnt[e] = 0;
            visited[e] = curiter;
            visitcnt[e]++;
        }
        for(int e:cdneg[i]){
            if(visited[e]==curiter){
                 cnt+=visitcnt[e];
            }
        }
        curiter++;
        for(int e : abneg[i]){
            if(visited[e]>0 && visited[e]!=curiter) visitcnt[e] = 0;
            visited[e] = curiter;
            visitcnt[e]++;
        }
        for(int e : cdpos[i]){
            if(visited[e]==curiter){
                cnt+=visitcnt[e];
            }
        }
    }

    cout<<cnt;
}