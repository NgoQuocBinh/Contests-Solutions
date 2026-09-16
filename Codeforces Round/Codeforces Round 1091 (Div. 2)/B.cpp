#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define Seaa int main()
using namespace std;

Seaa
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("solve.inp","r",stdin);
    // freopen("solve.out","w",stdout);

    ll t;
    cin >> t;

    while(t--){
        ll n,k;
        cin >> n >> k;

        vector<ll> a(n+1);

        for(ll i = 1 ; i<= n ; i++) cin >> a[i];

        ll p;
        cin >> p;

        ll x = a[p];

        ll l = 0;
        if (a[1] != x) l++;
        for (int i = 1; i < p; i++) {
            if (a[i] != a[i + 1]) l++;
        }

        ll r = 0;
        if (a[n] != x) r++;
        for (int i = p; i < n; i++) {
            if (a[i] != a[i + 1]) r++;
        }

        cout << max(l, r) << "\n";
        }

    return 0;
}