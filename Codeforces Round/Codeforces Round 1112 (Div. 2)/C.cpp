#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(x) cout << #x << " = ";for(auto idx : x) cout << idx << " "; cout << "\n";
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define hashmap unordered_map
#define hashset unordered_set
#define pb push_back
#define ff first
#define ss second
#define en "\n"

struct ele
{
	int l,r,u,v;
};

bool ok(const ele& e,int j,int m)
{
	int left = j, right = m - j + 1;
	if(left >= e.l && left <= e.r) return false;
	if(right >= e.u && right <= e.v) return false;
	return true;
}

bool check(int m,int n,const vector<ele>&a)
{
	if(m == 0) return true;
	int last = 0;
	for(int j = 1 ; j <= m ; j++)
	{
		int f = -1;
		for(int i = last + 1 ; i <= n ; i++)
		{
			if(ok(a[i],j,m))
			{
				f = i;
				break;
			}
		}
		if(f == -1) return false;
		last = f;
	}
	return true;
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
        	vector<ele> a(n + 1);
        	for(int i = 1 ; i <= n ; i++) cin >> a[i].l >> a[i].r >> a[i].u >> a[i].v;

        	for(int m = n ; m >= 0 ; m--)
        	{
        		if(check(m,n,a))
        		{
        			cout << m << en;
        			break;
        		}
        	}
        }

        return 0;
}