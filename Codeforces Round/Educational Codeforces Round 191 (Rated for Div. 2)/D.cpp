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

// void bcheck(){
//  int t;
//  cin >> t;

//  while(t--){
//   int n;
//   cin > n;
//   vector<int> a(n);
//   for(int i = 0 ; i < n ; i++) cin >> a[i];

//   int cnt = 0;
//   for(int i= 1 ; i < n ; i++){
//    if(a[i]!=a[i-1]) cnt++;
//   }
//   cout << ((ceil(cnt/2))>1?"NO\n":"YES\n");
//  }
// }

signed main(){
 IShowSpeed

 if(fopen(task".inp", "r")){
   freopen(task".inp", "r", stdin);
   freopen(task".out", "w", stdout);
 }

 int t;
 cin >> t;

 while (t--) {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  vector<tuple<int,int,int>> bl;
  int st = 0;

  for(int i = 1; i < n; i++){
   if (a[i] != a[i - 1]) {
    bl.push_back({a[st], st, i - 1});
    st = i;
   }
  }
  bl.push_back({a[st], st, n - 1});
  map<int,int> cnt;
  for(auto &b : bl){
   cnt[get<0>(b)]++;
  }

  int B = sz(bl),U = sz(cnt);
  if(B==U){
   cout << "YES\n";
   continue;
  }
  if(B-U > 4){
   cout << "NO\n";
   continue;
  }

  unordered_set<int> S;
  for(auto &p : cnt){
   if(p.second > 1) S.insert(p.fi);
  }

  unordered_set<int> V;
  for(auto &b : bl){
   int val = get<0>(b),l = get<1>(b),r = get<2>(b);
   if (S.count(val)) {
    V.insert(l);
    V.insert(r);
    if (l - 1 >= 0) V.insert(l - 1);
    if (r + 1 < n) V.insert(r + 1);
   }
  }

  vector<int> ca(all(V));
  sort(all(ca));
  bool found = false;
  for (int ii = 0; ii < sz(ca); ii++) {
   for (int jj = ii + 1; jj < sz(ca); jj++) {
    int i = ca[ii];
    int j = ca[jj];
    set<int> ah;
    if (i-1 >= 0) ah.insert(i - 1);
    if (i<n - 1) ah.insert(i);
    if (j-1 >= 0) ah.insert(j - 1);
    if (j<n - 1) ah.insert(j);
    int old = 0;
    for(int k : ah){
     if(a[k] != a[k + 1]) old++;
    }

    swap(a[i], a[j]);
    int newt = 0;
    for(int k : ah){
     if(a[k] != a[k + 1]) newt++;
    }

    if(B-old+newt == U){
     found = true;
     swap(a[i],a[j]);
     break;
    }
    swap(a[i],a[j]);
   }
   if(found) break;
  }

  cout << (found ? "YES\n" : "NO\n");
 }

 return 0;
}