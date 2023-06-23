#include<bits/stdc++.h>

using namespace std;

int n, q;
vector<long long> a;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	a.assign(n+1,0);
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a.begin()+1,a.end(),[](long long a, long long b){
		return a>b;
	});
	for (int i = 1; i <= n; i++) a[i] += a[i-1];
	while (q--){
		int c, k;
		long long res = 0;
		cin >> c >> k;
		res += a[c] + a[c/(k+1)];
		cout << res << "\n";
	}
	

	return 0;	
}
