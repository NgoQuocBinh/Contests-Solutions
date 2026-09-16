#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x : a) cout << x << " "; cout << "\n";
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
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
		long long n,m,x,y;
		cin >> n >> m >> x >> y;
		vector<long long> a(x + 1),b(y + 1);
		for(int i = 1 ; i <= x ; i++) cin >> a[i];
		for(int i = 1 ; i <= y ; i++) cin >> b[i];

		long long t = min(n,x), t1 = min(m,y);
		long long limit = t + t1;
		if(t == n && t1 == m) limit = n + m - 1;
		long long mx = 0,cnt1 = 0,cnt2 = 0,res = 0,i = x,j = y;
		while(res < limit && (i > 0 || j > 0))
		{
	        if(i > 0 && j > 0 && a[i] == b[j])
	        {
	            mx += a[i];
	            res++;
	            i--;
	            j--;
	        }
	        else if(j == 0 || (i > 0 && a[i] > b[j]))
	        {
	            if(cnt1 < t)
	            {
	                mx += a[i];
	                res++;
	                cnt1++;
	            }
	            i--;
	        }
	        else 
	        {
	            if(cnt2 < t1)
	            {
	                mx += b[j];
	                res++;
	                cnt2++;
	            }
	            j--;
	        }
	    }

	    cout << mx << en;
	}

	return 0;
}