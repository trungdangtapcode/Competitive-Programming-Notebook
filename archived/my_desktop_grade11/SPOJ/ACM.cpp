#include <bits/stdc++.h>

using namespace std;
typedef pair <int, pair <int , int>> id;
id a[2*400005];
int n;
int main(){
	cin >> n;
	for (int i = 0; i < 2*n; i++){
		cin >> a[i].second.first >> a[i].second.second;
		a[i].first = a[i].second.first - a[i].second.second;
	}
	sort(a,a+2*n);
	int res = 0;
	for (int i = 0; i < n; i++){
		res += a[i].second.first + a[i+n].second.second;
	}
	cout << res;
	
	return 0;
}
