#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int,int>>list;

bool compare(const pair<int,int> &a, const pair<int,int> &b){//less가 기본 오름차순 < 작은게 앞쪽 >큰게앞쪽
    return a.second<b.second ? true : (a.second==b.second ? a.first<b.first : false); 

}

int main(){
    int n;
    scanf("%d",&n);
    list.reserve(n);
    while(n--){
        int start,end;
        scanf("%d %d",&start, &end);
        list.push_back(make_pair(start,end));
    }
    std::sort(list.begin(),list.end(),compare);
    int start = 0;
    int cnt=0;
    for(auto element : list){
        if(element.first>=start){ //이전 회의 시간이 끝난뒤로 가장빨리 끝나는 회의
            cnt++;
            start = element.second; //새로운 회의 끝나는 시간
        }
    }
    printf("%d",cnt);
    return 0;
}