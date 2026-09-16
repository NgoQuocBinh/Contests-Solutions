#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(x) cout << #x << " = ";for(auto idx : x) cout << idx << " "; cout << "\n";
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define hashmap unordered_map
#define hashset unordered_set
#define pb push_back
#define ff first
#define ss second
#define en "\n"

const long long mod = 998244353;

long long calc(int p, int n, vector<int> &a)
{
        vector<int> vis(n + 1), cnt(n + 1);
        int last = -1;
        for(int i = 1; i < p; i++)
        {
                int x = a[i - 1];
                if(x != last)
                {
                        vis[x] |= 1;
                        last = x;
                }
                else cnt[x]++;
        }
        last = -1;
        for(int i = n - 1; i >= p; i--)
        {
                int x = a[i - 1];
                if(x != last)
                {
                        vis[x] |= 2;
                        last = x;
                }
                else cnt[x]++;
        }

        for(int i = 1; i <= n; i++)
        {
                if(vis[i] == 3) return 0;
        }
        long long ans = 1;
        int pool = 0;
        for(int i = n - 1; i >= 1; i--)
        {
                if(vis[i]) pool += cnt[i];
                else
                {
                        ans = ans * pool % mod;
                        pool--;
                        if(pool < 0) return 0;
                }
        }

        return ans;
}

void solve()
{
        int n;
        cin >> n;
        vector<int> a(n - 1);
        int mx = 0;
        for(int i = 0; i < n - 1; i++)
        {
                cin >> a[i];
                mx = max(mx, a[i]);
        }

        if(mx != n - 1)
        {
                cout << 0 << en;
                return;
        }

        int l = -1, r = -1;
        for(int i = 0; i < n - 1; i++)
        {
                if(a[i] == n - 1)
                {
                        if(l == -1) l = i + 1;
                        r = i + 1;
                }
        }

        for(int i = 0; i < l - 1; i++)
        {
                if(a[i] > a[i + 1])
                {
                        cout << 0 << en;
                        return;
                }
        }
        for(int i = r - 1; i < n - 2; i++)
        {
                if(a[i] < a[i + 1])
                {
                        cout << 0 << en;
                        return;
                }
        }

        long long ans = calc(l, n, a);
        if(l != r + 1) ans = (ans + calc(r + 1, n, a)) % mod;

        cout << ans << en;
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        #define task "sample"
        if(fopen(task".inp","r"))
        {
                freopen(task".inp","r",stdin);
                freopen(task".out","w",stdout);
        }

        int _;
        cin >> _;
        while(_--) solve();

        return 0;
}