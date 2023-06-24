#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
ii a[1000005]; //int dc r
double res = 0; //ko can phai long double
int n;
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	a[n] = a[0];
	for (int i = 0; i < n; i++) {
		res += (1.0*a[i].first*a[i+1].second-1.0*a[i].second*a[i+1].first);
	}
	cout << fixed << setprecision(2) << abs(res)/2.0;
	
	return 0;
}
