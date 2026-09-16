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

struct fen{
    int n;
    vector<ll> bit;
    fen(int n) : n(n),bit(n + 1, 0){}
    void add(int idx, ll val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }

    ll sum(int idx) const {
        ll res = 0;
        for (; idx > 0; idx -= idx & -idx) res += bit[idx];
        return res;
    }
};

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n),b(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    for(int i = 0 ; i < n ; i++) cin >> b[i];

    vector<int> res(n);
    bool ok = true;
    for(int i = 0 ; i < n ; i++){
        int pos = lower_bound(all(b),a[i]) - b.begin();
        if(pos == n){
            ok = false;
            break;
        }
        res[i] = pos + 1;
        // debug(pos);
        // debug(res[i]);
    }

    if(!ok){
        cout << "-1\n";
        return;
    }

    vector<vector<int>> tri(n + 1);
    for(int i = 0 ; i < n ; i++){
        tri[res[i]].pb(i + 1);
    }

    priority_queue<int,vector<int>,greater<int>> heap;
    vector<int> q;
    q.reserve(n);

    for(int i = 1; i <= n ; i++){
        for(int idx : tri[i]) heap.push(idx);
        if(heap.empty()){
            ok = false;
            break;
        }
        q.pb(heap.top());
        heap.pop();
    }

    if(!ok){
        cout << "-1\n";
        return;
    }

    ll cnt = 0;
    fen ft(n);
    for(int i = 0 ; i < n ; i++){
        int x = q[i];
        cnt += i - ft.sum(x);
        ft.add(x,1);
    }

    // vdebug(a);
    // vdebug(b);

    cout << cnt << en;
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