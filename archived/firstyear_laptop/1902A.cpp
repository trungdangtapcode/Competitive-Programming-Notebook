#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e3+5;
int n, res[maxN], a[maxN][maxN];
void solve(){
	cin >> n;
	string s;
	cin >> s;
	for (char c: s){
		if (c=='0'){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
