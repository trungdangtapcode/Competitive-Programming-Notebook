#include <bits/stdc++.h>

using namespace std;
int n, y, z, res = 0;
vector<int> a; //x

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> y >> z;
	for (int i = 0; i < n; i++) a[i] = abs(a[i]-z);
	y = abs(y-z);
	sort(a.begin(),a.end());
	for (int i = 0; i < n; i++){
		if (y<=a[i]) break;
		res++;
		y -= a[i];
	}
	cout << res;
	return 0;
}
