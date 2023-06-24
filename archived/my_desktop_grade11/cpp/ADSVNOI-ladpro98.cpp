#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <math.h>

	
const int N = 2200;
using namespace std;
 
struct dsu {
    int lab[N];
    int root(int u)
        {return lab[u] <= 0 ? u : (lab[u] = root(lab[u]));}
    void join(int u, int v) {
        if (lab[u] > lab[v]) swap(u, v);
        if (lab[u] == lab[v]) lab[u]--;
        lab[v] = u;
    }
} DS;
int n, m;
 
int main() {
    ios :: sync_with_stdio(0);
    cin >> n >> m;
    int ans = m, u, v;
    for (int i = 0; i<= m; i++) {
        cin >> u >> v;
        int x = DS.root(u), y = DS.root(v);
        if (x != y) {DS.join(x, y); ans--;};
    }
    cout << ans;
    return 0;
}
