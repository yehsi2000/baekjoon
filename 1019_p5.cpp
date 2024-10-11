#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

long long pow(long long a, int exp){
  long long ret = 1;
  for(int i=0; i<exp; ++i){
    ret*=a;
  }
  return ret;
}

int main() {
  int digit[9]={};
  int digitcnt[10]={};
  char str[10];
  scanf("%s", str);
  int innum = atoi(str);
  int size = strlen(str)-1;
  int dcnt=0;
  for(int i=0; i<=size; ++i){
    digit[size-i] = str[i]-'0';
  }
  
  for(int len=size; len>=0; --len){
    for(int topdigit = 0; topdigit<digit[len]; ++topdigit){
      for(int i=0; i<10; ++i){
        digitcnt[i] += pow(10,len-1)*len;
      }
      if(topdigit!=0) digitcnt[topdigit] += pow(10,len);
    }
    for(int i=len-1; i>=0; --i){
      digitcnt[digit[len]] += pow(10,i)*digit[i];
    }
    digitcnt[digit[len]]++;
  }
  for(int i=0; i<=size; ++i){
    if(digit[i]==0)	digitcnt[0]-=pow(10,i);
	}

  for(int i=0; i<10; ++i){
		printf("%d ",digitcnt[i]);
	}
}