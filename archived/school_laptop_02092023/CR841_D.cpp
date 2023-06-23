#include<bits/stdc++.h>

using namespace std;
int n, m, a[2000005], f[2000005];
int idx(int a, int b){
	return a*(m+2)+b; 
};
bool check(int l){
	for (int i = 0; i <= n; i++) f[idx(i,0)];
	for (int i = 0; i <= m; i++) f[idx(0,i)] = 0;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) f[idx(i,j)] = (a[idx(i,j)]<l) + f[idx(i-1,j)] + f[idx(i,j-1)] - f[idx(i-1,j-1)];
	bool res = 0;
	for (int i = 1; i + l -1 <= n; i++) for (int j = 1; j + l - 1 <= m; j++) res |= !(f[idx(i+l-1,j+l-1)]-f[idx(i-1,j+l-1)]-f[idx(i+l-1,j-1)]+f[idx(i-1,j-1)]);
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[idx(i,j)];
		int l = 1, h = n, m, res;
		while (l<=h){
			m = l+h>>1;
			if (check(m)){
				res = m;
				l = m+1;
			} else h = m-1;
		} 
		cout << res << "\n";
	}
	
	return 0;
}
