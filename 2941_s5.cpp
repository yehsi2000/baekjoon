#include <cstdio>

char word[101];

int main(){
    scanf("%s",word);
    int len=0;
    int cnt=0;
    while(word[++len]!='\0');
    for(int i=len-1;i>=0;--i){
        if(i>0 && word[i]=='='){
            if(i>1 && word[i-1]=='z' && word[i-2]=='d') i-=2;
            else if(word[i-1]=='c' || word[i-1]=='s' || word[i-1]=='z') i--;
        }
        else if(i>0 && word[i]=='-' && (word[i-1]=='c' || word[i-1]=='d')) i--;
        else if(i>0 && word[i]=='j' && (word[i-1]=='n' || word[i-1]=='l')) i--;
        cnt++;
    }
    printf("%d",cnt);
}