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

ll n, p, a, b, r;

namespace subtask_full
{
        void solve()
        {
                queue<ll> q;
                vector<ll> dist(p, -1);
                ll nxt[3] = {(n + a) % p, (n + b) % p, (n + a + b) % p};
                for(ll x : nxt)
                {
                        if(dist[x] == -1)
                        {
                                dist[x] = 1;
                                q.push(x);
                        }
                }

                if(dist[r] != -1)
                {
                        cout << dist[r];
                        return;
                }

                while(!q.empty())
                {
                        ll cur = q.front();
                        q.pop();

                        ll nxt[3] = {(cur + a) % p, (cur + b) % p, (cur + a + b) % p};
                        for(ll x : nxt)
                        {
                                if(dist[x] != -1) continue;

                                dist[x] = dist[cur] + 1;

                                if(x == r)
                                {
                                        cout << dist[x];
                                        return;
                                }

                                q.push(x);
                        }
                }

                cout << -1;
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

        cin >> n >> p >> a >> b >> r;

        subtask_full::solve();

        return 0;
}
