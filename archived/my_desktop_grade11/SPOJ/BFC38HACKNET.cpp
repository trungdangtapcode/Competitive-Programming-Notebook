#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a;
	for (int i = 0, x; i < n; i++) cin >> x, a.push_back(x);
	sort(a.begin(),a.end());
	cout << max((a[n-1]-a[0])*(a[n-2]-a[1]),(a[n-1]-a[1])*(a[n-2]-a[0]));
	
	return 0;
}
