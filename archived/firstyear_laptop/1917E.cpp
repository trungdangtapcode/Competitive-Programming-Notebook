#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e3+5;
int n, k, a[maxN][maxN];
void solve(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) a[i][j] = 0;
	if (k%2||k>n*n){
		cout << "No\n";
		return;
	}
	if (k==2||k==n*n-2){
		if (n==2){
			cout << "Yes\n1 0 0 1\n" << "\n";
		} else cout << "No\n";
		return;
	}
	if (k%4==2){
		a[2][1] = a[1][2] = a[3][1] = a[1][3] = a[2][3] = a[3][2] = 1;
		k -= 6;
	}
	for (int i = 1; i <= n; i += 2) for (int j = 1; j <= n; j+= 2){
		if (k==0) break;
		if (a[i][j]||a[i+1][j]||a[i][j+1]||a[i+1][j+1]) continue;
		a[i][j] = a[i+1][j] = a[i][j+1] = a[i+1][j+1] = 1;
		k -= 4;
	}
	cout << "Yes\n";
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	return 0;
}
