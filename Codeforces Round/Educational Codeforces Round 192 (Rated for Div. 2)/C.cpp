/*
       shool : Cu Chi High School
       participant : Ngo Quoc Binh
*/
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x : a) cout << x << " "; cout << "\n";
#define IShowSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define hashmap unordered_map
#define hashset unordered_set
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define rev(x) reverse(all(x))
#define sz(x) ((int)((x).size()))
#define max_arr(x) *max_element(all(x))
#define min_arr(x) *min_element(all(x))

#define pb push_back
#define pf push_front
#define PB pop_back
#define PF pop_front
#define en '\n'
#define fi first
#define se second
#define task "wtf"

using ll = long long;
using ull = unsigned long long;
using ld = long double;

void solve(){
        int t;
        cin >> t;

        while(t--){
                int n, k;
                cin >> n >> k;
                vector<int> a(n);
                for(int i = 0 ; i < n ; i++) cin >> a[i];
                vector<int> c;
                int cnt = 1;
                for(int i = 1; i < n; i++){
                        if(a[i] == a[i - 1]) cnt++;
                        else{
                                c.pb(cnt);
                                cnt = 1;
                        }
                        // debug(cnt);
                }

                c.pb(cnt);
                map<int, int> mp;
                for(int x : c) mp[x]++;
                vector<int> u = {0};
                for(auto [x, y] : mp) u.pb(x);
                int m = sz(u) - 1;
                vector<ll> sufCnt(m + 2), sufSum(m + 2);
                for(int i = m; i >= 1; i--){
                        sufCnt[i] = sufCnt[i + 1] + mp[u[i]];
                        sufSum[i] = sufSum[i + 1] + 1LL * mp[u[i]] * u[i];
                }

                int ans = 0;
                for(int i = 0; i < m; i++){
                        ll num = sufCnt[i + 1];
                        ll sum = sufSum[i + 1];
                        if(num == 0) continue;
                        ll rem = k - sum;
                        if(rem % num) continue;
                        ll x = rem / num;
                        ll l = max(1LL * u[i], -x);
                        ll r = u[i + 1] - 1;
                        if(l <= r) ans++;
                }

                // vdebug(sufSum);

                cout << ans << en;
        }
}
int main(){
        IShowSpeed

        if(fopen(task".inp", "r")){
                freopen(task".inp", "r", stdin);
                freopen(task".out", "w", stdout);
        }

        solve();

        return 0;
}