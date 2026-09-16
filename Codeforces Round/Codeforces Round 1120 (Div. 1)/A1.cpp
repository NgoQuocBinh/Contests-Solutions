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

int n;
vector<int> a;

namespace subtask_full
{
        void solve()
        {
                vector<int> diff(n + 1, 0);
                for(int i = 1 ; i <= n ; i++)
                {
                        ll x = a[i];
                        ll l = x * i;
                        ll r = (x + 1) * i - 1;

                        if(l >= n) continue;

                        r = min(r, (ll)n - 1);

                        diff[l]++;
                        if(r + 1 < n) diff[r + 1]--;
                }

                vector<int> ans;
                int bl = 0;
                for(int i = 0 ; i < n ; i++)
                {
                        bl += diff[i];

                        if(bl == 0) ans.pb(i);
                }

                cout << sz(ans) << en;
                for(int i = 0 ; i < sz(ans) ; i++) cout << ans[i] << " ";
                cout << en;
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
