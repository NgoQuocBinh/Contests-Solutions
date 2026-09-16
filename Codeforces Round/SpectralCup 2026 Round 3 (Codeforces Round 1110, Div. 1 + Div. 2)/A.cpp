#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " = " << x << "\n";
#define vdebug(a) cerr << #a << " = "; for(auto x : a) cerr << x << " "; cerr << "\n";
#define open(task) freopen(task".inp","r",stdin);freopen(task".out","w",stdout);
#define sz(x) ((int)x.size())
#define all(x) (x).begin(),(x).end()
#define hashmap unordered_map
#define hashset unordered_set
#define pb push_back
#define ff first
#define ss second
#define en "\n"

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 1e9;

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int t;
        cin >> t;

        while (t--)
        {
                int n, k;
                cin >> n >> k;
                string s;
                cin >> s;

                int ans = INF;
                for (int totR = 0; totR <= n; totR++)
                {
                    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
                    dp[0][0] = 0;

                    for (int pos = 0; pos < n; pos++)
                    {
                        int i = pos + 1;

                        for (int r = 0; r <= totR; r++)
                        {
                            if (dp[pos][r] == INF) continue;

                            if (r >= k)
                            {
                                int cost = dp[pos][r] + (s[pos] == 'R');
                                dp[pos + 1][r] = min(dp[pos + 1][r], cost);
                            }

                            if (r < totR)
                            {
                                if (totR <= (n - i) + r + 1 - k)
                                {
                                    int cost = dp[pos][r] + (s[pos] == 'L');
                                    dp[pos + 1][r + 1] = min(dp[pos + 1][r + 1], cost);
                                }
                            }
                        }
                    }

                    ans = min(ans, dp[n][totR]);
                }

                if (ans == INF) cout << -1 << en;
                else cout << ans << en;
            }

        return 0;
}
