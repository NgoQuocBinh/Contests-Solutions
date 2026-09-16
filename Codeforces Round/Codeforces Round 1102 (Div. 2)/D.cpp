#include <bits/stdc++.h>
using namespace std;

#define IShowSpeed ios::sync_with_stdio(false), cin.tie(0);
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) ((int)((x).size()))
#define pb push_back
#define fi first
#define se second

signed main(){
 IShowSpeed

 int t;
 cin >> t;

 while(t--){
  int n,k;
  cin >> n >> k;
  string s,z;
  cin >> s >> z;
  long long c00 = 0, c01 = 0, c10 = 0, c11 = 0;
  for (int i = 0; i < n; i++) {
   if (s[i]=='0'&&z[i]=='0') c00++;
   else if(s[i]=='0'&&z[i]=='1') c01++;
   else if (s[i]=='1'&&z[i]=='0') c10++;
   else if (s[i]=='1'&&z[i]=='1') c11++;
  }
  long long xa = c10+c11,xb = c01+c10,xc = c01+c11,fa = xa*(n-xa),fb = xb*(n-xb),fc = xc*(n-xc),cnt_a = 0, cnt_b = 0, cnt_c = 0;
  if (k%2==1){
   cnt_a = cnt_b = cnt_c = ((1LL<<k)+1)/3;
  }
  else {
   cnt_b = ((1LL<<k)-1)/3;cnt_a = cnt_c = cnt_b+1;
  }
  unsigned long long ans = 0;
  ans += (unsigned long long)cnt_a * fa;
  ans += (unsigned long long)cnt_b * fb;
  ans += (unsigned long long)cnt_c * fc;

 cout << ans << "\n";
 }

 return 0;
}