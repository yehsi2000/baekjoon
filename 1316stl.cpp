#include <iostream>

#include <string>
#include <unordered_set>
using namespace std;

int main()
{   
    int n, wordcnt=0;
    string str;
    
    
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>str;
        char lastchar;
        bool flag=true;
        unordered_set<char> charset;
        for(string::iterator i=str.begin();i!=str.end();++i){
            if(!charset.insert(*i).second && lastchar != *i){
                flag=false;
                break;
            }
            lastchar=*i;
        }
        if(flag) wordcnt++;
    }
    cout<<wordcnt;


    return 0;
}