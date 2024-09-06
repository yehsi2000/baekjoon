#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s1, s2;
int lcs[1001][1001] = {0,};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>s1>>s2;
    int i=1, j=1;
    for(;i<=s1.length();++i){
        for(j=1;j<=s2.length(); ++j){
            if(s1[i-1]==s2[j-1]) 
                lcs[i][j] = lcs[i-1][j-1] + 1;
            else 
                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
        }
    }
    printf("%d", lcs[i-1][j-1]);
}