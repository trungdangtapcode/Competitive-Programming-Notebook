#include<bits/stdc++.h>

using namespace std;
int n, m;
vector<int> a, b;
long long int res;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	a.assign(n+1,-1e9-1);
	b.assign(m+1,-1e9-1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	for (int i = 1, j1 = 1, j2 = 1; i <= n; i++){
		while (j1<m&&a[i]>b[j1]) j1++;
		while (j2<=m&&a[i]>=b[j2]) j2++;
		j2--;
		if (a[i]==b[j1]&&a[i]==b[j2]) res += j2 - j1 + 1;
	}
	cout << res;
	
	return 0;
}
