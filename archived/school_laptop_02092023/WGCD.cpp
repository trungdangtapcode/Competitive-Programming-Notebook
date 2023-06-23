#include<bits/stdc++.h>

using namespace std;
int t, h;
long long int w[100005], pref[100005];

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> t >> h;
	for (int i = 1; i <= h; i++) cin >> w[i];
	for (int i = 1; i <= h; i++) for (int j = 2*i; j <= h; j += i){
		w[j] -= w[i];	
	}
	for (int i = 1; i <= h; i++) pref[i] = pref[i-1] + w[i];
//	for (int i = 1; i <= h; i++) cout << w[i] << " "; cout << endl;
	
	while (t--){
		int n, m;
		cin >> n >> m;
		long long int res = 0;
		if (n<m) swap(n,m); //
	//	for (int i = 1; i <= m; i++){ 
	//		res += 1ll*w[i]*(n/i)*(m/i);
	//		cout << i << " " << n/i << " " << m/i << " = " << w[i]*(n/i)*(m/i) << endl;
	//	}
		for (int i = 1; i <= m;){
			int j = min({n/(n/i),m/(m/i),m});
	//		cout << i << " " << j << " = " << w[i]*(n/i)*(m/i) << "*" << j-i << endl;
	//		res += 1ll*(j-i)*w[i]*(n/i)*(m/i);
			res += 1ll*(pref[j]-pref[i-1])*(n/i)*(m/i);
			i = j+1;
		}
		cout << res << "\n";
	}
	return 0;
}
