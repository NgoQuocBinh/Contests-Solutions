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

void solve(){
        int t;
        cin >> t;

        while(t--){
                int n;
                cin >> n;

                for(int i = 1 ; i <= n ; i += 2){
                        cout << i + 1 << " " << i;
                        if(i + 1 < n) cout << " ";
                }

                cout << en;
        }
}

int main(){
        fastIO;

        solve();

        return 0;
}