#include <iostream>
#include <string>
#include <unordered_set>
#include <set>

using namespace std;

int main(void){
    int n,m;
    cin>>n>>m;
    unordered_set<string> notheard =unordered_set<string>();;
    for(int i=0; i<n; ++i){
        string tmp;
        cin>>tmp;
        notheard.insert(tmp);
    }
    set<string> deutbo = set<string>();
    for(int i=0; i<m; ++i){
        string tmp;
        cin>>tmp;
        if (notheard.find(tmp)!=notheard.end()) deutbo.insert(tmp);
    }

    cout<<deutbo.size()<<"\n";
    for(string d : deutbo){
        cout<<d<<"\n";
    }
    return 0;
}