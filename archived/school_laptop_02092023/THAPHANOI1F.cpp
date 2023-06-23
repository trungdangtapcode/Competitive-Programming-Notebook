#include<bits/stdc++.h>

using namespace std;
int n, g[4][4];
string res;
void build(int k, int s, int t, int tmp){
	if (k==1){
		res.push_back((char	)(s-1+'A'));
		res.push_back((char)(t-1+'A'));
		res.push_back('\n');
		return;
	}
	if (g[s][t]){
		build(k-1,s,t,tmp);
		build(k-1,t,tmp,s);
		build(1,s,t,tmp);
		build(k-1,tmp,s,t);
		build(k-1,s,t,tmp);
	} else {
		build(k-1,s,tmp,t);
		build(k-1,tmp,t,s);
		build(1,s,tmp,t);
		build(k-1,t,s,tmp);
		build(1,tmp,t,s);
		build(k-1,s,tmp,t);
		build(k-1,tmp,t,s);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= 3; i++) for (int j = 1; j <= 3; j++) cin >> g[i][j];
	if (n==1){
		if (g[1][3]) cout << "1\nAC";
		else cout << "2\nAB\nBC";
		return 0;
	}
	build(n,1,3,2);
	cout << res.size() << "\n";
	cout << res;
	return 0;
}
