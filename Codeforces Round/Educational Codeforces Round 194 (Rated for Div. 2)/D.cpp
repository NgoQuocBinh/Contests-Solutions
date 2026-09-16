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
string s;

namespace subtask_full
{
        bool check(ll lim)
        {
                ll l = 0, r = 0;
                for(int i = 0 ; i < n ; i++)
                {
                        if(l == r)
                        {
                                ll x = l;
                                if(s[i] == '+')
                                {
                                        l = x + 1;
                                        r = x + lim;
                                        l = max(l, 1LL);
                                        if(l > r) return false;
                                }
                                else if(s[i] == '-')
                                {
                                        l = x - lim;
                                        r = x - 1;
                                        r = min(r, -1LL);
                                        if(l > r) return false;
                                }
                                else
                                {
                                        return false;
                                }
                        }
                        else
                        {
                                l -= lim;
                                r += lim;
                                if(s[i] == '+')
                                {
                                        if(r <= 0) return false;
                                        l = max(l, 1LL);
                                }
                                else if(s[i] == '-')
                                {
                                        if(l >= 0) return false;
                                        r = min(r, -1LL);
                                }
                                else
                                {
                                        if(l > 0 || r < 0) return false;
                                        l = 0;
                                        r = 0;
                                }
                        }

                        if(lim == 1)
                        {
                                ll check = (i + 1) % 2;
                                if(((l % 2) + 2) % 2 != check) l++;
                                if(((r % 2) + 2) % 2 != check) r--;
                                if(l > r) return false;
                        }
                }

                return true;
        }


        void solve()
        {
                // bool ok = true;
                // for(int i = 0 ; i < sz(s) - 1 ; i++)
                // {
                //         if(s[i] == '0' && s[i + 1] == '0')
                //         {
                //                 ok = false;
                //                 break;
                //         }
                // }

                // if(!ok || s[0] == '0')
                // {
                //         cout << -1 << en;
                //         return ;
                // }

                // // char res = '#';
                // // for(int i = 0 ; i < sz(s) ; i++)
                // // {
                // //         if(s[i] == '0') continue;
                // //         if(res == '#') res = s[i];
                // //         else if(res != s[i])
                // //         {
                // //                 ok = false;
                // //                 break;
                // //         }
                // // }

                // // cout << (ok ? 1 : 2) << en;

                // if(check(1)) cout << 1 << en;
                // else if(check(2)) cout << 2 << en;
                // else cout << 3 << en;

                ll l = 1;
                ll r = 1'000'000'000LL;
                ll ans = -1;
                while(l <= r)
                {
                        ll mid = (l + r) >> 1;
                        if(check(mid))
                        {
                                ans = mid;
                                r = mid - 1;
                        }
                        else l = mid + 1;
                }

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
                cin >> n >> s;

                subtask_full::solve();
        }

        return 0;
}