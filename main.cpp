#include <cstdio>
#include <cstring>

#define MAX_N 24
#define INF 1000000000
#define min(A, B) ((A) < (B) ? (A) : (B))

int dp[MAX_N + 3][(1 << MAX_N) + 3];
int v[MAX_N + 3][MAX_N + 3];

int iter(int cur, unsigned mask, const int n) {
    if (dp[cur][mask] != -1) return dp[cur][mask];
    if (mask == (1 << n) - 1)
        return dp[cur][mask] = v[cur][0];
    int min_val = INF;
    for (int i = 0; i < n; i++) if (~mask & (1 << i))
        min_val = min(min_val, iter(i, mask | (1 << cur), n) + v[cur][i]);
    return dp[cur][mask] = min_val;
}

int main() {
    memset(dp, -1, sizeof dp);
    int n;
    scanf("%d ", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            scanf("%d ", &v[i][j]);
        }
    int ans = iter(0,1,n);
    printf("ans %d\n", ans);

    return 0;
}
