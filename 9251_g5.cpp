#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s1[1001], s2[1001];
int lcs[2][1001] = {0,};

int main(){
    scanf("%s", s1);
    scanf("%s", s2);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for(int i=1;i<=len1;++i){
        for(int j=1;j<=len2; ++j){
            if(s1[i-1]==s2[j-1]) //비교하는 문자가 같으면
                lcs[i%2][j] = lcs[(i+1)%2][j-1] + 1; //양쪽문자열 끝에서 하나씩 뺀것의 LCS에서 하나더하면됨
            else //비교하는 문자가 다르면
                lcs[i%2][j] = max(lcs[(i+1)%2][j],lcs[i%2][j-1]); //A에서 하나뺀거랑 B 비교, B에서하나뺀거랑 A비교해서 많이겹치는거
        }
    }
    printf("%d", lcs[len1%2][len2]);
}