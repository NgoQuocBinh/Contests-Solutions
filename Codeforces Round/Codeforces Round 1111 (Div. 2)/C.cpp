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
                vector<int> a(n),b(n);
                for(int i = 0 ; i < n ; i++) cin >> a[i];
                for(int i = 0 ; i < n ; i++) cin >> b[i];

                int cnt1 = 0;
                for(int i = 0 ; i < n ; i++)
                {
                        if(a[i] == 1) cnt1++;
                }

                int x = 0,y = 0,t1 = 0,t2 = 0;
                for(int i = 0 ; i < n ; i++)
                {
                        if(a[i] == 1 && b[i] == 0) x++;
                        else if(a[i] == 0 && b[i] == 1) y++;
                        else if(a[i] == 0) t1++;
                        else t2++;
                }

                if(x == 0 && y == 0) cout << 0 << en;
                else if(x % 2 != 0) cout << 1 << en;
                else if(x > 0) cout << 2 << en;
                else
                {
                        if(t1 > 0 && t2 > 0) cout << 2 << en;
                        else cout << -1 << en;
                }
        }

        return 0;
}

