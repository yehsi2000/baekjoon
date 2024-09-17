#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int num, q;
    vector<string> collection;
    collection.reserve(num);
    map<string, int> collectionmap;
    cin >> num >> q;
    for(int i=0; i<num; ++i){
        string s;
        cin >> s;
        collection.push_back(s);
        collectionmap.insert({collection[i],i+1});
    }
    for(int i=0; i<q; ++i){
        int n;
        string name;
        cin >> n;
        if(cin){
            cout<< collection[n-1]<<"\n";
        } else {
            cin.clear();
            cin >> name;
            cout << collectionmap[name] << "\n";
        }

    }
}