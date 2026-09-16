/*
       shool : Thi Tran secondary school
       participant : Ngo Quoc Binh
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define lli long long int
#define ulli unsigned long long int
#define ld long double

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x : a) cout << x << " "; cout << "\n";
#define IShowSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define hashmap unordered_map
#define hashset unordered_set
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) ((int)((x).size()))

#define pb push_back
#define en '\n'
#define fi first
#define se second
#define task "wtf"

const int maxn = 200005;
const int lg = 20;

vector<int> adj[maxn];
vector<int> dep[maxn];
int up[maxn][lg];
int h[maxn];
int mx;

void dfs(int u, int p, int d){
    h[u] = d;
    mx = max(mx, d);
    dep[d].pb(u);
    up[u][0] = p;
    for(int i = 1; i < lg; i++){
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    for(int v : adj[u]){
        if(v != p){
            dfs(v, u, d + 1);
        }
    }
}

int lca(int u, int v){
    if(h[u] < h[v]) swap(u, v);
    for(int i = lg - 1; i >= 0; i--){
        if(h[u] - (1 << i) >= h[v]){
            u = up[u][i];
        }
    }

    if(u == v) return u;
    for(int i = lg - 1; i >= 0; i--){
        if(up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }

    return up[u][0];
}

void solve(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        adj[i].clear();
        dep[i - 1].clear();
    }

    mx = 0;
    for(int i = 2; i <= n; i++){
        int p;
        cin >> p;
        adj[p].pb(i);
        adj[i].pb(p);
    }

    dfs(1, 1, 0);
    ll ans = 0;
    for(int d = 0; d <= mx; d++){
        auto &v = dep[d];
        int m = sz(v);
        ans += m;
        if(m > 1){
            vector<int> x;
            for(int i = 0; i < m - 1; i++){
                x.pb(lca(v[i], v[i + 1]));
            }
            sort(all(x));
            x.erase(unique(all(x)), x.end());
            ans += sz(x);
        }
    }

    cout << ans << en;
}

int main(){
    IShowSpeed

    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    int Test_Cases = 1;
    cin >> Test_Cases;
    for(int i = 1 ; i <= Test_Cases ; i++){
        solve();
    }

    return 0;
}