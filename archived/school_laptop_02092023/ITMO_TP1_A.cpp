#include<bits/stdc++.h>

using namespace std;
int n, m;
vector<int> a, b, res;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	a.assign(n+1,1e9+1);
	b.assign(m+1,1e9+1);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	for (int i = 0, j = 0;;){
		if (min(a[i],b[j])==1e9+1) break;
		if (a[i]>b[j]) res.push_back(b[j++]); else res.push_back(a[i++]);
	}
	for (int x: res) cout << x << " ";
	
	return 0;
}
