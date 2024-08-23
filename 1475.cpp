#include <stdio.h>
int s[10], n, min;

int main() {
    scanf("%d", &n);
    while(n) {
        s[n%10]++;
        n /= 10;
    }
    s[6] = (s[6]+s[9]+1)/2;
    for (n = 0; n < 9; n++)
        if (min < s[n]) min = s[n];
    printf("%d", min);
}