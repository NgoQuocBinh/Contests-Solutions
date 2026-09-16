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

const int maxn = 505;
int adj[maxn][maxn];
bool visited[maxn][maxn];
int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
int n;

bool bfs(int limit)
{
        memset(visited,false,sizeof(visited));
        queue<pair<int,int>> q;
        q.push({1,1});
        visited[1][1] = true;

        while(!q.empty())
        {
                auto [x,y] = q.front();
                q.pop();

                if(x == n && y == n) return true;
                for(int k = 0 ; k < 4 ; k++)
                {
                        int nx = x + dx[k], ny = y + dy[k];
                        if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
                        if(visited[nx][ny]) continue;
                        if(abs(adj[x][y] - adj[nx][ny]) > limit) continue;

                        visited[nx][ny] = true;
                        q.push({nx,ny});
                }
        }
        return false;
}

namespace subtask_full
{
        void solve()
        {
                int ans = 0;
                int l = 0, r = 1e6;
                while(l <= r){
                        int mid = (l + r) >> 1;
                        if(bfs(mid))
                        {
                                ans = mid;
                                r = mid - 1;
                        }
                        else l = mid + 1;
                }

                cout << ans;
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

        cin >> n;
        for(int i = 1 ; i <= n ; i++)
        {
                for(int j = 1 ; j <= n ; j++)
                {
                        cin >> adj[i][j];
                }
        }

        subtask_full::solve();

        return 0;
}
