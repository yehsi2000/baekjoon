#include <iostream>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string str;
    while(1){
        cin>>str;
        if(str=="0") break;
        int start = 0;
        int end = str.length()-1;
        bool flag = true;
        while(start<end){
            if(str[start]!=str[end]) {flag = false; break;}
            start++;end--;
        }
        if(flag) cout << "yes\n";
        else cout << "no\n";
    }
}