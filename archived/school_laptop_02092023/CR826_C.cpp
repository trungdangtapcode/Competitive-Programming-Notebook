#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> a;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--){
		cin >> n;
		a.assign(n,0);
		for (int i = 0; i < n; i++) cin >> a[i];
		int res = 1e9;
		for (int i = 0, sum = 0; i < n; i++){
			sum += a[i];
			int thickness = i+1, cur = 0;
			for (int j = i+1, last = i; j < n; j++){
				cur += a[j];
				if (cur==sum) thickness = max(thickness,j-last), cur = 0, last = j;
			}
			if (cur==0) res = min(res,thickness);
		}
		cout << res << "\n";
	}
	
	return 0;
}
