#include <vector>
#include <cstdio>
#include <functional>
#include <cassert>
using namespace std;

struct graph
{
    int n;
    vector<vector<int>> adj;
 
    graph(int n) : n(n), adj(n) {}
 
    void add_edge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    int add_node()
    {
        adj.push_back({});
        return n++;
    }
 
    vector<int>& operator[](int u) { return adj[u]; }
};
 
pair<vector<int>, pair<graph, vector<int>>> biconnected_components(graph &adj)
{
    int n = adj.n;

    vector<int> num(n), low(n), art(n), stk;
    vector<vector<int>> comps;

    function<void(int, int, int&)> dfs = [&](int u, int p, int &t)
    {
        num[u] = low[u] = ++t;
        stk.push_back(u);

        for (int v : adj[u]) if (v != p)
        {
            if (!num[v])
            {
                dfs(v, u, t);
                low[u] = min(low[u], low[v]);

                if (low[v] >= num[u])
                {
                    art[u] = (num[u] > 1 || num[v] > 2);

                    comps.push_back({u});
                    while (comps.back().back() != v)
                        comps.back().push_back(stk.back()), stk.pop_back();
                }
            }
            else low[u] = min(low[u], num[v]);
        }
    };

    for (int u = 0, t; u < n; ++u)
        if (!num[u]) dfs(u, -1, t = 0);

    // build the block cut tree
    function<pair<vector<int>, pair<graph, vector<int>>>()> build_tree = [&]()
    {
        graph tree(0);
        vector<int> id(n);
 
        for (int u = 0; u < n; ++u)
            if (art[u]) id[u] = tree.add_node();

        

        // for(auto &c : comps){
        //     for(auto &i: c) printf("%d ",i);
        //     printf("\n");
        // }

        // for(int i = 0; i < n; i++) printf("%d\n", art[i]);

 
        for (auto &comp : comps)
        {
            int node = tree.add_node();
            for (int u : comp)
                if (!art[u]) id[u] = node;
                else tree.add_edge(node, id[u]);
        }
 
        return make_pair(art, make_pair(tree, id));
    };
 
    return build_tree();
}

int p[100000], gle[200000], sko[200000][19];
bool odw[200000];
vector<vector<int>> kraw;

void dfs(int x, int g, int pop) {
    odw[x] = true;
    gle[x] = g;
    sko[x][0] = pop;
    for (int q = 1; q < 19; ++q)
        sko[x][q] = sko[sko[x][q-1]][q-1];
    for (int y : kraw[x])
        if (!odw[y])
            dfs(y, g + 1, x);
}

int lca(int x, int y) {
    if (gle[x] > gle[y])
        swap(x, y);
    for (int q = 18; q >= 0; --q)
        if (gle[y] > gle[x] && gle[sko[y][q]] >= gle[x])
            y = sko[y][q];
    assert(gle[x] == gle[y]);
    
    if (x == y)
        return x;

    for (int q = 18; q >= 0; --q)
        if (sko[x][q] != sko[y][q]) {
            x = sko[x][q];
            y = sko[y][q];
        }
    assert(sko[x][0] == sko[y][0]);
    return sko[x][0];
}

int odl(int x, int y) {
    int l = lca(x, y);
    return gle[x] + gle[y] - 2 * gle[l];
}

int Find(int x) {
    return p[x] = (x == p[x])? x : (p[x] = Find(p[x]));
}
void Union(int x, int y) {
    p[Find(x)] = Find(y);
}

int main() {
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; ++i)
        p[i] = i;
    graph G(n);

    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u; --v;
        G.add_edge(u, v);
        Union(u, v);
    }

    auto odp = biconnected_components(G);
    auto &art = odp.first;

    n = odp.second.first.n;
    kraw = odp.second.first.adj;
    auto &id = odp.second.second;

    // for(int i = 0; i < n; i++) printf("%d\n", id[i]);
    // for(auto &c : kraw){
    //     if(c.size() == 0) continue;
    //     for(auto &i : c) printf("%d ",i);
    //     printf("\n");
    // }
    
    for (int i = 0; i < n; ++i)
        if (!odw[i])
            dfs(i, 1, i);

    while (false) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        --u; --v; --w;
        if (Find(u) != Find(v) || Find(u) != Find(w) || (u == v && u != w)) {
            printf("NO\n");
            continue;
        }

        int leeway = 2 * int(art[w] != 0);

        u = id[u]; v = id[v]; w = id[w];

        if (odl(u, v) + leeway >= odl(u, w) + odl(v, w))
            printf("YES\n");
        else
            printf("NO\n");
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 19; j++) printf("%d ", sko[i][j]);
        printf("\n");
    }
    
}