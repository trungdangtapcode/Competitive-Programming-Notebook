#include<bits/stdc++.h>

using namespace std;
int n, a[100005];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	map<int,int> s;
	for (int i = 1; i <= n; i++){
//		s.insert(a[i]);
		s[a[i]]++;
	}
	if (s.size()==1) cout << "Yes\n";
	else {
		if (s.size()==2&&(s[a[1]]==n/2||s[a[1]]==n-n/2)) cout << "Yes\n";
		else cout << "No\n";
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
