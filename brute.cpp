#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <iomanip>
#include <tuple>
#include <list>
#include <bitset>
#include <queue>
#include <deque>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <chrono>
#include <stack>
#include <functional>
#include <utility>

using namespace std;
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

#define int long long
#define nl << "\n"
#define ll int
#define all(v) v.begin(), v.end()
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<char> vc;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpi;

template <typename T>
ostream &operator<<(ostream &stream, vector<T> &v)
{
    for (T &x : v)
        stream << x << " ";
    return stream;
}
template <typename T>
istream &operator>>(istream &stream, vector<T> &v)
{
    for (T &x : v)
        stream >> x;
    return stream;
}
template <typename T>
void sort(vector<T> &v)
{
    std::sort(v.begin(), v.end());
    return;
}
template <typename T>
T max(vector<T> &v)
{
    return *(max_element(v.begin(), v.end()));
}
template <typename T>
T min(vector<T> &v)
{
    return *(min_element(v.begin(), v.end()));
}

const int mod = 1e9 + 7;
const int inf = 1e18;
int mul(int a, int b) { return ((a % mod) * (b % mod)) % mod; }
int sub(int a, int b) { return (((a - b) % mod) + mod) % mod; }
int add(int a, int b) { return ((a + b) % mod); }

int power(int x, int y, int M)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % M;
        y >>= 1;
        x = (x * x) % M;
    }
    return res % M;
}
int mi(int x) { return power(x, mod - 2, mod); }
vi fac;
int nCr(int x, int r)
{
    if (x < r)
        return 0;
    return (fac[x] * ((mi(fac[r]) * mi(fac[x - r])) % mod)) % mod;
}

void solve()
{
    int a,b,v;
    cin>>a>>b>>v;
    int ans = 0;
    for(int i=a;i<=b;i++)
    {
        int temp = 0;
        for(int j = i;j<=b;j++)
        {
            temp|=j;
            if(temp<=v)
                ans = max(ans,j-i+1);
        }
    }
    cout<<ans nl;
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {

        solve();
    }
    return 0;
}
