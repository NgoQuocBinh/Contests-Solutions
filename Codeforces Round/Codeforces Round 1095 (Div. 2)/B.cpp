/* Minh Chau <3 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 200005;

ll n, p[N];
ll st_min[4*N], st_max[4*N];

void build(ll id, ll l, ll r){
    if(l == r){
        st_min[id] = st_max[id] = p[l];
        return;
    }
    ll m = (l + r) >> 1;
    build(id<<1, l, m);
    build(id<<1|1, m+1, r);
    st_min[id] = min(st_min[id<<1], st_min[id<<1|1]);
    st_max[id] = max(st_max[id<<1], st_max[id<<1|1]);
}

ll get_min(ll id, ll l, ll r, ll u, ll v){
    if(v < l || r < u) return 1e9;
    if(u <= l && r <= v) return st_min[id];
    ll m = (l + r) >> 1;
    return min(get_min(id<<1,l,m,u,v), get_min(id<<1|1,m+1,r,u,v));
}

ll get_max(ll id, ll l, ll r, ll u, ll v){
    if(v < l || r < u) return 0;
    if(u <= l && r <= v) return st_max[id];
    ll m = (l + r) >> 1;
    return max(get_max(id<<1,l,m,u,v), get_max(id<<1|1,m+1,r,u,v));
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    while(t--){
        cin >> n;
        for(ll i = 1; i <= n; i++) cin >> p[i];

        build(1,1,n);

        ll ans = 0;
        vector<pair<ll,ll>> cur;

        for(ll r = 1; r <= n; r++){
            vector<pair<ll,ll>> nxt;
            nxt.push_back({p[r], r});

            for(auto [g, l] : cur){
                ll ng = __gcd(g, p[r]);
                if(nxt.back().first == ng){
                    nxt.back().second = min(nxt.back().second, l);
                } else {
                    nxt.push_back({ng, l});
                }
            }

            cur = nxt;

            for(auto [g, l] : cur){
                ll L = l, R = r, res = -1;
                while(L <= R){
                    ll mid = (L + R) >> 1;
                    ll mn = get_min(1,1,n,mid,r);
                    ll mx = get_max(1,1,n,mid,r);
                    if(mx - mn <= g){
                        if(mx - mn == g) res = mid;
                        R = mid - 1;
                    } else L = mid + 1;
                }
                if(res != -1) ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}