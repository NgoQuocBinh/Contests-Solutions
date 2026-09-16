#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> l0, l1, l2, l3;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        bool div2 = (a % 2 == 0);
        bool div3 = (a % 3 == 0);
        
        if (div2 && div3) l0.push_back(a);
        else if (div2) l1.push_back(a);
        else if (div3) l2.push_back(a);
        else l3.push_back(a);
    }

    vector<int> result;

    if (l1.size() <= l2.size()) {
        for (int x : l0) result.push_back(x);
        for (int x : l1) result.push_back(x);
        for (int x : l3) result.push_back(x);
        for (int x : l2) result.push_back(x);
    } else {
        for (int x : l1) result.push_back(x);
        for (int x : l3) result.push_back(x);
        for (int x : l2) result.push_back(x);
        for (int x : l0) result.push_back(x);
    }

    for (int i = 0; i < n; ++i) {
        cout << result[i] << (i == n - 1 ? "" : " ");
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}