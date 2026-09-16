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
                int n;
                cin >> n;
                ll sum = 0;
                for(int i = 0 ; i < n ; i++)
                {
                        int x;
                        cin >> x;

                        sum += 1LL * x;
                }

                if(n % 2 == 1) cout << "NO" << en;
                else
                {
                        cout << (sum % 4 == 0 ? "YES" : "NO") << en;
                }
        }

        return 0;
}

