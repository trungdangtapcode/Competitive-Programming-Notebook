#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> a;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--){
		cin >> n;
		a.assign(n,0);
		int s = 0;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			int tmp = 0;
			while (a[i]%2==0) tmp++, a[i] /= 2;
			s += tmp;
		}
		priority_queue<int> pq;
		for (int i = 1; i <= n; i++){
			int tmp = 0, x = i;
			while (x%2==0) tmp++, x/= 2;
			pq.push(tmp);
		}
		n -= s;
		int res = 0;
		for (;;){
			if (n<=0){
				cout << res << "\n";
				break;
			}
			if (pq.empty()){
				cout << -1 << "\n";
				break;
			}
			n -= pq.top();
			pq.pop();
			res++;
		}
	}
	
	return 0;
}
