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
	priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
	for (int k = 1; k <= can3(n); k++) {
		if (n%(k*(k+1))==0) pq.push(k);
		if (n%k==0) if (checkxx1(n/k)!=-1) pq.push(checkxx1(n/k));
	}
	if (pq.empty()) {cout << -1 << endl; return;}
	long long int last = 0;
	while (!pq.empty()){
		if (pq.top()!=last) cout << pq.top() << " ";
		last = pq.top();
		pq.pop();
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
