#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x : a) cout << x << " "; cout << "\n";
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define en "\n"

int n;
vector<vector<int>> adj;

int bfs(int st, vector<int> &dist, vector<int> &par)
{
    dist.assign(n + 1, -1);
    par.assign(n + 1, -1);

    queue<int> q;
    q.push(st);
    dist[st] = 0;
    int res = st;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v : adj[u])
        {
            if(dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                par[v] = u;
                q.push(v);
                if(dist[v] > dist[res]) res = v;
            }
        }
    }

    return res;
}

int dfs(int u, int p, int dep, int c, vector<int> &S)
{
    int mx = dep;
    int cnt = 0;
    for(int v : adj[u])
    {
        if(v == p) continue;
        int cur = dfs(v, u, dep + 1, c, S);
        if(cur >= c) cnt++;
        mx = max(mx, cur);
    }
    if(cnt >= 2) S.pb(dep);

    return mx;
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

    while(_--)
    {
        cin >> n;
        adj.assign(n + 1, {});
        for(int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        if(n == 2)
        {
            cout << 1 << " " << 1 << en;
            continue;
        }

        vector<int> distA, parA;
        int A = bfs(1, distA, parA);
        vector<int> distB, parB;
        int B = bfs(A, distB, parB);
        int D = distB[B];
        int c = (D - 1) / 2;
        vector<int> path;
        int cur = B;
        while(cur != -1)
        {
            path.pb(cur);
            cur = parB[cur];
        }

        int u = path[c];
        int v = path[c + 1];
        vector<int> su, sv;
        dfs(u, v, 0, c, su);
        dfs(v, u, 0, c, sv);
        su.pb(c);
        sv.pb(c);
        sort(all(su));
        su.erase(unique(all(su)), su.end());
        sort(all(sv));
        sv.erase(unique(all(sv)), sv.end());
        vector<int> ans;
        for(int x : su)
        {
            for(int y : sv)
            {
                ans.pb(x + y + 1);
            }
        }

        sort(all(ans));
        ans.erase(unique(all(ans)), ans.end());
        cout << sz(ans);
        for(int i = 0 ; i < sz(ans) ; i++) cout << " " << ans[i];

        cout << en;
    }

    return 0;
}