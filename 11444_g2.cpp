#include <cstdio>
#include <map>
using namespace std;

long long div = 1000000007ll;
map<long long, long long> memo;

long long fibonacci(long long num) {
    if(num%2>0){
        long long plus, minus;
        if(memo.find((num+1)/2)!=memo.end()) 
            plus = memo.at((num+1)/2);
        else {
            plus = fibonacci((num+1)/2);
            memo.insert({(num+1)/2, plus});
        }
        if(memo.find((num-1)/2)!=memo.end()) 
            minus = memo.at((num-1)/2);
        else {
            minus = fibonacci((num-1)/2);
            memo.insert({(num-1)/2, minus});
        }
        memo.insert({num, (plus * plus + minus * minus) % div});
        return memo.at(num);
    } else {
        long long halfn, halfnminus, halfnplus;
        if(memo.find(num/2)!=memo.end())
            halfn = memo.at(num/2);
        else {
            halfn = fibonacci(num/2);
            memo.insert({num/2, halfn});
        }
        if(memo.find(num/2+1)!=memo.end())
            halfnminus = memo.at(num/2+1);
        else {
            halfnminus = fibonacci(num/2+1);
            memo.insert({num/2+1, halfnminus});
        }
        if(memo.find(num/2-1)!=memo.end())
            halfnplus = memo.at(num/2-1);
        else {
            halfnplus = fibonacci(num/2-1);
            memo.insert({num/2-1, halfnplus});
        }
        memo.insert({num, (halfn*(halfnminus+halfnplus)) % div});
        return memo.at(num);
    }
}

int main(){
    long long n;
    scanf("%lld", &n);
    memo.insert({0,0});
    memo.insert({1,1});
    memo.insert({2,1});
    memo.insert({3,2});
    memo.insert({4,3});
    printf("%lld",fibonacci(n));
}