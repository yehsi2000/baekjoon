#include <iostream>

using namespace std;

int main()
{
    string input;
    int wordcnt=0;

    getline(cin,input);
    if(input==" ") {
        cout<<0;
        return 0;
    }
    for(int i=0;i<input.length();++i){
        if(input[i]==' ' && (i!=0 && i!=input.length()-1)) wordcnt++;
    }
    
    cout<<wordcnt+1;
    

    return 0;
}