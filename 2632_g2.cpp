#include <iostream>
using namespace std;

int pizzaA[2000], pizzaB[2000];
int Asums[1000001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("E:\\dev\\cpptest\\baekjoon\\input.txt","r",stdin);
    int wanted;
    cin>>wanted;
    int m,n;
    cin>>m>>n;
    long long cnt = 0;
    int totalA = 0, totalB = 0;
    for(int i=0; i<m; ++i){
        cin>>pizzaA[i];
        pizzaA[i+m] = pizzaA[i];
        totalA += pizzaA[i];
    }
    for(int i=0; i<n; ++i) {
        cin>>pizzaB[i];
        pizzaB[i+n] = pizzaB[i];
        totalB += pizzaB[i];
    }
    Asums[0]++;
    Asums[totalA]++;
    for(int i=0; i<m; ++i){
        int sum=0;
        for(int j=0; j<m-1; ++j){
            sum+=pizzaA[i+j];
            Asums[sum]++;
        }
    }
    cnt += Asums[wanted];

    for(int i=0; i<n; ++i){
        int sum =0;
        for(int j=0; j<n-1; ++j){
            sum+=pizzaB[i+j];
            if(wanted>=sum) cnt += Asums[wanted-sum];
        }
    }
    if(wanted>=totalB) cnt+=Asums[wanted-totalB];
    

    cout<<cnt;
}