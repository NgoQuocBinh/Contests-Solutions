#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " = " << x << "\n";
#define vdebug(a) cerr << #a << " = "; for(auto x : a) cerr << x << " "; cerr << "\n";
#define open(task) freopen(task".inp","r",stdin);freopen(task".out","w",stdout);
#define sz(x) ((int)x.size())
#define all(x) (x).begin(),(x).end()
#define hashmap unordered_map
#define hashset unordered_set
#define pb push_back
#define ff first
#define ss second
#define en "\n"

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	while(t--)
	{
		int n, q;
		cin >> n >> q;
		vector<int> a(n);
		for(int i = 0; i < n; i++) cin >> a[i];

		vector<int> s = a;
		sort(all(s));
		vector<int> u = s;
		u.erase(unique(all(u)), u.end());
		vector<int> f(sz(u));
		int cnt = 0;
		vector<bool> p(n + 1);
		p[0] = true;

		for(int i = 0; i < n; i++)
		{
			int x = lower_bound(all(u), a[i]) - u.begin();
			if(f[x] == 0) cnt++;
			f[x]++;
			if(f[x] == 0) cnt--;

			int y = lower_bound(all(u), s[i]) - u.begin();
			if(f[y] == 0) cnt++;
			f[y]--;
			if(f[y] == 0) cnt--;
			if(cnt == 0) p[i + 1] = true;
		}

		int ans = 0;
		for(int b = 0; b <= 20; b++)
		{
			bool ok = true;
			int step = 1 << b;
			for(int i = step; i < n; i += step)
			{
				if(!p[i])
				{
					ok = false;
					break;
				}
			}

			if(ok)
			{
				if(b == 0) ans = 0;
				else ans = 1 << (b - 1);
				break;
			}
		}

		cout << ans << en;
	}

	return 0;
}
