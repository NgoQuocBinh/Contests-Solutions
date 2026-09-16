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
		vector<long long> a(n);
		for(int i = 0 ; i < n ; i++) cin >> a[i];

		vector<long long> calc(n -1);
		for(int i = 0 ; i < n - 1 ; i++) calc[i] = a[i + 1] - a[i];

		int l = 0;
		while(l < n - 1)
		{
			int r = l;
			while(r + 1 < n - 1 && abs(calc[r + 1]) % 2 == abs(calc[l] % 2))r++;
			sort(calc.begin() + l, calc.begin() + r + 1);
			l = r + 1;
		}

		for(int i = 0 ; i < n - 1 ; i++)
		{
			a[i + 1] = a[i] + calc[i];
		}

		for(int i = 0 ; i < n ; i++) cout << a[i] << " ";
		cout << en;
	}

	return 0;
}

