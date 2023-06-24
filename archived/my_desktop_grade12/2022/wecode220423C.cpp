#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, a[500005];
vector<int> d[500005];

bool check(int d){
	map<int,bool> mp;
	for (int i = 1; i <= n; i++){
		if (mp.count(a[i]%d)) return 0;
		mp[a[i]%d] = 1;
	}
	return 1;
}

main(){
	cin >> n;
	bitset<500005> x, xx;
	bitset<500005> y = 1;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		x = x | (y<<a[i]);
	}	
	for (int i = 1; i <= n; i++){
		xx = xx | (x>>a[i]);
	}
	for (int i = 1; i <= 5e5; i++){
		for (int j = i*2; j <= 5e5; j += i) d[j].push_back(i);
	}
	for (int i = 1; i <= 5e5; i++){
		if (xx[i]){
			for (int dv: d[i]) xx[dv] = 1;			
		}
	}
	for (int i = 1; i <= 5e5; i++){
		if (!xx[i]){
			cout << i << "\n";
			return 0;
		}
	}
	

	return 0;
}


/*
#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, a[500005];

bool check(int d){
	map<int,bool> mp;
	for (int i = 1; i <= n; i++){
		if (mp.count(a[i]%d)) return 0;
		mp[a[i]%d] = 1;
	}
	return 1;
}

main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}	
	int l = 1, h = 1e9, m, res = 0;
	while (l<=h){
		m = (l+h)/2;
		if (check(m)){
			res = m;
			h = m-1;
		} else l = m+1;
	}
	cout << res;

	return 0;
}
*/
