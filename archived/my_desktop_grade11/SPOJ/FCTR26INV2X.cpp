#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	int n; cin >> n;
	int res = 0; vector<int> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
		for (int j = 0; j < i; j++) res += (a[j]>2*a[i]);
	}
	cout << res;
	
	return 0;
}
