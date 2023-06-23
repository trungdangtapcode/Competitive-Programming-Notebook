#include<bits/stdc++.h>

using namespace std;
int n, m;
vector<int> a, b, res;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	a.assign(n+1,-1e9-1);
	b.assign(m+1,-1e9-1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	for (int i = 1, j = 1; j <= m; j++){
		while (i<=n&&a[i]<b[j]) i++;
		i--;
		if (a[i]<b[j]) cout << i << " ";
	}
	
	return 0;
}
