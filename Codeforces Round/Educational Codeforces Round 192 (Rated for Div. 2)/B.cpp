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
                int n;
                cin >> n;
                vector<int> a(n + 1),pre1(n + 1,0),pre2(n + 1,0);
                for(int i = 1 ; i <= n ; i++){
                        cin >> a[i];
                        pre1[i] = pre1[i - 1] + (a[i] == 1 ? 1 : -1);
                        pre2[i] = pre2[i - 1] + (a[i] == 3 ? -1 : 1);
                }

                const int INF = 1e9;
                int mn = INF;
                bool ok = false;
                for(int i = 2 ; i <= n - 1 ; i++){
                        int j = i - 1;
                        if(pre1[j] >= 0) mn = min(mn,pre2[j]);
                        if(mn != INF && pre2[i] >= mn){
                                ok = true;
                                break;
                        }
                }

                cout << (ok ? "YES" : "NO") << en;
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