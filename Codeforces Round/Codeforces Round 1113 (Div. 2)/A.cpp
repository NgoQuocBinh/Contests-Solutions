#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x : a) cout << x << " "; cout << "\n";
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

        int _;
        cin >> _;

        while(_--)
        {
                string s;
                cin >> s;

                string best = "";

                for(int i = 0; i < s.size(); i++)
                {
                    if (s[i] != '0') continue;
                    string t = s;
                    t.erase(i, 1);
                    t.erase(t.find('1'), 1);
                    if(best.empty() || t > best) best = t;
                }

                cout << best << en;
        }

        return 0;
}

