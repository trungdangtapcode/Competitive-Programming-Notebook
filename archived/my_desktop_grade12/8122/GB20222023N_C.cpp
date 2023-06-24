#include<bits/stdc++.h>

using namespace std;
int n, t, cnt[1005];
long long a[1005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		map<long long, bool> m;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			if (m.count(a[i])) m[-1] = 1;
			m[a[i]] = 1;
		}
		if (m.count(-1)){
			cout << "NO\n";
			continue;
		}
		bool res = true;
		for (int i = 2; i <= n/2; i++){
			for (int j = 0; j < i; j++) cnt[j] = 0;
			for (int j = 0; j < n; j++) cnt[a[j]%i]++;
			if (*min_element(cnt,cnt+i)>=2){
				res = false;
				break;
			}
		}
		cout << (res?"YES\n":"NO\n");
	}
	
	return 0;
}
