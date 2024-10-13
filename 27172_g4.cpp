//에라스토테네스의 체, 배수 약수 검사
#include <bits/stdc++.h>

using namespace std;

int score[1000001];
bool appeared[1000001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> nums(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
    appeared[nums[i]] = true;
  }
  for (int i = 0; i < n; i++) {
    // 배수들에 대해서 검사
    for (int i = nums[i] * 2; i <= 1000000; i += nums[i]) {
      if (appeared[i]) {
        score[i]--;
        score[nums[i]]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << score[nums[i]] << " ";
  }
  return 0;
}