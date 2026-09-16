#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define Seaa int main()
using namespace std;

const ll MAX_SUM = 20001;

bool solve_backtrack(ll n, vector<ll>& a, vector<ll>& res, vector<bool>& used, bitset<MAX_SUM>& possible) {
    if ((ll)res.size() == n) return true;
    for (ll i = 0; i < n; ++i) {
        if (!used[i]) {
            ll val = a[i];
            if (!possible.test(val)) {
                used[i] = true;
                res.pb(val);
                bitset<MAX_SUM> next_possible = possible | (possible << val);
                if (solve_backtrack(n, a, res, used, next_possible)) return true;
                res.pop_back();
                used[i] = false;
            }
        }
    }
    return false;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    bool has_duplicates = false;
    vector<ll> freq(101, 0);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        freq[a[i]]++;
        if (freq[a[i]] > 1) has_duplicates = true;
    }
    if (has_duplicates) {
        cout << -1 << '\n';
        return;
    }
    sort(a.rbegin(), a.rend());
    vector<ll> res;
    vector<bool> used(n, false);
    bitset<MAX_SUM> possible;
    possible.set(0);
    if (solve_backtrack(n, a, res, used, possible)) {
        for (ll i = 0; i < n; ++i) {
            cout << res[i] << (i == n - 1 ? "" : " ");
        }
        cout << '\n';
    } else cout << -1 << '\n';
}

Seaa
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}