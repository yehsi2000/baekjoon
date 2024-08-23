#include <cstdio>

int main()
{   
    int n, wordcnt=0;
    char str[101];
    scanf("%d",&n);

    for(int i=0;i<n;++i){
        scanf("%s", str);
        char lastchar;
        bool flag=true;
        bool charset[27]={0,};
        for(int i=0; str[i]!='\0'; ++i){
            if(charset[str[i]-'a'] && lastchar != str[i]){
                flag=false;
                break;
            }
            lastchar=str[i];
            charset[str[i]-'a']=true;
        }
        if(flag) wordcnt++;
    }
    printf("%d",wordcnt);
    return 0;
}