#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct node{
  string val;
  map<string,node> connects;
};

void printmap(node* root, int depth){
  for(int i=0;i<depth; ++i) cout<<"--";
  cout<<root->val<<"\n";
  for(auto e: root->connects){
    printmap(&e.second,depth+1);
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  map<string, node>* roots;
  roots = new map<string,node>();
  int n, depth;
  string input;
  cin>>n;
  for(int i=0; i<n; ++i){
    cin>>depth;
    map<string,node>* selec = roots;
    for(int j=0; j<depth; ++j){
      cin>>input;
      if(selec->find(input) != selec->end()){
        selec = &((*selec)[input].connects);
      } else {
        selec->insert({input,node{input}});
        selec = &((*selec)[input].connects);
      }
    }
  }
  for(auto e: *roots){
    printmap(&e.second,0);
  }
  
}