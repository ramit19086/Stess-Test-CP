#include <bits/stdc++.h>
using namespace std;
#define nl << '\n'
#define ll long long

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
ll randint(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r)(rng);
}
char randchar(char a, char b)
{
    return (char)a + randint(0, b - a);
}

int main(int argc, char *argv[])
{
    srand(atoi(argv[1]));/
    cout << 1 nl;
    ll n = randint(1,10);
    cout << n nl;
    for(int i = 0; i < n; i++)
        cout << randint(1,20) <<" ";
    cout nl;
    return 0;
}
