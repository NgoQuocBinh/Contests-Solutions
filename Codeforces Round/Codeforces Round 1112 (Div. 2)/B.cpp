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
        	int n,k;
        	cin >> n >> k;
        	vector<pair<int,int>> cnt;
        	if(n % 2 == 0) cnt.pb({n / 2,n / 2});
        	else
        	{
        		cnt.pb({(n + 1) / 2, (n - 1) / 2});
        		cnt.pb({(n - 1) / 2, (n + 1) / 2});
        	}

        	int m = n - k;
        	int ok = 0;
        	for(auto [a,b] : cnt)
        	{
        		for(int i = max(0,m - b) ; i <= min(a,m) ; i++)
        		{
        			string ans;
        			int o = m - i;
        			if(o > b) continue;
        			if(abs(i - o) > 1) continue;

        			if((i == 0 && a > 0) || (o == 0 && b > 0)) continue;

        			vector<int> len0(i,1),len1(o,1);
        			int r0 = a - i, r1 = b - o;

        			if(i) len0[0] += r0;
        			if(o) len1[0] += r1;

        			if(i >= o)
        			{
        				int j = 0, k = 0;
        				while(j < i || k < o)
        				{
        					if(j < i) ans += string(len0[j++],'0');
        					if(k < o) ans += string(len1[k++],'1');
        				}
        			}
        			else
        			{
        				int j = 0, k = 0;
        				while(j < i || k < o)
        				{
        					if(k < o) ans += string(len1[k++],'1');
        					if(j < i) ans += string(len0[j++],'0');
        				}
        			}

        			ok = 1;
        			cout << ans << en;
        			break;
        		}
        		if(ok) break;
        	}
        	if(!ok) cout << -1 << en;
        }

        return 0;
}