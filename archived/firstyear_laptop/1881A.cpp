#include<bits/stdc++.h>

using namespace std;
int n, m;
string s, t;
void solve(){
	cin >> n >> m >> s >> t;
//	if (s.find(t)!=string::npos){
//		cout << 0 << "\n";
//		return;
//	}
//	int res = n;
//	for (int i = n-1; i >= 0; i--) if (n-i<=m&&s.substr(i,n-i)==t.substr(0,n-i)){
//		res = i;
//	}
//	cout << m-(n-res) <<"\n";
	for (int i = 0; i<2||s.length() <= 4*m; i++){
		if (s.find(t)!=string::npos){
			cout << i << "\n";
			return;
		}
		s += s;
	}
	cout << -1 << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

