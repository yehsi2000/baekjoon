//부분수열의 합 실2
#include <cstdio>
using namespace std;

int N, a[20], ANS = 0;
void count(int n, int sum) {
	if (n < N - 1) {
		count(n + 1, sum);
		count(n + 1, sum - a[n]);
	}
	else {
		if (!sum) ANS++;
		if (sum == a[n]) ANS++;
	}
}
int main() {
	int S;

	scanf("%d%d", &N, &S);
	for (int i = 0; i < N; ++i) scanf("%d", &a[i]);
	count(0,S);
	printf("%d", (S) ? ANS : ANS - 1);

	return 0;
}