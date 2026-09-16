/*
       shool : Thi Tran secondary school
       participant : Ngo Quoc Binh
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define lli long long int
#define ulli unsigned long long int
#define ld long double

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x : a) cout << x << " "; cout << "\n";
#define IShowSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define hashmap unordered_map
#define hashset unordered_set
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) ((int)((x).size()))

#define pb push_back
#define en '\n'
#define fi first
#define se second
#define task "wtf"

void solve(){
    int n,c;
    cin >> n >> c;
    vector<int> a(n),b(n);
    for(int i = 0 ; i < n ; i++)cin >> a[i];
    for(int i = 0 ; i < n ; i++) cin >> b[i];

    int ans = INT_MAX;
    bool ok = true;
    int res = 0;
    for(int i = 0 ; i < n ; i++){
        if(a[i] < b[i]){
            ok = false;
            break;
        }
        res += a[i] - b[i];
    }
    if(ok) ans = min(ans,res);

    sort(all(a));
    sort(all(b));

    ok = true;
    res = c;
    for(int i = 0 ; i < n ; i++){
        if(a[i] < b[i]){
            ok = false;
            break;
        }
        res += a[i] - b[i];
    }
    if(ok) ans = min(ans,res);

    cout << (ans == INT_MAX ? -1 : ans) << en;
}

int main(){
    IShowSpeed

    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    int Test_Cases = 1;
    cin >> Test_Cases;
    for(int i = 1 ; i <= Test_Cases ; i++){
        solve();
    }

    return 0;
}