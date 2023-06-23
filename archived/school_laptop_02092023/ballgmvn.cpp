#include<bits/stdc++.h>

using namespace std;
int n;
typedef pair<int,int> ii;
ii x[1005],	y[1005];
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> x[i].first >> x[i].second;
	}
	for (int i = 1; i <= n; i++){
		cin >> y[i].first >> y[i].second;
	}
	for (int i = 1;i <= n; i++){
		map<ii,int> mp;
		for (int j = 1; j <= n; j++){
			int a = y[j].first-x[i].first, b = y[j].second-x[i].second, g = __gcd(a,b);
			a /= g, b /= g;
			if (mp.count({a,b})) return cout << i << " " << n+j << " " << n+mp[{a,b}], 0;
			mp[{a,b}] = j;
		}
	}
	for (int i = 1;i <= n; i++){
		map<ii,int> mp;
		for (int j = 1; j <= n; j++){
			int a = x[j].first-y[i].first, b = x[j].second-y[i].second, g = __gcd(a,b);
			a /= g, b /= g;
			if (mp.count({a,b})) return cout << n+i << " " << j << " " << mp[{a,b}], 0;
			mp[{a,b}] = j;
		}
	}
	cout << -1;
	
	return 0;
}
