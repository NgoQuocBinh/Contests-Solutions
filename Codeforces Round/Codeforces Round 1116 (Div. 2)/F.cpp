#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x : a) cout << x << " "; cout << "\n";
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pb push_back
#define en "\n"

bool check(long long limit, int n,const vector<long long> &a)
{
    long long r = max(0LL,limit - 60);
    if(r >= n) return true;

    // priority_queue<long long> pq;
    // int rem = n - (int)r;
    // for(int i = 0 ; i < rem ; i++) pq.push(a[i]);
    priority_queue<long long> pq(a.begin(), a.begin() + (n - (long long) r));
    long long st = min(limit - 1, 59LL);
    for(int i = st ; i >= 0 ; i--)
    {
        if(pq.empty()) break;
        long long res = pq.top();
        pq.pop();
        long long val = 1LL << i;
        if(val < res) pq.push(res - val);
    }

    return pq.empty();

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
    // cout << "T = " << _ << en;

    while(_--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for(int i = 0 ; i < n ; i++) cin >> a[i];

        sort(all(a));

        // cout << "hi";

        // vdebug(a);

        long long l = 0, r = n + 60;
        while(l < r)
        {
            long long mid = l + ((r - l) >> 1);
            if(check(mid,n,a)) r = mid;
            else l = mid + 1;
        }

        cout << r  << en;
    }

    return 0;
}