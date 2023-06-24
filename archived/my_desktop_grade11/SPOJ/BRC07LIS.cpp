#include<bits/stdc++.h>

using namespace std;

int main(){
	int last = -1e9-7, lastAdded = 0, n;
	long long int res = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(),a.end());
	for (int i = 0; i < n; i++){
		if (a[i]>last) res += lastAdded+1, lastAdded++;
		else res += lastAdded;
		last = a[i];
	}
	cout << res;
	
	return 0;
}
