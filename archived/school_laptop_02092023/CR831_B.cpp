#include<bits/stdc++.h>

using namespace std;
int n;
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		long long int mmax = -1e9, sum = 0;
		for (int i = 0, a, b; i < n; i++){
			cin >> a >> b;
			if (a<b) swap(a,b);
			mmax = max(mmax,1ll*a);
			sum += b;
		}
		cout << 2*(mmax+sum) << "\n";
	}
	return 0;
}
