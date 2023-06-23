#include<bits/stdc++.h>

using namespace std;
int p[100005], pref[100005], n, m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	for (int i = 2; i <= 1e5; i++) p[i] = 1;
	for (int i = 2; i*i <= 1e5; i++) if (p[i]) for (int j = i*i; j <= 1e5; j += i) p[j] = 0;
	for (int i = 1; i <= 1e5; i++) for (int j = 2*i; j <= 1e5; j += i) p[j] -= p[i];
	for (int i = 1; i <= 1e5; i++) pref[i] = pref[i-1] + p[i];
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		long long int res = 0;
		for (int i = 1; i <= min(n,m); i++){
			int j = min({n/(n/i),m/(m/i),n,m});
			res += 1ll*(pref[j]-pref[i-1])*(n/i)*(m/i);
			i = j;
		} 
		cout << res << "\n";
	}
	return 0;
}
