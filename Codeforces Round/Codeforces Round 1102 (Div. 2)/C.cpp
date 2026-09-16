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
  int n;
  cin >> n;
  vector<long long> h(n);
  for (int i = 0; i < n; ++i) {
   cin >> h[i];
  }
  for (int k = 0; k < n; ++k) {
   vector<long long> R(n,0),L(n,0);
   long long curmx = 0;
   for (int step = 1; step < n; ++step) {
    int prev = (k+step-1)%n;
    int curr = (k+step)%n;
    curmx = max(curmx, h[prev]);
    R[curr] = curmx;
   }
   long long currmaxx = 0;
   for (int step = 1; step < n; ++step) {
    int curr = (k-step+n)%n;
    int pe = curr;
    currmaxx = max(currmaxx,h[pe]);
    L[curr] = currmaxx;
   }

   long long ans = 0;
   for (int i = 0; i < n; ++i) {
    if (i!=k) {
     ans += min(R[i],L[i]);
    }
   }
   cout << ans << (k==n-1?"":" ");
  }
  cout << "\n";
  }
 return 0;
}