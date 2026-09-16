#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define chuongtrinhketthucoday return 0;
#define en "\n"
int t,n;

void input(){
    cin >> t;
}

void solve(){
    cin >> n;
    int c0 = 0, c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        if (x == 0) c0++;
        else if (x == 1) c1++;
        else c2++;
    }
    int pairs = min(c1, c2);
    int rem = abs(c1 - c2);
    cout << c0 + pairs + rem / 3 << '\n';
}

int main(){
    fastIO

    input();
    while(t--) solve();

    chuongtrinhketthucoday
}