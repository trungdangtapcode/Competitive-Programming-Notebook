#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int n, a[maxN], c[25];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int s = 0, cnt = 0;
	for (int i = 1; i <= n; i++) s = s|a[i];
	for (int i = 0; i < 20; i++) cnt += (s>>i&1);
	memset(c, 0,sizeof(c));
	int res = 0, num = 0;
	for (int i = 1, j = 0, last = 0; i <= n; i++){
		while (j<n&&num<cnt||j<i){
			j++;
			for (int k = 0; k < 20; k++){
				c[k] += (a[j]>>k&1);
				if (c[k]==1&&(a[j]>>k&1)) num++;
			};
		}
//		cout << i << ".." << j <<" " << cnt << "\n";
		if (num==cnt) res = max(res, j-i+1), last = i;
		else res = max(res, i-last+1);
		for (int k = 0; k < 20; k++){
			c[k] -= (a[i]>>k&1);
			if (c[k]==0&(a[i]>>k&1)) num--;
		};
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

