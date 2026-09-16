/*
       shool : Cu Chi High School
       participant : Ngo Quoc Binh
*/
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " = " << x << "\n";
#define vdebug(a) cerr << #a << " = ";for(auto x : a) cerr << x << " ";cerr << "\n";
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
#define ff first
#define ss second

using ll = long long;
using ull = unsigned long long;
using ld = long double;

ll calc(ll x){
        if(x == 0) return 0;
        int b = 64 - __builtin_clzll(x);
        int c = __builtin_popcountll(x);
        return b + c - 1;
}

void solve(){
        int t;
        cin >> t;

        while(t--){
                int n;
                cin >> n;
                vector<ll> a(n);
                for(int i = 0; i < n; i++) cin >> a[i];

                ll ans = -1;
                for(int k = 0; k <= 20; k++){
                        ll sum = 0;
                        ll p = 1LL << k;
                        for(int i = 0; i < n; i++){
                                ll x = a[i];
                                ll y = ((x + p - 1) / p) * p;
                                if(y == 0) y = p;
                                ll best = 2e18;
                                while(true){
                                        ll cur = (y - x) + calc(y);
                                        best = min(best, cur);
                                        if(y - x >= best) break;
                                        y += p;
                                }

                                sum += best;
                        }

                        sum -= 1LL * k * (n - 1);
                        if(ans == -1 || sum < ans) ans = sum;
                }

                cout << ans << en;
        }
}

int main(){
        fastIO;

        solve();

        return 0;
}