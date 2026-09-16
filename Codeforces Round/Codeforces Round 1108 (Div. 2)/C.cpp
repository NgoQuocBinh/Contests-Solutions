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

const int mod = 1e9 + 7;

ll power(ll a, ll b){
        ll res = 1;
        while(b){
                if(b & 1) res = res * a % mod;
                a = a * a % mod;
                b >>= 1;
        }
        return res;
}

void solve(){
        int t;
        cin >> t;

        while(t--){
                int n;
                cin >> n;
                int cnt = 0;
                vector<int> a;
                for(int i = 0; i < n; i++){
                        int x;
                        cin >> x;
                        if(x == -1) cnt++;
                        else a.pb(x);
                }

                ll e = (cnt == 0 ? 1 : power(2, cnt - 1)),o = (cnt == 0 ? 0 : power(2, cnt - 1)),w0 = 1,k = 0;
                if(!a.empty()){
                        int val = a[0];
                        int num = 1;
                        for(int i = 1; i < sz(a); i++){
                                if(a[i] == val){
                                        num++;
                                }
                                else{
                                        w0 = w0 * power(2, num - 1) % mod;
                                        if(val + 1 == a[i]) k++;
                                        val = a[i];
                                        num = 1;
                                }
                        }
                        w0 = w0 * power(2, num - 1) % mod;
                }

                ll w1 = k * w0 % mod;
                ll ans = (e * w0 % mod + o * w1 % mod) % mod;

                cout << ans << en;
        }
}

int main(){
        fastIO;

        solve();

        return 0;
}