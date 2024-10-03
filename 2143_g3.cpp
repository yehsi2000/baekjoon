#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int listA[1001];
int listB[1001];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("E:\\dev\\cpptest\\baekjoon\\input.txt","r",stdin);
    int target, sumA=0, sumB=0;
    int n,m;
    cin>>target;
    cin>>n;
    for(int i=0; i<n; ++i){
        cin>>listA[i];
        sumA+=listA[i];
    }
    cin>>m;
    for(int i=0; i<m; ++i){
        cin>>listB[i];
        sumB+=listB[i];
    }
    vector<int> Asums, Bsums;
    for(int start=-1; start<n; ++start){
        int sum;
        if(start==-1) sum = sumA;
        else sum = sum-listA[start];
        int newsum =sum;
        for(int end=n-1; end>start && end>=0; --end){
            Asums.push_back(newsum);
            newsum-=listA[end];
        }
    }
    for(int start=-1; start<m; ++start){
        int sum;
        if(start==-1) sum = sumB;
        else sum = sum-listB[start];
        int newsum =sum;
        for(int end=m-1; end>start && end>=0; --end){
            Bsums.push_back(newsum);
            newsum-=listB[end];
        }
    }
    sort(Bsums.begin(),Bsums.end());
    long long cnt = 0;
    for(int i=0; i<Asums.size(); ++i){
        int val = target-Asums[i];
        cnt += upper_bound(Bsums.begin(),Bsums.end(),val)-lower_bound(Bsums.begin(),Bsums.end(),val);
    }

    cout<<cnt;
}