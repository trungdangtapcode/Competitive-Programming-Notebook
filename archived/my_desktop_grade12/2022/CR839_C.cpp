#include<bits/stdc++.h>

using namespace std;
int n, k;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> k >> n;
		int cur = 1;
		for (int i = 1; i <= k; i++){
			cout << cur << " ";
			if (cur+i+k-i-1<=n) cur += i; else cur++;
		}
		cout << "\n";
	}
	
	return 0;
}
