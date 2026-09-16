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
		int n,q;
		cin >> n >> q;
		string s,t;
		cin >> s >> t;

		vector<int> pref_s(n + 1, 0),pref_t(n + 1, 0),pref_e(n + 1, 0);
	    for(int i = 0; i < n; i++) 
	    {
	        pref_s[i + 1] = pref_s[i] + (s[i] == '1');
	        pref_t[i + 1] = pref_t[i] + (t[i] == '1');
	        pref_e[i + 1] = pref_e[i] + (s[i] == t[i]);
	        // debug(pref_s[i +1];
	        // debug(pref_t[i + 1]);
	        // debug(pref_e[i + 1]);
	    }

	    // vdebug(pref_s);
	    // vdebug(pref_e);
	    // vdebug(pref_t);
	    
	    while(q--)
	    {
	    	int l, r;
	        cin >> l >> r;
	        int e = pref_e[r] - pref_e[l - 1],sum_s = pref_s[r] - pref_s[l - 1],sum_t = pref_t[r] - pref_t[l - 1];
	        if (e >= abs(sum_s - sum_t))  cout << "YES" << en;
	        else cout << "NO" << en;
	    }
	}

	return 0;
}

