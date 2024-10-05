#include <iostream>
#include <vector>
#include <deque>
#include <bitset>
#include <algorithm>
using namespace std;

struct node{
    int val;
    bitset<3> connects; //left right updown
};

int n, w;
vector<node> inside;
vector<node> outside;

inline int left(int num) {
    return (num-1+n)%n;
}

inline int right(int num) {
    return (num+1)%n;
}

int breaker(){
    for(int j=0; j<n; ++j){
        if(inside[j].connects.count()>0){
            if(inside[j].connects.count()==1) return j;
            if(inside[j].connects[0]) {
                inside[j].connects[0] =false;
                inside[left(j)].connects[1] = false;
            }
            else if(inside[j].connects[1]) {
                inside[j].connects[1] =false;
                inside[right(j)].connects[0] = false;
            }
            else if(inside[j].connects[2]) {
                inside[j].connects[2] =false;
                outside[j].connects[2] = false;
            }
            if(inside[j].connects.count()==1) return j;
        } else if(outside[j].connects.count()>0){
            if(outside[j].connects.count()==1) return j;
            if(outside[j].connects[0]) {
                outside[j].connects[0] =false;
                outside[left(j)].connects[1] = false;
            }
            else if(outside[j].connects[1]) {
                outside[j].connects[1] =false;
                outside[right(j)].connects[0] = false;
            }
            else if(outside[j].connects[2]) {
                outside[j].connects[2] =false;
                inside[j].connects[2] = false;
            }
            if(outside[j].connects.count()==1) return j+n;
        }
    }
    return -1;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("E:\\dev\\cpptest\\baekjoon\\input.txt","r",stdin);
    int t;
    cin>>t;
    for(int i=0; i<t; ++i){        
        cin>>n>>w;
        inside = vector<node>(n);
        outside = vector<node>(n);
        for(int j=0; j<n; ++j){
            cin>>inside[j].val;
            if(inside[left(j)].val && inside[left(j)].val + inside[j].val<=w){
                inside[j].connects[0] = true;
                inside[left(j)].connects[1]=true;
            }
            if(inside[right(j)].val && inside[right(j)].val + inside[j].val<=w) {
                inside[j].connects[1] = true;
                inside[right(j)].connects[0] = true;
            }
        }
        for(int j=0; j<n; ++j){
            cin>>outside[j].val;
            if(outside[left(j)].val && outside[left(j)].val + outside[j].val<=w) {
                outside[j].connects[0] = true;
                outside[left(j)].connects[1] = true;
            }
            if(outside[right(j)].val && outside[right(j)].val + outside[j].val<=w) {
                outside[j].connects[1] = true;
                outside[right(j)].connects[0] = true;
            }
            if(inside[j].val + outside[j].val<=w) {
                outside[j].connects[2] = true;
                inside[j].connects[2] = true;
            }
        }
        int cnt=0;
        deque<int> dq;
        for(int j=0; j<n; ++j){
            if(inside[j].connects.count()==1){
                dq.push_back(j);
            }
            if(outside[j].connects.count()==1){
                dq.push_back(j+n);
            }
        }
        if(dq.empty()){
            int add = breaker();
            if(add!=-1) dq.push_back(add);
        }
        while(!dq.empty()){
            int j = dq.front();
            dq.pop_front();
            if(j<n){
                if(inside[j].connects.count() != 1) {
                    if(dq.empty()){
                        int add = breaker();
                        if(add!=-1) dq.push_back(add);
                    }
                    continue;
                }
                if(inside[j].connects[2]) {
                    //only connection outside
                    if(outside[j].connects[0]) outside[left(j)].connects[1]=false;
                    if(outside[left(j)].connects.count()==1) dq.push_back(left(j)+n);

                    if(outside[j].connects[1]) outside[right(j)].connects[0]=false;
                    if(outside[right(j)].connects.count()==1) dq.push_back(right(j)+n);
                    
                    outside[j].connects.reset();
                } else if(inside[j].connects[1]){
                    //only connection rightside
                    if(inside[right(j)].connects[1]) inside[right(right(j))].connects[0]=false;
                    if(inside[right(right(j))].connects.count()==1) dq.push_back(right(right(j)));

                    if(inside[right(j)].connects[2]) outside[right(j)].connects[2]=false;
                    if(outside[right(j)].connects.count()==1) dq.push_back(right(j) + n);

                    inside[right(j)].connects.reset();
                } else {
                    //only connection leftside
                    if(inside[left(j)].connects[0]) inside[left(left(j))].connects[1]=false;
                    if(inside[left(left(j))].connects.count()==1) dq.push_back(left(left(j)));

                    if(inside[left(j)].connects[2]) outside[left(j)].connects[2]=false;
                    if(outside[left(j)].connects.count()==1) dq.push_back(left(j) + n);

                    inside[left(j)].connects.reset();
                }
                inside[j].connects.reset();
            } else {
                j-=n;
                if(outside[j].connects.count() != 1) {
                    if(dq.empty()){
                        int add = breaker();
                        if(add!=-1) dq.push_back(add);
                    }
                    continue;
                }
                if(outside[j].connects[2]) {
                    //only connection inside
                    if(inside[j].connects[0]) inside[left(j)].connects[1]=false;
                    if(inside[left(j)].connects.count()==1) dq.push_back(left(j));

                    if(inside[j].connects[1]) inside[right(j)].connects[0]=false;
                    if(inside[right(j)].connects.count()==1) dq.push_back(right(j));
                    
                    inside[j].connects.reset();
                } else if(outside[j].connects[1]){
                    //only connection rightside
                    if(outside[right(j)].connects[1]) outside[right(right(j))].connects[0]=false;
                    if(outside[right(right(j))].connects.count()==1) dq.push_back(right(right(j)) + n);

                    if(outside[right(j)].connects[2]) inside[right(j)].connects[2]=false;
                    if(inside[right(j)].connects.count()==1) dq.push_back(right(j));

                    outside[right(j)].connects.reset();
                } else {
                    //only connection leftside
                    if(outside[left(j)].connects[0]) outside[left(left(j))].connects[1]=false;
                    if(outside[left(left(j))].connects.count()==1) dq.push_back(left(left(j)) + n);

                    if(outside[left(j)].connects[2]) inside[left(j)].connects[2]=false;
                    if(inside[left(j)].connects.count()==1) dq.push_back(left(j));

                    outside[left(j)].connects.reset();
                }
                outside[j].connects.reset();
            }
            cnt++;
            if(dq.empty()){
                int add = breaker();
                if(add!=-1) dq.push_back(add);
            }
        }
        cout<<2*n-cnt<<"\n";
    }
}