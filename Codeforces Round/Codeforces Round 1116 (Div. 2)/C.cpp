#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x : a) cout << x << " "; cout << "\n";
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pb push_back
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
		string s;
		cin >> s;

		int ans = 0,ans1 = 0;
		for(int i = 0 ; i < 2 * n ; i++)
		{
			int l;
			if(s[i] == '1')
			{
				int nxt = (i + 1) % (2 * n);
				if(s[nxt] == '0') l = nxt;
				else l = i;
				if(l % 2 != 0) ans++;
				else ans1++;
			}
		}

		cout << ans << " " << ans1 << en;
	}

	return 0;
}