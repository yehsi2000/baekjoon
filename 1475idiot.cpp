#include <cstdio>
#include <cstring>

char str[8];
int len, cnt=1;

int main (){
    while(true){
        char c = getchar();
        if(c<=' ') break;
        str[len] = c;
        len++;
    }
    str[len]='\0';
    int havecnt=0;
    for(int i=0; i<len; i++){ //should be enough for all number
        bool check[10]= {false};
        for(int i=0;i<10;i++){
            if(check[i]) continue;
            char* loc;
            if(!(loc = strchr(str,i+'0'))) {
                if(i==6 && (loc = strchr(str,'9'))) check[6] = true;
                else if(i==9 && (loc = strchr(str,'6'))) check[9] = true;
                else continue;
            }
            else check[i] = true;
            *loc = 127;
            havecnt++;
        }
        if(havecnt == len){
            printf("%d", cnt);
            break;
        } else cnt++;
    }
}