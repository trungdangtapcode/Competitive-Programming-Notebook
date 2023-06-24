#include<bits/stdc++.h>

using namespace std;
int p, cha[100005];
int timcha(int x){
	return (cha[x]==x?x:cha[x]=timcha(cha[x]));
}
bool hop(int u, int v){
	int pu = timcha(u), pv = timcha(v);
	if (pu==pv) return false;
	cha[pu] = pv;
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> p;
	for (int i = 1; i <= 1e4; i++) cha[i] = i;
	while (p--){
		int x, y, t;
		cin >> x >> y >> t;
		if (t==1) hop(x,y);
		else cout << (timcha(x)==timcha(y)) << "\n";
	}
	
	
	return 0;
}
