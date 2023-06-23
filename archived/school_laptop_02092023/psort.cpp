#include<bits/stdc++.h>

using namespace std;
int n, m;

int cha[100005];
int timcha(int x){
	if (cha[x]==x) return x;
	return cha[x] = timcha(cha[x]);
}
void hop(int u, int v){
	int pu = timcha(u), pv = timcha(v);
	if (pu==pv) return;
	cha[pu] = pv;
}

int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cha[i] = i;
	while (m--){
		int u, v;
		cin >> u >> v;
		if (u>v){
			cout << "No";
			return 0;
		}
		if (u+1==v) hop(u,v); //
	}
	for (int i = 2; i <= n; i++) if (timcha(1)!=timcha(i)){
		cout << "No";
		return 0;
	}
	cout << "Yes";
	
	return 0;
}
