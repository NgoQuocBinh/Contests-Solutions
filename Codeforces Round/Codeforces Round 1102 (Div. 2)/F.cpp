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
  for (int i = 0; i < n; i++) {
   cin >> h[i];
  }
  int M = 0;
  for (int i = 1; i < n; i++) {
   if (h[i]>h[M]) {
    M = i;
   }
  }
  vector<long long> A(n-1);
  for (int i = 0; i < n-1; i++) {
   A[i] = h[(M+1+i)%n];
  }
  auto compute_F = [](const vector<long long>& vec) {
   int N = vec.size();
   vector<int> nge(N);
   stack<int> st;
   for (int i = N-1; i >= 0;i--) {
    while (!st.empty()&&vec[st.top()]<= vec[i]) {
     st.pop();
    }
    nge[i] = st.empty()?N:st.top();
    st.push(i);
   }
   
   vector<long long> F(N+1,0);
   for (int i = N-1;i >= 0;i--) {
    F[i] = (long long)(nge[i]-i)*vec[i]+F[nge[i]];
   }
   return F;
  };

  vector<long long> F_A = compute_F(A); 
  vector<long long> B = A;
  reverse(all(B));
  vector<long long> F_B = compute_F(B); 
  vector<long long> ans(n);
  for (int k = 0; k < n; ++k) {
   long long f = F_A[k];
   long long g = 0;
   if (k>0) {
    g = F_B[n-1-k];
   }
   ans[(M+1+k)%n] = f+g;
  }
  for (int i = 0; i < n; i++) {
   cout << ans[i] << (i==n-1?"":" ");
  }
  cout << "\n";
 }

 return 0;
}