#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;


int cnt;

void getPrime(int n){
    if(n==1) return;
    deque<bool> isprime(n+1,true);
    for(int i=2;i*i<=n; ++i){
        if(isprime[i])
            for(int j=i*i; j<=n; j+=i)
                isprime[j] =false;
    }
    vector<int> primes;
    for(int i=2; i<=n; ++i){
        if(isprime[i]) primes.push_back(i);
    }

    int start = 0, end = 0, sum=0;
    int size = primes.size();
    while(end<=size){
        if(sum>=n) {
            sum-=primes[start++];
        }
        if(sum<n) {
            sum+=primes[end++];
        }
        if(sum==n) {
            cnt++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("E:\\dev\\cpptest\\baekjoon\\input.txt","r",stdin);
    int n;
    cin>>n;
    getPrime(n);
    cout<<cnt;

}