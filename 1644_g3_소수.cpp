#include <iostream>
using namespace std;

// 제출번호 7944056
// sunhong님 코드 참조

bool is_not_prime[4000001] = {0};
int primes[285000] = {0};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  for (int i = 3; i * i <= n; i += 2) {
    if (!is_not_prime[i])
      for (int j = i * i; j <= n; j += i * 2)  //  홀수의 짝수번째는 고려할 필요 없으므로, i*2씩 증가
        is_not_prime[j] = true;
  }

  int index = 0;
  primes[index++] = 2;
  for (int i = 3; i <= n; i += 2)
    if (!is_not_prime[i]) primes[index++] = i;

  int p, q;
  p = q = 0;
  int sum = 0;
  int count = 0;

  while (q <= index) {
    if (sum < n) {
      sum += primes[q++];
    } else {
      if (sum == n) count++;
      sum -= primes[p++];
    }
  }
  cout << count;
}