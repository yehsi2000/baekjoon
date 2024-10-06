#include <algorithm>
#include <bitset>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bitset<100001> visited;

void TermProject() {
  int n;
  cin >> n;
  vector<int> points(n + 1);
  int in_team_cnt = 0;
  visited.reset();
  for (int i = 1; i <= n; ++i) {
    int tmp;
    cin >> tmp;
    if (i == tmp) {
      visited[i] = true;
      in_team_cnt++;
    }
    else
      points[i] = tmp;
  }
  
  for (int i = 1; i <= n; ++i) {
    if (visited[i])
      continue;
    stack<int> st;
    vector<bool> traced(n + 1, false);
    st.push(i);
    int loop_begin = 0;
    bool done = false;
    while (!st.empty() && !done) {
      int top = st.top();
      if (loop_begin) {
        st.pop();
        if (loop_begin == top)
          done = true;
        else
          in_team_cnt++;
      } else if (traced[top]) {
        loop_begin = top;
        in_team_cnt++;
        st.pop();
      } else {
        if(visited[top]) break;
        visited[top] = true;
        traced[top] = true;
        st.push(points[top]);
      }
    }
  }
  cout<<n-in_team_cnt<<"\n";

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    TermProject();
  }
}