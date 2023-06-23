#include<bits/stdc++.h>

using namespace std;

int cha[200005], len[200005], n, q, x, y, t, shift = -1;
int timcha(int x){
	int px = cha[x];
	if (px==x) return x;
	cha[x] = timcha(cha[x]);
	len[x] = (len[x]+len[px])%2;
	return cha[x];
}
void hop(int u, int v){
	int pu = timcha(u), pv = timcha(v);
	if (pu==pv) return;
	cha[pu] = pv;
	len[pu] = (len[u]+len[v]+1)%2;	
}

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cha[i] = i, len[i] = 0;
	while (q--){
		cin >> t >> x >> y;
		x = (x+shift)%n+1;
		y = (y+shift)%n+1;
		if (t==0){
			hop(x,y);
		} else {
			timcha(x); timcha(y);
			if (len[x]==len[y]||cha[x]!=cha[y]){
				cout << "YES\n";
				shift++;
			} else cout << "NO\n";
		}
	}
	return 0;
}
