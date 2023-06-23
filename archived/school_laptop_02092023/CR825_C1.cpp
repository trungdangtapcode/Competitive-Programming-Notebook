#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> a, cnt;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		a.assign(n+1,0);
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		long long int res = 0; 
		for (int i = 1, j = 0; i <= n; i++){
			while (j<n&&a[j+1]>=j+1-i+1) j++;
			res += j-i+1;
//			cout << i << " " << j << endl;
		}
		cout << res << "\n";
	}
	return 0;
}
