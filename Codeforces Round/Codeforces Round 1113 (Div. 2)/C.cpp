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
		int n;
		cin >> n;
		vector<int> a(2 * n + 1),l(n + 1,0),r(n + 1,0);
		for(int i = 1 ; i <= 2 * n ; i++)
		{
			cin >> a[i];
			if(l[a[i]] == 0) l[a[i]] = i;
			else r[a[i]] = i;
		}

		vector<long long> dp(2 * n + 1,0);
		for(int i = 1 ; i <= 2 * n ; i++)
		{
			dp[i] = dp[i - 1];
			if(r[a[i]] == i)
			{
				int le = l[a[i]];
				long long len = i - le + 1, w = len * len - len;
				dp[i] = max(dp[i], dp[le - 1] + w);
			}
		}

		cout << 2LL * n + dp[2 * n] << en;
	}

	return 0;
}