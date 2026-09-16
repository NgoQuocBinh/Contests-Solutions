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
        	int n;
        	cin >> n;
        	vector<long long> w(n + 1);
        	for(int i = 1 ; i <= n ; i++) cin >> w[i];

        	if(n % 2 == 1)
        	{
        		cout << "NO" << en;
        		continue;
        	}

        	long long mxe = 0, mno = LLONG_MAX;
        	for(int i = 1 ; i <= n ; i++)
        	{
        		if(i % 2 == 0) mxe = max(mxe, w[i]);
        		else mno = min(mno, w[i]);
        	}

        	cout << (mxe + 1 < mno ? "YES" : "NO") << en;
        }

        return 0;
}