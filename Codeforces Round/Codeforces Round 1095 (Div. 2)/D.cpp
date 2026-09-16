#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(x) cout << #x << " = ";for(auto idx : x) cout << idx << " "; cout << "\n";
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define hashmap unordered_map
#define hashset unordered_set
#define pb push_back
#define ff first
#define ss second
#define en "\n"

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int _;
        cin >> _;

        while(_--)
        {
                int n;
                cin >> n;
                vector<int> a(n),chan,le;
                for(int i = 0 ; i < n ; i++)
                {
                        cin >> a[i];
                        if(a[i] % 2 == 0) chan.pb(a[i]);
                        else le.pb(a[i]);
                }

                int min_chan = INT_MAX,max_chan = INT_MIN,min_le = INT_MAX,max_le = INT_MIN;
                if(sz(chan) > 0) min_chan = *min_element(all(chan)), max_chan = *max_element(all(chan));
                if(sz(le) > 0) min_le = *min_element(all(le)), max_le = *max_element(all(le));

                bool ok = true;
                if(sz(chan) > 0)
                {
                        int try_chan = chan[0];
                        int si = sz(chan);
                        for(int i = 0 ; i < si ; i++)
                        {
                                if(try_chan > chan[i])
                                {
                                        if(min_le > chan[i] && max_le < try_chan)
                                        {
                                                ok = false;
                                                break;
                                        }
                                }
                                else
                                {
                                        try_chan = chan[i];
                                }
                        }
                }

                if(sz(le) > 0)
                {
                        int try_le = le[0];
                        int si = sz(le);
                        for(int i = 0 ; i < si ; i++)
                        {
                                if(try_le > le[i])
                                {
                                        if(min_chan > le[i] && max_chan < try_le)
                                        {
                                                ok = false;
                                                break;
                                        }
                                }
                                else
                                {
                                        try_le = le[i];
                                }
                        }
                }

                cout << (ok ? "YES" : "NO") << en;
        }

        return 0;
}