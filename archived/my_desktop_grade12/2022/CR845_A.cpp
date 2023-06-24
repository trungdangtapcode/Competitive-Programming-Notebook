#include<bits/stdc++.h>

using namespace std;
int n, a[10005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int nTest; cin >> nTest;
	while (nTest--){
		cin >> n;
		for (int i =0 ; i < n; i++) cin >> a[i];
		int res = 0;
		for (int i = 0; i < n-1; i++) res += (a[i]%2==a[i+1]%2);
		cout << res << "\n";
	}
	
	return 0;
}
