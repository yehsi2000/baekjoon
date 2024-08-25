#include <cstdio>

int array[500][500];

int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;++i) for(int j=0;j<m; ++j) scanf("%d",&array[i][j]);
    int max = 0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            int sum;
            if(j+3<m) {sum = array[i][j]+array[i][j+1]+array[i][j+2]+array[i][j+3]; max = sum>max ? sum : max;} //가로네칸

            if(i+3<n) {sum = array[i][j]+array[i+1][j]+array[i+2][j]+array[i+3][j]; max = sum>max ? sum : max;} //세로네칸

            if(i+1<n && j+1<m) {sum = array[i][j]+array[i+1][j]+array[i][j+1]+array[i+1][j+1]; max = sum>max ? sum : max;} //2x2

            if(i+2<n && j+1<m) {
                sum = array[i][j]+array[i+1][j]+array[i+2][j]+array[i][j+1]; max = sum>max ? sum : max; //세로3 우상 한칸
                sum = array[i][j]+array[i+1][j]+array[i+2][j]+array[i+1][j+1]; max = sum>max ? sum : max; //세로3 우중 한칸
                sum = array[i][j]+array[i+1][j]+array[i+2][j]+array[i+2][j+1]; max = sum>max ? sum : max; //세로3 우하 한칸
                
                sum = array[i][j+1]+array[i+1][j+1]+array[i+2][j+1]+array[i][j]; max = sum>max ? sum : max; //세로3 좌상 한칸
                sum = array[i][j+1]+array[i+1][j+1]+array[i+2][j+1]+array[i+1][j]; max = sum>max ? sum : max; //세로3 좌중 한칸
                sum = array[i][j+1]+array[i+1][j+1]+array[i+2][j+1]+array[i+2][j]; max = sum>max ? sum : max; //세로3 좌하 한칸

                sum = array[i][j]+array[i+1][j]+array[i+1][j+1]+array[i+2][j+1]; max = sum>max ? sum : max; //2x2 오른쪽 한칸아래로 밀기
                sum = array[i][j+1]+array[i+1][j]+array[i+1][j+1]+array[i+2][j]; max = sum>max ? sum : max; //2x2 왼쪽 한칸아래로 밀기
            }

            if(i+1<n && j+2<m) {
                sum = array[i][j]+array[i][j+1]+array[i][j+2]+array[i+1][j]; max = sum>max ? sum : max; //가로3 하좌 한칸
                sum = array[i][j]+array[i][j+1]+array[i][j+2]+array[i+1][j+1]; max = sum>max ? sum : max; //가로3 하중 한칸
                sum = array[i][j]+array[i][j+1]+array[i][j+2]+array[i+1][j+2]; max = sum>max ? sum : max; //가로3 하우 한칸

                sum = array[i+1][j]+array[i+1][j+1]+array[i+1][j+2]+array[i][j]; max = sum>max ? sum : max; //가로3 상좌 한칸
                sum = array[i+1][j]+array[i+1][j+1]+array[i+1][j+2]+array[i][j+1]; max = sum>max ? sum : max; //가로3 상중 한칸
                sum = array[i+1][j]+array[i+1][j+1]+array[i+1][j+2]+array[i][j+2]; max = sum>max ? sum : max; //가로3 상우 한칸

                sum = array[i+1][j]+array[i+1][j+1]+array[i][j+1]+array[i][j+2]; max = sum>max ? sum : max; //2x2 위쪽 한칸우로 밀기
                sum = array[i][j]+array[i][j+1]+array[i+1][j+1]+array[i+1][j+2]; max = sum>max ? sum : max; //2x2 아래쪽 한칸우로 밀기
            } 
        }
    }
    printf("%d", max);
    
}