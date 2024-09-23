#include <iostream>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    map<long long,int> scores;
    for(int i=0; i<n; ++i) {
        long long tmp;
        cin>>tmp;
        if(scores.find(tmp)!=scores.end()){
            scores[tmp]++;
        } else {
            scores.insert({tmp,1});
        }
    }
    pair<long long,int> maxpair = {0,0};
    for(pair<const long long,int> score : scores){
        if(score.second>maxpair.second) maxpair = score;
    }
    cout<<maxpair.first;
    return 0;
}