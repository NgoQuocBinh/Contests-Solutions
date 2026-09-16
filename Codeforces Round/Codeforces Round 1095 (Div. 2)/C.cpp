#include <bits/stdc++.h>
#include <cassert>
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
                vector<int> a(n);
                for(int i = 0 ; i < n ; i++) cin >> a[i];
                
                multiset<int> ms(all(a));
                int l = 0, r = n + 1;
                while(l < r)
                {
                        int mid = (l + r) / 2;
                        assert(sz(ms) == n);
                                
                        bool ok = true;
                        vector<int> store;
                        for(int i = mid - 1 ; i >= 0 ; i--)
                        {
                                if(ms.count(i))
                                {
                                        store.pb(i);
                                        ms.erase(ms.find(i));
                                        continue;
                                }
                                else
                                {
                                        int res = *ms.rbegin();

                                        if(res < 2 * i + 1)
                                        {
                                                ok = false;
                                                break;
                                        }

                                        store.pb(res);
                                        ms.erase(ms.find(res));
                                }
                        }

                        for(int i = 0 ; i < sz(store) ; i++) ms.insert(store[i]);

                        if(ok) l = mid + 1;
                        else r = mid;
                }

                assert(l > 0);
                l--;

                cout << l << en;
        }

        return 0;
}