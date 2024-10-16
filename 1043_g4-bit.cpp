#include <cstdio>
int main() {
  long long party[55] = {}, truth = 0, N, M, K, a;
  scanf("%lld%lld%lld", &N, &M, &K);
  for (int i = 0; i < K; i++) scanf("%lld", &a), truth |= (1LL << a);
  for (int i = 0; i < M; i++) {
    scanf("%lld", &N);
    for (int j = 0; j < N; j++) scanf("%lld", &a), party[i] |= (1LL << a);
  }
  a = 0;
  for (int q = 0; q < M; q++) //그냥 한번돌릴때마다 한번 갱신된다 생각하고 m^2번 돌리기
    for (int i = 0; i < M; i++)
      if (truth & party[i]) truth |= party[i];
  for (int i = 0; i < M; i++) a += !(party[i] & truth);
  printf("%lld", a);
  return 0;
}