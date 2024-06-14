#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, k;
void solve(){
	cin >> n >> k;
	if (n==1){
		cout << k << "\n";
		return;
	}
	int tmp = __lg(k);
	tmp = (1<<tmp)-1;
	cout << tmp << " " << k-tmp << " ";
	for (int i = 3; i <= n; i++) cout << 0 << " ";
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

