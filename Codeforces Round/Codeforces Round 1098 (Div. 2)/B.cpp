#include <bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define chuongtrinhketthucoday return 0;
#define en "\n"

int t;

void input(){
    cin >> t;
}

void solve(){
    while(t--){
        long long n, x1, x2, k;
        cin >> n >> x1 >> x2 >> k;
        if(n <= 3){
            cout << 1 << en;
            continue;
        }
        long long diff = abs(x1 - x2);
        long long D = min(diff, n - diff);
        cout << D + k << en;
    }
}

int main(){
    fastIO

    input();
    solve();

    chuongtrinhketthucoday
}