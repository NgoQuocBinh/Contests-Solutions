#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) ((int)((x).size()))
#define pb push_back
#define fi first
#define se second

// bool isPallin(long long n){
//  string s = to_string(n);
//  string t = s;
//  reverse(all(t));
//  return s==t;
// }

signed main(){
 ios::sync_with_stdio(false), cin.tie(0);

 int t;
 cin >> t;
 
 while(t--){
  long long n;
  cin >> n;
  // for(long long i = 1 ; ; i++){
  //  for(long long j = 1 ; ; j++){
  //   if(i+j==n&&isPallin(i)&&j%12==0) cout << i << " " << j << "\n";
  //  }
  // }

  long long rem = n%12;
  long long a = 0;
  if(rem<=9) a = rem;
  else if(rem==11) a = 11;
  else{
   if(n==10){
    cout << "-1\n";
    continue;
   }
   a=22;
  }
  cout << a << " " << (n-a) << "\n";
 }

 return 0;
}