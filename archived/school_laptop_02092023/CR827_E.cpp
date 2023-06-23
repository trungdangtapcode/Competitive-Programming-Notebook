#include <bits/stdc++.h>

using namespace std;
int n, q, k;
vector<long long int> a, mmax;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
	int t; cin >> t;
	while (t--){
		cin >> n >> q;
		a.assign(n+1,0);
		mmax.assign(n+1,0);
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			mmax[i] = max(mmax[i-1],a[i]);
			a[i] += a[i-1];
		}
		while (q--){
			cin >> k;
			cout << a[upper_bound(mmax.begin(),mmax.end(),k)-mmax.begin()-1] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
