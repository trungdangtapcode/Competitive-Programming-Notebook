#include<bits/stdc++.h>

using namespace std;
const char s[] = {'a','e','i','u','o'};
int n;
void solve(){
	cin >> n;
	int c = n/5;
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < c; j++) cout << s[i];
		if (i<n%5) cout << s[i];
	}
	cout << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

