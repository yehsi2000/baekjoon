#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string input;
    cin>>input;
    stack<int> st;
    int cnt = 0;
    for(int i=0; i<input.length(); ++i){
        if(input[i]=='('){
            st.push(i);
        }
        if(input[i]==')'){
            int top = st.top();
            st.pop();
            if(i-top==1){
                cnt+=st.size();
            } else {
                cnt++;
            }
        }
    }
    cout << cnt;
}