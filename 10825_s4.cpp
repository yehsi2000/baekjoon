#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Score{
    string name;
    int korean;
    int english;
    int math;
    bool operator<(Score a){
        if(korean > a.korean){
            return true;
        } else if(korean == a.korean){
            if(english < a.english){
                return true;
            } else if(english == a.english){
                if(math > a.math) {
                    return true;
                } else if(math==a.math) {
                    return name < a.name;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<Score> scores;
    while(n--){
        string tmpstr;
        int tmpkor, tmpeng, tmpmath;
        cin >> tmpstr>> tmpkor >> tmpeng >> tmpmath;
        scores.push_back({tmpstr,tmpkor,tmpeng,tmpmath});
    }
    sort(scores.begin(),scores.end());
    for(int i=0; i<scores.size();++i){
        cout<<scores[i].name<<"\n";
    }
}