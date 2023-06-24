#include <bits/stdc++.h>

using namespace std;
int n, k, a, sum, mmax, t, need;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> t;
	while (t--){
		sum = 0; mmax = -1e5;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> a;
			sum += a;
			mmax = max(mmax,a);
		}
		need = mmax*n-sum;
		if (k>=need) cout << ((k-need)%n==0?"YES":"NO") << '\n';
		else cout << "NO" << '\n';
	}
	
	return 0;
}
