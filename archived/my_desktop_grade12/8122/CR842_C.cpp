#include<bits/stdc++.h>

using namespace std;
int n, a[200005], b[200005], ra[200005], rb[200005], x[200005];
int solve(){
	cin >> n;
	set<int> s1, s2;
	for (int i = 1; i <= n; i++) s1.insert(i), s2.insert(i);
	for (int i = 1; i <= n; i++) a[i] = b[i] = ra[i] = rb[i] = 0;
	for (int i = 1; i <= n; i++){
		cin >> x[i];
	}
	for (int i = 1; i <= n; i++){
		if (s1.find(x[i])!=s1.end()){
			a[i] = x[i];
			ra[a[i]] = i;
			s1.erase(x[i]);
		} else {
			if (s2.find(x[i])==s2.end()) return cout << "NO\n", 0;
			b[i] = x[i];
			rb[b[i]] = i;
			s2.erase(x[i]);
		}
	}
	for (int i = 1; i <= n; i++) if (ra[i]!=0){
		if (*s2.begin()>i) return cout << "NO\n", 0;
		b[ra[i]] = *s2.begin();
		s2.erase(s2.begin());
	}
	for (int i = 1; i <= n; i++) if (rb[i]!=0){
		if (*s1.begin()>i) return cout << "NO\n", 0;
		a[rb[i]] = *s1.begin();
		s1.erase(s1.begin());
	}
	cout << "YES\n";
	for (int i = 1; i <= n; i++) cout << a[i] << " "; cout << "\n";
	for (int i = 1; i <= n; i++) cout << b[i] << " "; cout << "\n";
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	solve();
	int t; cin >> t;
	while (t--){
		solve();
	}
	
	return 0;
}
