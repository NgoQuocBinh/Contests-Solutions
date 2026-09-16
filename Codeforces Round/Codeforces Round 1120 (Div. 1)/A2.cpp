#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define hashmap unordered_map
#define hashset unordered_set
#define pb push_back
#define ff first
#define ss second
#define en "\n"

const int mod = 1e9 + 7;
int n;
vector<int> a;

namespace subtask_full
{
        void solve()
        {
                vector<int> f(n, -1);
                for(int i = 1 ; i <= n ; i++)
                {
                        ll l = 1LL * a[i] * i;
                        ll r = min(1LL * n - 1, 1LL * (a[i] + 1) * i - 1);

                        if(l <= r) f[l] = max(f[l], (int)r);
                }

                vector<int> v;
                int mx = -1;
                for(int i = 0 ; i < n ; i++)
                {
                        mx = max(mx, f[i]);
                        if(mx < i) v.pb(i);
                }

                int m = sz(v);
                vector<int> req(m, -1);
                for(int k = 1 ; k <= n ; k++)
                {
                        for(int j = 0 ; j < a[k] ; j++)
                        {
                                int l = lower_bound(all(v), 1LL * j * k) - v.begin();
                                int r = upper_bound(all(v), min(1LL * n - 1, 1LL * (j + 1) * k - 1)) - v.begin() - 1;
                                if(l <= r) req[r] = max(req[r], l);
                        }
                }

                for(int i = 1 ; i < m ; i++) req[i] = max(req[i], req[i - 1]);

                vector<int> dp(m + 1), pre(m + 2);
                dp[0] = 1;
                pre[1] = 1;
                for(int i = 1 ; i <= m ; i++)
                {
                        int l = req[i - 1] + 1;
                        if(l <= i) dp[i] = (pre[i] - pre[l - 1] + mod) % mod;
                        pre[i + 1] = (pre[i] + dp[i]) % mod;
                }

                int l = m ? req[m - 1] + 1 : 0;
                ll ans = 0;
                for(int i = l ; i <= m ; i++) ans = (ans + dp[i]) % mod;

                cout << ans << en;
        }
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        #define task "sample"
        if (fopen(task ".inp", "r"))
        {
                freopen(task ".inp", "r", stdin);
                freopen(task ".out", "w", stdout);
        }

        int t;
        cin >> t;

        while(t--)
        {
                cin >> n;
                a.assign(n + 1, 0);
                for(int i = 1 ; i <= n ; i++) cin >> a[i];

                subtask_full::solve();
        }

        return 0;
}
