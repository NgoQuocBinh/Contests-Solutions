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
		int n,m;
		cin >> n >> m;
		vector<long long> v(n);
		for(int i = 0 ; i < n ; i++) cin >> v[i];

		vector<long long> a(1LL * n * m);
		for(int i = 0 ; i < 1LL * n * m ; i++)
		{
			cin >> a[i];
		}

		if(m == 1)
		{
			cout << 1 << en;
			continue;
		}
		else
		{
			int ans = m;
			vector<long long> t;
			for(int i = n - 1 ; i >= 0 ; i--)
			{
				vector<long long> th = t;
				th.insert(th.end(), a.begin() + 1LL * i * m, a.begin() + 1LL * (i + 1) * m);
				sort(th.rbegin(),th.rend());
				long long curs = 0;
				int limit = min((int)sz(th), m - 1);
				for(int j = 1 ; j <= limit ; j++)
				{
					curs += th[j - 1];
					if(curs >= v[i])
					{
						ans = min(ans,j);
						break;
					}
				}
				t.assign(th.begin(),th.begin() + limit);
			}

			cout << ans << en;
		}
	}

	return 0;
}

