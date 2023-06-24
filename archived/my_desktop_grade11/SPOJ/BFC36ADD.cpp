#include <bits/stdc++.h>

using namespace std;
int n, a[105];
bool solve(){
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
//	sort(a,a+n);
	for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++) for (int k = j+1; k < n; k++){
		if (a[i]+a[j]==a[k]||a[k]+a[i]==a[j]||a[j]+a[k]==a[i]) return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--){
		cout << (solve()?"YES":"NO") << '\n';
	}
}
