#include <iostream>
#include <queue>
using namespace std;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
int n,k;
bool visit[100001];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	pq.push({0,n});
	while(!pq.empty()){
		auto qtop = pq.top();
		pq.pop();
		visit[qtop.second] = true;
		if(qtop.second==k){
			cout<<qtop.first;
			break;
		}
        if(qtop.second<50001 && !visit[qtop.second*2]) pq.push({qtop.first,qtop.second*2});
		if(qtop.second<100001 && !visit[qtop.second+1]) pq.push({qtop.first+1,qtop.second+1});
		if(qtop.second>0 && !visit[qtop.second-1]) pq.push({qtop.first+1,qtop.second-1});	
	}
	
	return 0;
}