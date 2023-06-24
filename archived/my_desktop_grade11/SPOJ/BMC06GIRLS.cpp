#include <bits/stdc++.h>

using namespace std;
int m, n;
long long int k;
vector<long long int> a,s;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> m >> n >> k;
	a.push_back(0);
	for (int i = 0; i< m; i++) {
		long long int x;
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	s.assign(m+5,0);
	for (int i = 1; i <= m; i++){
		s[i] = s[i-1] + a[i];
	}
//	for (int i = 1; i <= m; i++){
//		cout << s[i] << " "; 
//	}
	long long int res = -2;
	for (int i = 1; i <= m-n+1; i++){
		if (a[i+n-1]-a[i]<=k) res = max(res,s[i+n-1]-s[i-1]);//, cout << i<< " "<< endl;
	}
	cout << res;
		
	return 0;
}
