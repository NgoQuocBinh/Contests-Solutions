#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define en "\n"

ll s,q;
vector<ll> prefix,divi;

ll calc(ll lim)
{
        if(lim <= 0) return 0;
        if(lim > s) return prefix.back();
        int pos = lower_bound(all(divi),lim) - divi.begin();
        ll l = (pos == 0 ? 0 : divi[pos - 1]);
        ll w = s / divi[pos];
        ll res = prefix[pos] + (lim - l) * w;
        return res;
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
                divi.clear();
                cin >> s >> q;

                for(ll i = 1 ; i * i <= s ; i++) 
                {
                        if(s % i == 0)
                        {
                                divi.pb(i);
                                if(i * i != s) divi.pb(s / i);
                        }
                }

                sort(all(divi));

                prefix.assign(sz(divi) + 1,0);
                for(int i = 0 ; i < sz(divi) ; i++)
                {
                        ll l = (i == 0 ? 0 : divi[i - 1]), r = divi[i];

                        ll len = r - l, w = s / divi[i];
                        prefix[i + 1] = prefix[i] + len * w;
                }

                while(q--)
                {
                        ll x,y;
                        cin >> x >> y;

                        ll ts = s / x;
                        int pos = upper_bound(all(divi),ts) - divi.begin();
                        ll ans = 0, good;
                        if(pos == 0)  good = 0;
                        else good = divi[pos - 1];

                        good = min(good,y);
                        ans += good * x;
                        ans += calc(y) - calc(good);

                        cout << ans << en;
                }
        }

        return 0;
}