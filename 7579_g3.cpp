#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, memNeeded;
    cin>>n>>memNeeded;
    int totalcost=0;
    vector<pair<int,int>> progMemCost(n);    
    for(int i=0; i<n; ++i) cin>>progMemCost[i].first;
    for(int i=0; i<n; ++i) {
        cin>>progMemCost[i].second;
        totalcost+=progMemCost[i].second;
    }
    vector<int> dp(totalcost+1);
    for(int i=0; i<n; ++i){
        for(int j=totalcost; j>=0; --j){
            if(j>=progMemCost[i].second) 
                dp[j] = max(dp[j], dp[j-progMemCost[i].second] + progMemCost[i].first);
        }
    }
    int cost;
    for(cost=0; dp[cost]<memNeeded; cost++);
    cout<<cost;
    
}