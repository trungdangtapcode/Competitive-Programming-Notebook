#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct edge { int u, v, c; };
typedef vector<edge>::iterator iter;
struct pack {int s; iter it;};

bool operator<(const pack& a, const pack &b) {
    return a.s > b.s;
}

int dijkstra(int z, int t, const vector<edge> &E, const vector<iter> &s) {

    priority_queue<pack> heap;
    vector<int> f(s.size(), -1);
	f[0] = 0;

    if (s[z] != E.end()) heap.push({s[z]->c, s[z]});
    while (!heap.empty()) {
        pack x = heap.top();
        //if (x.it->v == t) return x.s;
		//if (x.s>=f[x.it->v]&&!f[x.it->v]){ cout << "cc" << endl; continue;}
		
        int u = x.it->v;
        if (f[u]==-1) f[u] = x.s; else f[u] = min(f[u],x.s);
        if (s[u] != E.end()) heap.push({x.s + s[u]->c, s[u]});

        while (f[heap.top().it->v]!=-1&&!heap.empty()) {
            iter it = heap.top().it;
            heap.pop();
            int u = it->u;
            while (it != E.end() && it->u == u) {
                if (f[it->v]==-1) {
                    heap.push({f[u] + it->c, it});
                    break;
                }
                it++;
            }
        }
    }
    for (int i = 0; i < 6; i++) cout << f[i] << " "; cout << endl;
    return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<edge> E(m);
    for (auto &e: E) {
        cin >> e.u >> e.v >> e.c;
        e.u--, e.v--;
    }

    sort(E.begin(), E.end(), [](const edge &a, const edge &b){
            return a.c<b.c;
        });
    stable_sort(E.begin(), E.end(), [](const edge &a, const edge &b){
            return a.u<b.u;
        });
    vector<iter> s(n, E.end());
    for (auto it=E.begin(); it != E.end(); it++) {
        if (s[it->u] == E.end()) s[it->u] = it;
    }

	cout << dijkstra(0, n-1, E, s) << '\n';
    return 0;
}
