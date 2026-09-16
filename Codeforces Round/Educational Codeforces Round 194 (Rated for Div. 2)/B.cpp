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

ll x, y, k;

namespace subtask_full
{
        void solve()
        {
                ll d = y - x;
                ll ans = 0;
                for(ll i = 0 ; i < min(k, max(0LL, d - x + 1)) ; i++)
                {
                        ans += d % (x + i);
                }

                ans += (k - min(k, max(0LL, d - x + 1))) * d;

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
                cin >> x >> y >> k;

                subtask_full::solve();
        }

        return 0;
}