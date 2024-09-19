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
        int start=0, end=n-1;
        int rangeF, rangeB;
        while(start<=end){
            int mid = (start+end)/2;
            if(sang[mid] <= temp) start = mid+1;
            else end = mid-1;
        }
        rangeF = end;
        start = 0;
        end = n;
        while(start<=end){
            int mid = (start+end)/2;
            if(sang[mid] < temp) start = mid;
            else end = mid;
        }
        if(start==0 && sang[start]==temp) start--;
        rangeB = start;
        if(sang[rangeF]==temp){
            printf("%d ", rangeF-rangeB);
        }
        else printf("0 ");
    }

}