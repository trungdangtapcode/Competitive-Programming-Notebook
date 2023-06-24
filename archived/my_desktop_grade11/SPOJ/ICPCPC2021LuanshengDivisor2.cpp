#include <bits/stdc++.h>

using namespace std;

long long int can3(long long int n){
	long long int l = 1, h = n, m;
	while (l<=h){
		m = (l+h)/2;
		if (m*m*m==n) {return m;}
		if (m*m*m>n){
			h = m-1;
		} else {
			l = m+1;
		}
	}
	return m;
}

long long int checkxx1(long long int n){
	long long int l = 1, h = n, m;
	while (l<=h){
		m = (l+h)/2;
		if (m*(m+1)==n) {return m;}
		if (m*(m+1)>n){
			h = m-1;
		} else {
			l = m+1;
		}
	}
	return -1;
}

void solve(){
	long long int n;
	cin >> n;
	deque<long long int> d;
	for (int k = 1; k < can3(n); k++) if (n%k==0) {
		if (n%(k+1)==0) cout << k <<" ";
		d.push_back(n/k);
	}
	long long int m = 0;
	while (!d.empty()){
		long long int x = d.back();
		d.pop_back();
		while (m*(m+1) < x) m++;
		//cout << x << endl;
		if (m*(m+1)==x) cout << m << " "; 
	}
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
