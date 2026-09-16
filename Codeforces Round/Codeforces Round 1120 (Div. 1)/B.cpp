#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define hashmap unordered_map
#define hashset unordered_set
#define pb push_back
#define ff first
#define ss second
#define en "\n"

const ll inf = 1e16;
int n;
vector<ll> a;
vector<int> p;

struct node
{
        bool leaf;
        ll sum, req, v, extra;
};

struct SegmentTree
{
        int n;
        vector<node> st;

        SegmentTree(int n)
        {
                this->n = n;
                st.resize(4 * n + 5);
        }

        ll query(int id, ll s)
        {
                if(s >= st[id].req) return 0;
                if(st[id].leaf) return 1;

                int l = id * 2;
                int r = id * 2 + 1;
                if(s >= st[l].req) return query(r, s + st[l].sum);

                return query(l, s) + st[id].extra;
        }

        void pull(int id)
        {
                int l = id * 2;
                int r = id * 2 + 1;

                st[id].leaf = false;
                st[id].sum = st[l].sum + st[r].sum;
                st[id].req = max(st[l].req, st[r].req - st[l].sum);
                if(st[l].v >= st[r].req) st[id].v = st[l].v + st[r].sum;
                else st[id].v = st[r].v;

                st[id].extra = query(r, st[l].v);
        }

        void build(int id, int l, int r)
        {
                if(l == r)
                {
                        st[id] = {1, a[l], a[l], a[l], 0};
                        return;
                }

                int mid = (l + r) >> 1;
                build(id * 2, l, mid);
                build(id * 2 + 1, mid + 1, r);

                pull(id);
        }

        void update(int id, int l, int r, int pos)
        {
                if(l == r)
                {
                        st[id] = {0, 0, -inf, -inf, 0};
                        return;
                }

                int mid = (l + r) >> 1;
                if(pos <= mid) update(id * 2, l, mid, pos);
                else update(id * 2 + 1, mid + 1, r, pos);

                pull(id);
        }
};

namespace subtask_full
{
        void solve()
        {
                SegmentTree st(n);
                st.build(1, 1, n);
                for(int i = 0 ; i < n ; i++)
                {
                        if(i > 0) st.update(1, 1, n, p[i]);

                        cout << st.query(1, 0) - 1;
                        cout << (i == n - 1 ? en : " ");
                }
        }
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        #define task "sample"
        if (fopen(task ".inp", "r"))
        {
                freopen(task ".inp", "r", stdin);
                freopen(task ".out", "w", stdout);
        }

        int t;
        cin >> t;
        while(t--)
        {
                cin >> n;
                a.resize(n + 1);
                p.resize(n + 1);
                for(int i = 1 ; i <= n ; i++) cin >> a[i];
                for(int i = 1; i <= n; i++) cin >> p[i];

                subtask_full::solve();
        }

        return 0;
}
