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
                int n,m;
                cin >> n >> m;
                vector<ll> a(n),b(m);
                for(int i = 0 ; i < n ; i++) cin >> a[i];
                for(int i = 0 ; i < m ; i++) cin >> b[i];
                
                if(1LL * a[0] + n - 1 >= 1LL * b[0] + m - 1) cout << 1 << en;
                else cout << 2 << en;
        }

        return 0;
}