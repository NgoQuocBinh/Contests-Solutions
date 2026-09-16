#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        int open = count(s.begin(), s.end(), '(');
        int close = n - open;

        if (open == close)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}