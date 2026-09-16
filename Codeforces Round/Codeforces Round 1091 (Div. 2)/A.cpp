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

        vector<ll> a(n);

        ll sum = 0;

        for(ll i = 0 ; i < n ; i++){
            cin >> a[i];
            sum += a[i];
        }

        if (sum % 2 != 0 || (1LL * n * k) % 2 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}