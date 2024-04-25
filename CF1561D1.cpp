#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int MAX = 4000006;
int ps[MAX + 1];
int dp[MAX + 1];
 
inline int add(ll n1, ll n2, ll m) {
    return (n1 + n2) % m;
}
 
inline int mul(ll n1, ll n2, ll m) {
    return (n1 * n2) % m;
}
 
int dfs(int n, int m) {
    if (dp[n] != -1) {
        return dp[n];
    }
 
    dp[n] = ps[n - 1];
    int sqrtN = sqrt(n);
    for (int i = 1; i <= sqrtN; ++i) {
        dp[n] = add(dp[n], mul(dfs(i, m), (n / i) - (n / (i + 1)), m), m);
    }
    for (int i = n / (sqrtN + 1); i > 1; --i) {
        dp[n] = add(dp[n], dfs(n / i, m), m);
    }
 
    return dp[n];
}
 
void solve() {
    memset(dp, -1, sizeof(dp));
    dp[1] = ps[1] = 1;
 
    int n, m;
    cin >> n >> m;
    for (int i = 2; i <= n; ++i) {
        ps[i] = add(dfs(i, m), ps[i - 1], m);
    }
 
    cout << dp[n] << '\n';
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
 
    solve();
 
    return 0;
}

