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
        ll n,m,a,b;
        cin >> n >> m >> a >> b;

        if(__gcd(n,a)==1&&__gcd(m,b)==1&&__gcd(n,m)<=2){
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    

    return 0;
}