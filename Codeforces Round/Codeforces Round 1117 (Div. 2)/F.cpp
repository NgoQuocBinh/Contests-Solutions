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

const ll inf = 2e18;

int n, q, x;
int d[1000005], s[1000005];
ll tr[1000005][5][5];

void clr(ll a[5][5])
{
        for(int i = 0 ; i < x ; i++)
        {
                for(int j = 0 ; j < x ; j++)
                {
                        a[i][j] = inf;
                }
        }
}

void la(int id, ll a[5][5])
{
        clr(a);
        int len = d[id];
        ll cost = s[id];
        for(int u = 1 ; u <= x ; u++)
        {
                if(u > len)
                {
                        int v = u - len;

                        if(v >= 1 && v <= x)
                        {
                                a[u - 1][v - 1] = 0;
                        }
                }
                else
                {
                        for(int v = 1 ; v <= x ; v++)
                        {
                                ll tri = (len - u + v - 1) / x;
                                a[u - 1][v - 1] = tri * cost;
                        }
                }
        }
}

void merge(ll a[5][5], ll b[5][5], ll c[5][5])
{
        clr(c);
        for(int i = 0 ; i < x ; i++)
        {
                for(int k = 0 ; k < x ; k++)
                {
                        if(a[i][k] == inf)
                        {
                                continue;
                        }
                        for(int j = 0 ; j < x ; j++)
                        {
                                if(b[k][j] == inf)
                                {
                                        continue;
                                }

                                c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
                        }
                }
        }
}

void build()
{
        for(int i = n - 1 ; i > 0 ; i--)
        {
                ll a[5][5], b[5][5];
                int l = i * 2;
                int r = i * 2 + 1;
                if(l >= n)
                {
                        la(l - n, a);
                }
                else
                {
                        memcpy(a, tr[l], sizeof(a));
                }

                if(r >= n)
                {
                        la(r - n, b);
                }
                else
                {
                        memcpy(b, tr[r], sizeof(b));
                }
                merge(a, b, tr[i]);
        }
}

void upd(int id)
{
        int p = id + n;
        p >>= 1;
        while(p > 0)
        {
                ll a[5][5], b[5][5];
                int l = p * 2;
                int r = p * 2 + 1;
                if(l >= n)
                {
                        la(l - n, a);
                }
                else
                {
                        memcpy(a, tr[l], sizeof(a));
                }

                if(r >= n)
                {
                        la(r - n, b);
                }
                else
                {
                        memcpy(b, tr[r], sizeof(b));
                }

                merge(a, b, tr[p]);
                p >>= 1;
        }
}

void get(int l, int r, ll ans[5][5])
{
        l += n;
        r += n;
        ll le[5][5], ri[5][5];
        bool hasl = false;
        bool hasr = false;
        while(l <= r)
        {
                if(l & 1)
                {
                        ll cur[5][5];

                        if(l >= n)
                        {
                                la(l - n, cur);
                        }
                        else
                        {
                                memcpy(cur, tr[l], sizeof(cur));
                        }

                        if(!hasl)
                        {
                                memcpy(le, cur, sizeof(le));
                                hasl = true;
                        }
                        else
                        {
                                ll tmp[5][5];

                                merge(le, cur, tmp);
                                memcpy(le, tmp, sizeof(le));
                        }

                        l++;
                }

                if(!(r & 1))
                {
                        ll cur[5][5];

                        if(r >= n)
                        {
                                la(r - n, cur);
                        }
                        else
                        {
                                memcpy(cur, tr[r], sizeof(cur));
                        }

                        if(!hasr)
                        {
                                memcpy(ri, cur, sizeof(ri));
                                hasr = true;
                        }
                        else
                        {
                                ll tmp[5][5];

                                merge(cur, ri, tmp);
                                memcpy(ri, tmp, sizeof(ri));
                        }

                        r--;
                }
                l >>= 1;
                r >>= 1;
        }

        if(hasl && hasr)
        {
                merge(le, ri, ans);
        }
        else if(hasl)
        {
                memcpy(ans, le, sizeof(le));
        }
        else
        {
                memcpy(ans, ri, sizeof(ri));
        }
}

ll cost(int id, int pos)
{
        if(pos > d[id])
        {
                return inf;
        }
        int rem = d[id] - pos;
        ll tri = 0;
        if(rem > 0)
        {
                tri = (rem + x - 1) / x;
        }
        return tri * s[id];
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        #define task "sample"

        if(fopen(task ".inp", "r"))
        {
                freopen(task ".inp", "r", stdin);
                freopen(task ".out", "w", stdout);
        }

        cin >> n >> q >> x;
        for(int i = 0 ; i < n ; i++) cin >> d[i];
        for(int i = 0 ; i < n ; i++) cin >> s[i];

        build();
        while(q--)
        {
                char type;
                cin >> type;
                if(type == '1')
                {
                        int id, v;
                        cin >> id >> v;
                        id--;
                        d[id] = v;
                        upd(id);
                }
                else if(type == '2')
                {
                        int id, v;
                        cin >> id >> v;
                        id--;
                        s[id] = v;
                        upd(id);
                }
                else if(type == '?')
                {
                        int l, r;
                        cin >> l >> r;
                        l--;r--;
                        if(l == r)
                        {
                                cout << cost(l, 1) << en;
                                continue;
                        }
                        ll a[5][5];
                        get(l, r - 1, a);
                        ll ans = inf;
                        for(int pos = 1 ; pos <= x ; pos++)
                        {
                                if(a[0][pos - 1] == inf)
                                {
                                        continue;
                                }
                                ll last = cost(r, pos);
                                if(last == inf)
                                {
                                        continue;
                                }
                                ans = min(ans, a[0][pos - 1] + last);
                        }

                        cout << ans << en;
                }
        }

        return 0;
}
