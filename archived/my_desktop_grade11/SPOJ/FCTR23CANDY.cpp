#include <bits/stdc++.h>

using namespace std;
int n;
vector<long long int> a;
long long int sum = 0;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	a.push_back(0);
	for (int i = 1; i<= n; i++){
		long long int x;
		cin >> x;
		a.push_back(x+a[i-1]);
		sum += x;
	}
	
//	int k = lower_bound(a.begin(),a.end(),sum/2)-a.begin();
//	cout << abs(sum-2*a[k]);
	long long int res = 1e10;
	for (int i = 1; i<= n; i++){
		res = min(res,abs(sum-2*a[i]));
	}
	cout << res;
	
	return 0;
}
