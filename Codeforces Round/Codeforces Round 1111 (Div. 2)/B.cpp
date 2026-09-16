#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " = " << x << "\n";
#define vdebug(a) cerr << #a << " = "; for(auto x : a) cerr << x << " "; cerr << "\n";
#define open(task) freopen(task".inp","r",stdin);freopen(task".out","w",stdout);
#define sz(x) ((int)x.size())
#define all(x) (x).begin(),(x).end()
#define hashmap unordered_map
#define hashset unordered_set
#define pb push_back
#define ff first
#define ss second
#define en "\n"

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int t;
        cin >> t;

        while(t--)
        {
                ll n,m,k;
                cin >> n >> k >> m;

                if(k > m)
                {
                        cout << "NO" << en;
                        continue;
                }
                else
                {
                        cout << "YES" << en;
                        vector<ll> prefix(n + 1);
                        for(int i = 0 ; i <= n ; i++) prefix[i] = i % k;
                        for(int i = 1 ; i <= n ; i++)
                        {
                                ll d = (prefix[i] - prefix[i - 1] + m) % m;
                                if(d == 0) d = m;
                                cout << d << " " ;
                        }
                        cout << en;
                }
        }

        return 0;
}

