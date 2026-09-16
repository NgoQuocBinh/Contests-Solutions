#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define en "\n"

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

        int t;
        cin >> t;

        while(t--)
        {
                int n, m;
                cin >> n >> m;
                vector<string> words(n), av(m);
                bool a[26] = {};
                for(auto &w : words)
                {
                        cin >> w;
                        a[w[0] - 'a'] = true;
                }

                for(auto &s : av) cin >> s;
                vector<bool> used(m, false);
                int done = 0;
                bool inP = true;
                while (inP)
                {
                        inP = false;

                        for(int i = 0; i < m; i++)
                        {
                                if(used[i]) continue;
                                bool can = true;
                                for(char c : av[i])
                                {
                                        if(!a[c - 'A'])
                                        {
                                                can = false;
                                                break;
                                        }
                                }
                                if(can)
                                {
                                        used[i] = true;
                                        done++;
                                        a[av[i][0] - 'A'] = true;
                                        inP = true;
                                }
                        }
                }

                cout << (done == m ? "YES" : "NO") << en;
        }

    return 0;
}
