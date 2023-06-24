#include <bits/stdc++.h>

using namespace std;
long long int n;

bool check(long long int x){
	long long int l = 1, h = 2000000000, m;
	while (l<=h){
		m = (l+h)/2;
		if (m*m == x) return true;
		if (m*m>x) h = m-1; else l = m + 1;
	}
	return (m*m==x);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--){
		cin >> n;
		cout << (check(n)) << '\n';
	}
	
	return 0;
}
