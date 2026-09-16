/* Minh Chau <3 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 676767677;
const ll INF = (ll)4e18;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> a(n+1);
        for(ll i = 1; i <= n; i++) cin >> a[i];

        vector<ll> dp(n+1, INF);
        dp[0] = 0;

        for(ll i = 1; i <= n; i++){
            ll prod = 1;
            for(ll j = i; j >= 1; j--){
                if(j < i && a[j] > a[j+1]) break;
                prod = (prod * a[j]) % MOD;
                dp[i] = min(dp[i], (dp[j-1] + prod) % MOD);
            }
        }

        cout << dp[n] % MOD << '\n';
    }

    return 0;
}