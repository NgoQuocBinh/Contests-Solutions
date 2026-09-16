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
		int n,m;
		cin >> n >> m;
		vector<int> a(n),b(m);
		for(int i = 0 ; i < n ; i++) cin >> a[i];
		for(int i = 0 ; i < m ; i++) cin >> b[i];

		if(n < 2 * m)
		{
			cout << "NO" << en;
			continue;
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		bool ok = true;
		for(int i = 0; i < m; i++)
		{
		    if(a[i] > b[i] || a[n - m + i] < b[i])
		    {
		        ok = false;
		        break;
		    }
		}

		cout << (ok ? "YES" : "NO") << '\n';
	}

	return 0;
}

