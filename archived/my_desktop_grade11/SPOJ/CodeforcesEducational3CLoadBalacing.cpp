#include <bits/stdc++.h>

using namespace std;
int n, res, s;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i], s += a[i];
	sort(a.begin(),a.end());
	
	for (int i = 0; i < n; i++){
		if (i<n-s%n) res += abs(a[i]-(s/n));
		else res += abs(a[i]-(s/n+1));
	}
	cout << res/2; //alway even
	
	return 0;
}
