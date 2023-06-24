//the same: https://oj.vnoi.info/problem/fcb001_height

#include <bits/stdc++.h>

using namespace std;
int n;
vector <int> a, b;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	a.resize(n);
	b.resize(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a.begin(),a.end());
	for (int i = 0; i < n; i++){
		cout << lower_bound(a.begin(),a.end(),b[i])-a.begin()-1+1 << ' ';
	}
	
	return 0;
}
