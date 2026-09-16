#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x : a) cout << x << " "; cout << "\n";
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pb push_back
#define en "\n"

const long long mod = 998244353;

long long calc(const string &s,int st)
{
	long long cnt = 0;
	for(int i = 0 ; i <= 1 ; i++)
	{
		bool ok = true;
		for(int j = st, pos = 0; j < sz(s) ; j += 2, pos++)
		{
			int e = i ^ (pos & 1);
			if(s[j] != '?' && s[j] - '0'!= e)
			{
				ok = false;
				break;
			}
		}
		if(ok) cnt++;
	}

	return cnt;
}

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
		string s;
		cin >> s;

		long long le = calc(s,0),chan = calc(s,1);

		cout << le * chan % mod << en;
	}

	return 0;
}