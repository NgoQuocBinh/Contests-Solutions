#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x : a) cout << x << " "; cout << "\n";
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define en "\n"

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #define task "sample"
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }

    const int MAX = 200001;
    vector<bool> prime(MAX + 1, true);
    prime[0] = prime[1] = false;

    for(int i = 2; i * i <= MAX; i++) 
    {
        if(prime[i]) 
        {
            for(int j = i * i; j <= MAX; j += i) prime[j] = false;
        }
    }

    int _;
    cin >> _;

    while(_--)
    {
        int n;
        cin >> n;

        cout << (prime[n + 1] ? "YES" : "NO") << en;
    }

    return 0;
}