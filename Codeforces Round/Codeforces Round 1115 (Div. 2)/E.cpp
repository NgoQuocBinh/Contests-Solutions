#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x : a) cout << x << " "; cout << "\n";
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define en "\n"

void brute(int n)
{
	for(int a = 1; a <= n; a++)
	{
        for(int d = 1; a + 2 * d <= n; d++) 
        {
            int b = a + d;
            int c = a + 2 * d;

            if((a ^ b ^ c) == 0) 
            {
                debug(d);
            }
        }
    }
}

const long long mod = 1e9 + 7;
long long dp[65][2][2];
vector<int> bit(62);
long long solve(int i, int cur, int sm)
{
    if(i == 0)
    {
        int c = cur;
        if(!sm && c > bit[0]) return 0;
        return 1;
    }

    if(dp[i][cur][sm] != -1) return dp[i][cur][sm];

    long long res = 0;
    for(int pre = 0; pre <= 1; pre++)
    {
        if(cur && pre) continue;
        for(int y = 0; y <= 1; y++)
        {
            if(pre == 0 && y) continue;
            int c = cur | y;
            int ns = sm;
            if(!sm)
            {
                if(c > bit[i]) continue;
                if(c < bit[i]) ns = 1;
            }
            res = (res + solve(i - 1, pre, ns)) % mod;
        }
    }
    return dp[i][cur][sm] = res;
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

	// brute(1000);

	int _;
	cin >> _;

	while(_--)
	{
		unsigned long long n;
		cin >> n;

		// long long ans = 0;
		// for(int i = 0 ; i < 64 ; i++)
		// {
		// 	unsigned long long d = 1ULL << (i + 1), x = n / d;
		// 	if(x <= 1) break;
		// 	ans = (ans + (x - 1) % mod) % mod;
		// }

		// cout << ans % mod << en;
	
		for(int i = 0; i < 62; i++) bit[i] = (n >> i) & 1;
        memset(dp, -1, sizeof(dp));
        long long ans = 0;
        for(int k = 0; k <= 60; k++)
        {
            bool ok = true;
            int ck = 0;
            for(int j = 61; j >= k + 1; j--)
            {
                int c = (j == k + 1);
                if(!ck)
                {
                    if(c > bit[j])
                    {
                        ok = false;
                        break;
                    }
                    if(c < bit[j]) ck = 1;
                }
            }

            if(ok) ans = (ans + solve(k, 1, ck)) % mod;
        }

        cout << ans << en;
	}

	return 0;
}

