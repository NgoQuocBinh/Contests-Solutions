#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x : a) cout << x << " "; cout << "\n";
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
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
        int n;
        cin >> n;
        string s;
        cin >> s;

        int cnt0 = 0, cnt1 = 0;
        for(char c : s) 
        {
            if(c == '0') cnt0++;
            else cnt1++;
        }

        int l0 = 0;
        char tar = '0';
        for(char c : s) 
        {
            if(c == tar) 
            {
                l0++;
                tar = (tar == '0') ? '1' : '0';
            }
        }

        int l1 = 0;
        tar = '1';
        for(char c : s) 
        {
            if(c == tar) 
            {
                l1++;
                tar = (tar == '1') ? '0' : '1';
            }
        }

        int ans = -1;
        int d = cnt0 - cnt1;
        for(int i = -1; i <= 1; i++) 
        {
            if(abs(d - i) <= 1) 
            {
                int len = -1;
                if(i == 1) 
                {
                    if(l0 > 0) 
                    {
                        len = (l0 % 2 == 1) ? l0 : l0 - 1;
                    }
                } 
                else if(i == -1) 
                {
                    if(l1 > 0) 
                    {
                        len = (l1 % 2 == 1) ? l1 : l1 - 1;
                    }
                } 
                else if(i == 0) 
                {
                    int len0 = (l0 % 2 == 0) ? l0 : l0 - 1;
                    int len1 = (l1 % 2 == 0) ? l1 : l1 - 1;
                    len = max(len0, len1);
                }

                if(len != -1) ans = max(ans, len);
            }
        }

        if(ans == -1) cout << -1 << en;
        else cout << n - ans << en;
    }

    return 0;
}