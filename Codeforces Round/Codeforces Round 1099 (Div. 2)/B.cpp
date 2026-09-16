/*NGO QUOC BINH*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define int long long
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define str string

#define pb push_back
#define eb emplace_back
#define ff first
#define ss second

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()

#define en '\n'

#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define No cout << "No\n"
#define yes cout << "yes\n"
#define no cout << "no\n"

#define debug(x) cerr << #x << " = " << x << endl;
#define bug(...) cerr << "[ "; _print(__VA_ARGS__); cerr << " ]\n";

#define fastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define file(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout);

#define TIME cerr << "\nTime elapsed: " << 1.0 * (clock() - Start) / CLOCKS_PER_SEC << " s\n";
#define this_is_the_end_of_the_fucking_code return 0;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
clock_t Start;

template<typename T>
using vec = vector<T>;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using maxpq = priority_queue<T>;
template<typename T>
using uset = unordered_set<T>;
template<typename T1, typename T2>
using umap = unordered_map<T1, T2>;
template<typename T>
using deq = deque<T>;
template<typename T>
using stc = stack<T>;
template<typename T>
using que = queue<T>;
template<typename T>
using mst = multiset<T>;
template<typename T>
using umst = unordered_multiset<T>;
template<typename T1, typename T2>
using mmap = multimap<T1, T2>;
template<typename T>
using graph = vector<vector<T>>;
template<typename T>
using matrix = vector<vector<T>>;
template<typename T>
bool maximize(T &a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

template<typename T>
bool minimize(T &a, T b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}

template<typename T>
void read(T &x){
    cin >> x;
}

template<typename T>
void print(T x){
    cout << x;
}

template<typename T>
void println(T x){
    cout << x << endl;
}

template<typename T>
void readVector(vector<T> &a){
    for(auto &x : a) cin >> x;
}

template<typename T>
void printVector(vector<T> &a){
    for(auto x : a) cout << x << ' ';
    cout << endl;
}

template<typename T>
T sumVector(vector<T> &a){
    T sum = 0;
    for(auto x : a) sum += x;
    return sum;
}

template<typename T>
T maxVector(vector<T> &a){
    return *max_element(all(a));
}

template<typename T>
T minVector(vector<T> &a){
    return *min_element(all(a));
}

template<typename T>
void sortAsc(vector<T> &a){
    sort(all(a));
}

template<typename T>
void sortDesc(vector<T> &a){
    sort(rall(a));
}

template<typename T>
void reverseVector(vector<T> &a){
    reverse(all(a));
}

template<typename T>
bool contains(vector<T> &a, T val){
    return find(all(a), val) != a.end();
}

template<typename T>
int lower(vector<T> &a, T val){
    return lower_bound(all(a), val) - a.begin();
}

template<typename T>
int upper(vector<T> &a, T val){
    return upper_bound(all(a), val) - a.begin();
}

template<typename T>
void compress(vector<T> &a){
    sort(all(a));
    a.erase(unique(all(a)), a.end());
}

template<typename T>
vector<T> prefixSum(vector<T> &a){
    vector<T> pref(sz(a) + 1, 0);
    for(int i = 0; i < sz(a); i++){
        pref[i + 1] = pref[i] + a[i];
    }
    return pref;
}

template<typename T>
vector<T> suffixSum(vector<T> &a){
    vector<T> suf(sz(a) + 1, 0);
    for(int i = sz(a) - 1; i >= 0; i--){
        suf[i] = suf[i + 1] + a[i];
    }
    return suf;
}

template<typename T>
T gcdTemplate(T a, T b){
    return __gcd(a, b);
}

template<typename T>
T lcmTemplate(T a, T b){
    return a / gcdTemplate(a, b) * b;
}

template<typename T>
T sqr(T x){
    return x * x;
}

template<typename T>
T cube(T x){
    return x * x * x;
}

template<typename T>
bool isOdd(T x){
    return x & 1;
}

template<typename T>
bool isEven(T x){
    return !(x & 1);
}

template<typename T>
T ceilDiv(T a, T b){
    return (a + b - 1) / b;
}

template<typename T>
T floorDiv(T a, T b){
    return a / b;
}

template<typename T>
T power(T a, T b){
    T res = 1;
    while(b){
        if(b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

template<typename T>
T modpow(T a, T b, T mod){
    a %= mod;
    T res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

template<typename T>
T random(T l, T r){
    return uniform_int_distribution<T>(l, r)(rng);
}

void _print(){ }

template<typename T, typename... V>
void _print(T t, V... v){
    cerr << t;
    if(sizeof...(v)) cerr << ", ";
    _print(v...);
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();

        return splitmix64(x + FIXED_RANDOM);
    }
};

/*start coding here !*/
ll t,n;
vll a;

void input(){
    cin >> t;
}

void solve(){
    cin >> n;
    a.assign(n,0);
    ll md = 0;
    for(ll i = 0; i < n ; i++){
        cin >> a[i];
        if(i>0){
            md = max(md,a[i-1]-a[i]);
        }
    }

    if(md==0){YES;return;}

    ll k = md;

    bool dp0 = true,dp1 = true;

    for(ll i = 1 ; i < n ; i++){
        bool next0 = false,next1 = false;
        if(dp0&&a[i-1]<=a[i]) next0 = true;
        if(dp1&&a[i-1]+k<=a[i]) next0 = true;
        if(dp0&&a[i-1]<=a[i]+k) next1 = true;
        if(dp1&&a[i-1]+k<=a[i]+k) next1 =true;

        dp0 = next0;
        dp1 = next1;

        if(!dp0&&!dp1) break;
    }
    if(dp0||dp1) YES;
    else NO;
}

signed main(){
    fastIO

    input();
    Start = clock();
    while(t--) solve();

    TIME
    this_is_the_end_of_the_fucking_code
}