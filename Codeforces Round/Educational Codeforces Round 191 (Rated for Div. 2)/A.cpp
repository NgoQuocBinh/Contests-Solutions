#include <bits/stdc++.h>
using namespace std;

#define IShowSpeed ios::sync_with_stdio(false), cin.tie(0);
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) ((int)((x).size()))
#define pb push_back
#define fi first
#define se second
#define task "wtf"

long long ceil_div(long long a, long long b) {
 return (a + b - 1) / b;
}

signed main(){
 IShowSpeed

 if(fopen(task".inp", "r")){
   freopen(task".inp", "r", stdin);
   freopen(task".out", "w", stdout);
 }

 int t;
 cin >> t;

 while(t--){
  long long n,x,y,z;
  cin >> n >> x >> y >> z;

  long long res = ceil_div(n,x+y);
  long long res1,f = ceil_div(n,x);

  if(f<=z){
   res1 = f;
  }
  else{
   long long r = n - x*z;
   res1 = z + ceil_div(r,x+10*y);
  }
  cout << min(res,res1) << "\n";
 }

 return 0;
}