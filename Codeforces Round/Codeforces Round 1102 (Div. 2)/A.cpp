#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) ((int)((x).size()))
#define pb push_back
#define fi first
#define se second

signed main(){
 ios::sync_with_stdio(false), cin.tie(0);

 int t;
 cin >> t;

 while(t--){
  int n;
  cin >> n;
  vector<int> b(n);
  for(int i = 0 ; i < n ; i++){
   cin >> b[i];
  }

  sort(all(b),greater<int>());

  bool ok = true;
  for(int i = 2 ; i < n ; i++){
   if(b[i-2]%b[i-1]!=b[i]){
    ok = false;
    break;
   }
  }
  
  if(ok){
   cout << b[0] << " " << b[1] << "\n";
  }
  else{
   cout << "-1\n";
  }
 }

 return 0;
}