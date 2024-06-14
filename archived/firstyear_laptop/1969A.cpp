#include<bits/stdc++.h>

using namespace std;
int n, p[105], q[105];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> p[i];
	}
	for (int i = 1; i <= n; i++){
		if (p[p[i]]==i){
			cout << 2 << "\n";
			return;
		}
	}
	cout << 3 << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

