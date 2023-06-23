#include<bits/stdc++.h>

using namespace std;

int n, q, cnt[2], p, x;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--){
		cin >> n >> q;
		cnt[0] = cnt[1] = 0;
		long long int sum = 0;
		for (int i = 0, a; i < n; i++){
			cin >> a;
			cnt[a%2]++;
			sum += a;
		}
		while (q--){
			cin >> p >> x;
			sum += cnt[p]*x;
			if (x%2) cnt[!p] += cnt[p], cnt[p] = 0; 
			cout << sum << "\n";
		}
	}
	return 0;
}
