#include<bits/stdc++.h>

using namespace std;
#define int long long
int k, n, m, cnt0;
vector<int> a, ps, ng;

bool check(int x){
	int cnt = 0; //(x>=0)*cnt0*n
	int j = n-1;
	for (int y: ps){
		while (j<n-1&&a[j]*y<=x) j++;
		while (j>0&&a[j]*y>x) j--;
		if (a[j]*y<=x) cnt+=j+1;
	}
	j = 0;
	for (int y: ng){
		while (j>0&&a[j]*y<=x) j--;
		while (j<n-1&&a[j]*y>x) j++;
		if (a[j]*y<=x) cnt += n-1-j+1;
	}
//	for (int i = 0; i < n; i++){
//		for (auto y: ps) if (a[i]*y<=x) cnt++;
//		for (auto y: ng) if (a[i]*y<=x) cnt++;
//	}
//	cout << cnt;
	return cnt>=k;
}

main(){
	cin >> k;
	cin >> m;
	for (int i = 0, x; i < m; i++){
		cin >> x;
		if (x>=0) ps.push_back(x);
		else ng.push_back(x);
	}
	cin >> n;
	a.assign(n,0);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	sort(ps.begin(),ps.end());
	sort(ng.begin(),ng.end());
	
//	for (int i = -1e3; i <= 1e3; i++){
//		if (check(i)){
//			cout << i;
//			return 0;
//		}
//	}	
//	n = n/0;
//	check(1);
	int l = -2e18, h = 2e18, m, res = 6969;
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
