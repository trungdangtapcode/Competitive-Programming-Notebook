#include <bits/stdc++.h>

using namespace std;
typedef pair<pair<long long int,long long int>,pair<long long int,long long int>> rec;
vector <rec> a;
vector <int> g[5505], gt[5505], comp;
stack <int> order;
vector <bool> used;
int n;

bool check(rec a, rec b){
	return !(a.first.first<b.second.first&&a.first.second>b.second.second //<=
			&&a.second.first>b.first.first&&a.second.second<b.first.second); //phu dich cho de
}

void dfs1(int u) {
    used[u] = true;
    for (int v : g[u]) {
        if (!used[v])
            dfs1(v);
    }
    order.push(u);
}

void dfs2(int u, int counter) {
    comp[u] = counter;
    for (int v : gt[u]) {
        if (comp[v] == -1)
            dfs2(v, counter);
    }
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	cin >> n;
	a.clear();
	for (int i = 0; i < n; i++){
		long long int x, y, h, w;
		cin >> x >> y >> w >> h;
		x *= 2;
		y *= 2;
		a.push_back({{x-w,y+h},{x+w,y-h}});
		a.push_back({{x-h,y+w},{x+h,y-w}});
	}
	for (int i = 0; i < 2*n; i++) for (int j = 0; j < 2*n; j++) if (i/2!=j/2) {
		if (!check(a[i],a[j])){
//			cout << "checked: " << i << " " << j << endl;
			g[i].push_back(j^1);
			gt[j^1].push_back(i);
		}
	}
//	for (int i = 0; i < 2*n; i++){
//		cout << i <<" ("<< a[i].first.first/2 << "," << a[i].first.second/2<<")("
//		<< a[i].second.first/2 << "," << a[i].second.second/2 <<"): ";
//		for (auto& it: g[i]) cout << it << " ";
//		cout << endl;
//	}
	
	//order.clear();
	used.assign(2*n,false);
	for (int i = 0; i < 2*n; i++) if (!used[i]) dfs1(i);
	comp.assign(2*n,-1);
	for (int i = 0, j = 0; i < 2*n; i++){
		if (comp[order.top()]==-1) dfs2(order.top(),j++);
		order.pop();
	}
//	for (int i = 0; i < 2*n; i++) cout << "comp[" << i << "] = " << comp[i] << endl;
	for (int i = 0; i < 2*n; i++) if (comp[i^1]==comp[i]) {
		cout << "No";
		return 0;
	}
	cout << "Yes" << '\n';
	for (int i = 0; i < 2*n; i+=2) cout << (comp[i]>comp[i^1]?"K":"Q");
	
	return 0;
}
