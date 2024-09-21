#include <cstdio>
#include <cstring>
char s[100001];
int main(){
    scanf("%s", s);
    int digits[10] = {0,};
    int digitsum = 0;
    int len = strlen(s);
    for(int i=0; i<len; ++i){
        digits[s[i]-'0']++;
        digitsum += s[i]-'0';
    }
    if(digits[0]==0 || digitsum%3) printf("-1");
    else {
        for(int i=9; i>=0; --i){
            while(digits[i]--) printf("%c",i+'0');
        }
    }
}