#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define hashmap unordered_map
#define hashset unordered_set
#define pb push_back
#define ff first
#define ss second
#define en "\n"

const int maxn = 300005;
int n, q;
int l, r;
string s;
int pref0[maxn];
int pref1[maxn];
int prefd[maxn];

namespace precompute
{
        void run()
        {
                for(int i = 1; i <= n; ++i) 
                {
                        pref0[i] = pref0[i - 1] + (s[i - 1] == '0');
                        pref1[i] = pref1[i - 1] + (s[i - 1] == '1');
                        prefd[i] = prefd[i - 1];
                        if(i < n && s[i - 1] != s[i]) prefd[i]++;
                }
        }       
}

namespace subtask_full
{
        void solve()
        {
                int cnt0 = pref0[r] - pref0[l - 1];
                int cnt1 = pref1[r] - pref1[l - 1];
                int diff = 1;

                if(l < r) diff += prefd[r - 1] - prefd[l - 1];
                ll k = 1;
                ll need0 = (cnt0 + 1LL) / 2;
                ll need1 = (cnt1 + 1LL) / 2;
                ll needd = diff / 2LL;
                ll needall = (cnt0 + cnt1 - diff / 2 + 2LL) / 3;
                k = max(k, need0);
                k = max(k, need1);
                k = max(k, needd);
                k = max(k, needall);

                cout << 4LL * k - (r - l + 1) << en;
        }
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        #define task "sample"
        if (fopen(task ".inp", "r"))
        {
                freopen(task ".inp", "r", stdin);
                freopen(task ".out", "w", stdout);
        }

        cin >> n >> q >> s;
        precompute::run();

        while(q--)
        {
                cin >> l >> r;

                subtask_full::solve();
        }

        return 0;
}