#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
    int n,m;
    scanf("%d", &n);
    vector<int> sang(n);
    for(int i=0; i<n; ++i){
        scanf("%d", &sang[i]);
    }
    sort(sang.begin(), sang.end());
    scanf("%d", &m);
    vector<int> isthere(m);
    for(int i=0; i<m; ++i){
        int temp;
        scanf("%d", &temp);
        int start=0, end=n;
        while(start+1<end){
            int mid = (start+end)/2;
            if(sang[mid] <= temp) start = mid;
            else end = mid;
        }
        if(sang[start]==temp) printf("1 ");
        else printf("0 ");
    }

}