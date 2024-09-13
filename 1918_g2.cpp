#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

stack<char> st;

int main(){
    char midexpr[101];
    scanf("%s",midexpr);
    for(int i=0; i<strlen(midexpr); ++i){
        if(midexpr[i]>='A' && midexpr[i]<='Z'){
            printf("%c", midexpr[i]);
        } else if(midexpr[i] == '*' || midexpr[i]=='/'){
            if(st.empty()){
                st.push(midexpr[i]);
                continue;
            } else {
                while(!st.empty() && st.top() != '+' && st.top() != '-' && st.top() != '(') {
                    printf("%c", st.top());
                    st.pop();
                }
                if(!st.empty() && (st.top() == '*' || st.top() == '/')){
                    printf("%c", st.top());
                    st.pop();
                }
                st.push(midexpr[i]);
            }
        } else if(midexpr[i] == '+' || midexpr[i] =='-'){
            if(st.empty()){
                st.push(midexpr[i]);
            } else {
                while(!st.empty() && st.top() != '+' && st.top() != '-' && st.top() != '('){
                    printf("%c", st.top());
                    st.pop();
                }
                if(!st.empty() && (st.top() == '+' || st.top() == '-')){
                    printf("%c", st.top());
                    st.pop();
                }
                st.push(midexpr[i]);
            }
        } else if(midexpr[i] == '('){
            st.push(midexpr[i]);
        } else if(midexpr[i] == ')'){
            while(st.top()!='('){
                printf("%c", st.top());
                st.pop();
            }
            st.pop();
        }
    }

    while(!st.empty()){
        if(st.top() != '(') printf("%c", st.top());
        st.pop();
    }
}