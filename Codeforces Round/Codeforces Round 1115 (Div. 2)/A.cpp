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

		map<int,int> freq;
		long long sum = 0;
		for(int i = 0 ; i < n ; i++)
		{
			int x;
			cin >> x;

			sum += x;
			freq[x]++;
		}

		int mx = 0,v = 0;
		for(auto[x,c] : freq)
		{
			if(c > mx)
			{
				mx = c;
				v = x;
			}
		}

		int o = n - mx;
		if(mx <= o + 1) cout << sum << en;
		else
		{
			int tr = mx - (o + 2);
			cout << sum - 1LL * tr * v << en;
		}
	}

	return 0;
}

