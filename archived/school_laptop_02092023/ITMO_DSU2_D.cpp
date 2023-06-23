#include<bits/stdc++.h>

using namespace std;
int n, q, x, cha[300005], depth[300005], a, b, c, p;
vector<pair<char,int>> query;

int timcha(int x){
	int px = cha[x];
	if (px==x) return x;
	cha[x] = timcha(px);
	depth[x] += depth[px];
	return cha[x];
}
void hop(int u, int v){
	int pu = timcha(u), pv = timcha(v);
	if (pu==pv) return;
	cha[pu] = pv;
	depth[pu]++;
}

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	cin >> n >> q;
	for (int i = 1; i <= n+1; i++) cha[i] = i;
	while (q--){
		cin >> p;
		if (p==1){
			cin >> a >> b;
			hop(a,b);
		} else {
			cin >> c;
			timcha(c);
			cout << depth[c] << "\n";
		}
	}
	
	return 0;
}
