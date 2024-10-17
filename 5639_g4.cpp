#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
vector<int> preorder;

void pretopost(int l, int r) {
  if (l > r) return;
  int root = preorder[l];
  if(l==r){
    cout<<root<<'\n';
    return;
  }
  int idx = -1;
  for (int i = l + 1; i <= r; ++i){
    if(preorder[i] > root){
      idx=i;
      break;
    }
  }
  if (idx == -1) idx = r + 1;
  pretopost(l + 1, idx - 1);
  pretopost(idx, r);
  cout << root << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tmp;
  while (cin>>tmp) {
    if (!cin) break;
    preorder.push_back(tmp);
  }
  pretopost(0, preorder.size() - 1);
  return 0;
}