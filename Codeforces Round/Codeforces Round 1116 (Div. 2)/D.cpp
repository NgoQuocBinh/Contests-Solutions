#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x : a) cout << x << " "; cout << "\n";
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pb push_back
#define en "\n"

const int maxn = 1e6 + 5;
const long long mod = 998244353;
long long fact[maxn], inv[maxn];

long long binpow(long long a, long long b, long long mod = mod)
{
	long long res = 1;
	a %= mod;
	while(b > 0)
	{
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

long long calc(int n, int k)
{
	if(k < 0 || k > n) return 0;
	return fact[n] * inv[k] % mod * inv[n - k] % mod;
}

struct Stree
{
	int n;
	vector<long long> tree;

	Stree(int n) : n(n)
	{
		tree.assign(4 * n + 5, 0);
	}

	void update(int id, int l, int r, int pos, long long val)
	{
		if(l == r)
		{
			tree[id] = val;
			return;
		}
		int mid = l + r >> 1;
		if(pos <= mid) update(id * 2, l, mid, pos, val);
		else update(id * 2 + 1, mid + 1, r, pos, val);
		tree[id] = tree[id * 2] + tree[id * 2 + 1];
	}

	long long get(int id, int l, int r, int u, int v)
	{
		if(v < l || r < u) return 0;
		if(u <= l && r <= v) return tree[id];
		int mid = l + r >> 1;
		return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	#define task "sample"
	if(fopen(task".inp", "r"))
	{
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}

	fact[0] = 1;
	inv[0] = 1;
	for(int i = 1; i < maxn; i++) fact[i] = fact[i - 1] * i % mod;
	inv[maxn - 1] = binpow(fact[maxn - 1], mod - 2);
	for(int i = maxn - 2; i >= 1; i--) inv[i] = inv[i + 1] * (i + 1) % mod;

	int _;
	cin >> _;

	while(_--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;

		if(n <= 1)
		{
			cout << 1 << en;
			continue;
		}

		Stree st(n + 5);
		int k = 0;
		for(int i = 0; i < n - 1; i++)
		{
			if(s[i] != s[i + 1])
			{
				st.update(1, 1, n, i + 1, 1);
				k++;
			}
		}

		if(k == 0)
		{
			cout << 1 << en;
			continue;
		}

		vector<long long> p;
		for(int i = 1; i <= k; i++)
		{
			int l = 1;
			int r = n;
			int pos = -1;
			while(l <= r)
			{
				int mid = l + r >> 1;
				if(st.get(1, 1, n, 1, mid) >= i)
				{
					pos = mid;
					r = mid - 1;
				}
				else
				{
					l = mid + 1;
				}
			}

			p.pb(pos - 1);
		}

		vector<long long> c;
		c.pb(p[0]);
		for(int i = 1; i < k; i++) c.pb(p[i] - p[i - 1] - 1);
		c.pb(n - 2 - p.back());
		long long s1 = 0;
		long long s2 = 0;
		for(int i = 0; i < sz(c); i++)
		{
			if(i % 2 == 0) s1 += c[i];
			else s2 += c[i];
		}

		long long v1 = k / 2 + 1;
		long long v2 = (k + 1) / 2;
		long long ans1 = calc(s1 + v1 - 1, v1 - 1);
		long long ans2 = calc(s2 + v2 - 1, v2 - 1);
		long long ans = ans1 * ans2 % mod;

		cout << ans << en;
	}

	return 0;
}