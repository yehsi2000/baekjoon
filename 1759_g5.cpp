#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int L,C;
vector<char> alphabet;

void dfs(string passwd, int lastidx, int vowelcnt, int conscnt){
    int len = passwd.length();
    if(len == L && vowelcnt>0 && conscnt>1){
        cout<<passwd<<"\n";
        return;
    }

    for(int i=lastidx+1; i<C; ++i){
        int single = alphabet[i];
        if(single == 'a' || single == 'e' || single == 'i' || single == 'o' || single == 'u')
            dfs(passwd + alphabet[i],i,vowelcnt+1,conscnt);
        else 
            dfs(passwd + alphabet[i],i,vowelcnt,conscnt+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin>>L>>C;
    alphabet = vector<char>(C);
    for(int i=0; i<C; ++i){
        cin>>alphabet[i];
    }
    sort(alphabet.begin(),alphabet.end());
    dfs("", -1, 0, 0);
    

}