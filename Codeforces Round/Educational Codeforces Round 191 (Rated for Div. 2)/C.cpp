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

const int inf = 30000;

signed main(){
 IShowSpeed

 if(fopen(task".inp", "r")){
   freopen(task".inp", "r", stdin);
   freopen(task".out", "w", stdout);
 }

 int t;
 cin >> t;

 while(t--){
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  vector<vector<int>> dp(n + 1, vector<int>(n + 2, inf));
  vector<vector<int>> mx(n + 1, vector<int>(n + 2, -1));
  dp[0][0] = 0;
  mx[0][0] = 0;
  for (int i = 1; i <= n; i++) {
   char c = s[i - 1];
   for (int b = 0; b <= i; b++) {
    if (c == '(') {
     if (b > 0 && dp[i - 1][b - 1] != inf) {
      int v = dp[i - 1][b - 1];
      int d = mx[i - 1][b - 1];
      if (v < dp[i][b]) {
       dp[i][b] = v;
       mx[i][b] = d;
      } else if (v == dp[i][b]) {
       mx[i][b] = max(mx[i][b], d);
      }
     }
     if (dp[i - 1][b] != inf) {
      int v = dp[i - 1][b] + 1;
      int d = mx[i - 1][b] + 1;
      if (v < dp[i][b]) {
       dp[i][b] = v;
       mx[i][b] = d;
      } else if (v == dp[i][b]) {
       mx[i][b] = max(mx[i][b], d);
      }
     }
    } else {
     if (dp[i - 1][b + 1] != inf) {
      int v = dp[i - 1][b + 1] + 1;
      int d = mx[i - 1][b + 1];
      if (v < dp[i][b]) {
       dp[i][b] = v;
       mx[i][b] = d;
      } else if (v == dp[i][b]) {
       mx[i][b] = max(mx[i][b], d);
      }
     }
     if (b == 0 && dp[i - 1][0] != inf) {
      int v = dp[i - 1][0];
      int d = mx[i - 1][0];
      if (v < dp[i][0]) {
       dp[i][0] = v;
       mx[i][0] = d;
      } else if (v == dp[i][0]) {
       mx[i][0] = max(mx[i][0], d);
      }
     }
     if (dp[i - 1][b] != inf) {
      int v = dp[i - 1][b] + 1;
      int d = mx[i - 1][b] + 1;

      if (v < dp[i][b]) {
       dp[i][b] = v;
       mx[i][b] = d;
      } else if (v == dp[i][b]) {
       mx[i][b] = max(mx[i][b], d);
      }
     }
    }
   }
  }
  int best = inf;
  for (int b = 0; b <= n; b++) {
   best = min(best, dp[n][b]);
  }
  int need = min((int)best, k);
  int bal = -1;
  for (int b = 0; b <= n; b++) {
   if (dp[n][b] == best && mx[n][b] >= need) {
    bal = b;
    break;
   }
  }
  string ans(n, '0');

  int cur_bal = bal;
  int cur_del = need;
  for (int i = n; i >= 1; i--) {
   char c = s[i - 1];
   if (c == '(') {
    if (cur_bal > 0 &&dp[i - 1][cur_bal - 1] == dp[i][cur_bal] &&mx[i - 1][cur_bal - 1] >= cur_del) {
     cur_bal--;
     continue;
    }
    ans[i - 1] = '1';
    cur_del--;

   } else {
    if (dp[i - 1][cur_bal + 1] != inf &&dp[i - 1][cur_bal + 1] + 1 == dp[i][cur_bal] &&mx[i - 1][cur_bal + 1] >= cur_del) {
     cur_bal++;
     continue;
    }
    if (cur_bal == 0 &&dp[i - 1][0] == dp[i][0] &&mx[i - 1][0] >= cur_del) {
     continue;
    }
    ans[i - 1] = '1';
    cur_del--;
   }
  }
  cout << ans << '\n';
 }

 return 0;
}