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

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int t;
        cin >> t;

        while(t--)
        {
                ll n, c;
                cin >> n >> c;

                vector<ll> a(n), b;
                for(int i = 0 ; i < n ; i++) cin >> a[i];

                reverse(all(a));
                ll s = 0;
                for(ll x : a)
                {
                        s += x - c;
                        b.pb(c - x);
                }

                sort(all(b), greater<ll>());

                ll ans = s;
                for(int i = 0; i < n / 2; i++)
                {
                        if(b[i] > 0) ans += b[i];
                        else break;
                }

                cout << ans << en;
        }

        return 0;
}
