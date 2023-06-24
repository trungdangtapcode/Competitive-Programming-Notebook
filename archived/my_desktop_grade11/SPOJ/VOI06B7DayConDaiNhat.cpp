#include <bits/stdc++.h>

using namespace std;

int n, minp[100005];
vector<pair<long long int, int>> a;
long long int x, p;

int main(){
	cin >> n >> p;
	a.push_back({0,0});
	for (int i = 1; i <= n; i++) {
		cin >> x;
		x += a[i-1].first;
		a.push_back({x,i});
	}
	sort(a.begin(),a.end());
	for (int i = 0; i <= n; i++){
		if (i > 0) minp[i] = min(minp[i-1],a[i].second); else minp[0] = a[0].second;
	}
	
	for (int i = 0; i <= n; i++) cout << " {"<< a[i].first << ","<< a[i].second << "} ";
	
	int j = 0, res = -1;
	for (int i = 0; i <= n; i++){
		while (a[i].first-a[j].first>=p) j++;
		//cout << j <<
		if (j>0) res = max(res,i-minp[j-1]);
	}
	cout << res;
	
	
	
	
	return 0;
}
