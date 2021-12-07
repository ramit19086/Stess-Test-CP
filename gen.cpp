#include <bits/stdc++.h>
using namespace std;
#define nl << '\n'
#define ll long long

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll randint(ll l, ll r)
{
    return uniform_int_distribution<ll>(l, r)(rng);
}
char randchar(char a, char b)
{
    return (char)a + randint(0, b - a);
}
class DSU
{
private:
    int n;
    vector<int> rank, parent, size;
public:
    DSU(int n = 1) : n(n)
    {
        rank = vector<int>(n + 1), parent = vector<int>(n + 1), size = vector<int>(n + 1, 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }
    int Find(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = Find(parent[v]);
    }

    bool Union(int a, int b)
    {
        a = Find(a), b = Find(b);
        if (a == b)
            return 0;
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
        size[a] += size[b];
        return 1;
    }
    int Component_size(int a)
    {
        return size[Find(a)];
    }
};

vector<pair<int,int>> generate_tree(int n)
{
    DSU nodes(n);
    vector<int> parent(n + 1);
    for(int i = 2; i <= n; i++)
    {
        do
        {
            parent[i] = randint(1, n);
        } while (!nodes.Union(parent[i], i));     
    }
    vector<pair<int,int>> edges;
    for(int i = 2; i <= n; i++)
        edges.push_back({parent[i], i});
    return edges;
}

int main(int argc, char* argv[])
{
    
}
