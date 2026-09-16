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
		int n;
	    cin >> n;
	    vector<int> a(n);
	    for(int i = 0; i < n; i++) 
	    {
	        cin >> a[i];
	    }
	 
	    vector<int> b, c;
	    for(int i = 0; i < n; i++) 
	    {
	        if(b.empty() || b.back() != a[i]) 
	        {
	            b.pb(a[i]);
	            c.pb(1);
	        } 
	        else 
	        {
	            c.back()++;
	        }
	    }
	    
	    int m = sz(b);
	    if(m == 1) 
	    {
	        cout << 1 << en;
	        continue;
	    }

	    bool c2 = false;
	    for(int i = 0; i < m - 1; ++i) 
	    {
	        if(c[i] >= 2 && c[i+1] >= 2) 
	        {
	            c2 = true;
	            break;
	        }
	    }
	    
	    if(c2) 
	    {
	        cout << m + 2 << en;
	        continue;
	    }
	    
	    bool c1 = false;
	    for(int i = 0; i < m; ++i) 
	    {
	        if(c[i] >= 2) 
	        {
	            bool rs = false;
	            if(i < m - 1) 
	            {
	                if(i + 2 >= m || b[i + 2] != b[i]) 
	                {
	                    rs = true;
	                }
	            }
	            
	            bool ls = false;
	            if(i > 0) 
	            { 
	                if(i - 2 < 0 || b[i - 2] != b[i]) 
	                {
	                    ls = true;
	                }
	            }
	            
	            if(rs || ls) 
	            {
	                c1 = true;
	                break;
	            }
	        }
	    }
	    
	    if(c1)
	    {
	        cout << m + 1 << en;
	    } 
	    else 
	    {
	        cout << m << en;
	    }
	}

	return 0;
}