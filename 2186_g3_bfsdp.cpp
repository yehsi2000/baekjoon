#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <numeric>
 
using namespace std;
int N, M, K;
const int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

bool isValid(int r, int c){
    return 0 <= r && r < N && 0 <= c && c < M;
}

void solve() {
    
}

int main(int argc, char** argv) {
    // BFS, DP
    cin>>N>>M>>K;
    vector<vector<char>> table(N, vector<char>(M));
    for (int r = 0; r < N; ++r) {
        string temp;
        cin>>temp;
        for (int c = 0; c < M; ++c) table[r][c] = temp[c];
    }
    string target;
    cin >> target;
    vector<vector<int>> dp(N, vector<int>(M, 0)), 
                        buf(N, vector<int>(M, 0));
    queue<pair<int,int>> q;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            if (table[r][c] == target.back()) {
                dp[r][c] = 1;
                q.push({r, c});
            }
        }
    }
    
    while (!q.empty()) {
        target.pop_back();
        if (target.empty())
            break;

        int sz = q.size();
        bool onQ[100][100] = {false};
        while (sz--) {
            int r = q.front().first, c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                for (int j = 1; j <= K; ++j) {
                    int nr = r + dr[i] * j, nc = c + dc[i] * j;
                    if (!isValid(nr, nc) || table[nr][nc] != target.back())
                        continue;
                    buf[nr][nc] += dp[r][c];
                    if (!onQ[nr][nc]) {
                        q.push({nr, nc});
                        onQ[nr][nc] = true;
                    }
                }
            }
            dp[r][c] = 0;
        }
        swap(dp, buf);
    }

    int sum = 0;
    for (int r = 0; r < N; ++r)
        sum = accumulate(dp[r].begin(), dp[r].end(), sum);
    printf("%d", sum);
    return 0;
}