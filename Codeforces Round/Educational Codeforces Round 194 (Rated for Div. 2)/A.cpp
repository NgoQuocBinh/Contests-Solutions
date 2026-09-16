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
vector<int> a;

namespace subtask_full
{
        void solve()
        {
                int cnt = 0;
                for(int i = 0 ; i < n ; i++) 
                {
                        if(a[i] == 0) cnt++;
                }

                if(cnt < 2) cout << -1 << en;
                else cout << a[0] + a[n - 1] << en;
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
                cin >> n;
                a.assign(n + 1, 0);
                for(int i = 0 ; i < n ; i++) cin >> a[i];

                subtask_full::solve();
        }

        return 0;
}