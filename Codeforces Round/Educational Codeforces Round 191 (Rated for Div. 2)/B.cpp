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

signed main(){
 IShowSpeed

 if(fopen(task".inp", "r")){
   freopen(task".inp", "r", stdin);
   freopen(task".out", "w", stdout);
 }

 int t;
 cin >> t;

 while(t--){
  int n;
  cin >> n;
  vector<int> ans;

  for(int i = 1 ; i <= n ; i++) ans.pb(i);
  for(int i = 1; i <= n ; i++) ans.pb(i);
  for(int i = 2 ; i <= n ; i++) ans.pb(i);
  ans.pb(1);
  for(int i = 1 ; i <= n ; i++) ans.pb(i);
  for(int i = 0  ;i < sz(ans) ; i++){
   if(i) cout << " ";
   cout << ans[i];
  }
  cout << "\n";
 }

 return 0;
}