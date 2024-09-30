//https://www.acmicpc.net/source/60391378
#include <cstdio>
int main()
{
    char s1[1001], s2[1001];
    int str2_idx, lcs_idx, maxlen = 0, LCS[1001]{};
    scanf("%s", s1);
    scanf("%s", s2);
    for (int str1_idx = 0; s1[str1_idx] != '\0'; str1_idx++)
    {
        str2_idx = 0;
        lcs_idx = 1;
        while (lcs_idx <= maxlen)
        {
            if (str2_idx == LCS[lcs_idx])
            {
                lcs_idx++;
            }
            else if (s2[str2_idx] == s1[str1_idx])
            {
                //swap LCS[lcs_idx] and str2_idx
                LCS[lcs_idx] += str2_idx;
                str2_idx = LCS[lcs_idx] - str2_idx;
                LCS[lcs_idx] -= str2_idx;
                lcs_idx++;
            }
            str2_idx++;
        }
        while (s2[str2_idx] != '\0')
        {
            if (s2[str2_idx] == s1[str1_idx])
            {
                LCS[++maxlen] = str2_idx;
                break;
            }
            str2_idx++;
        }
    }
    printf("%d", maxlen);
    return 0;
}