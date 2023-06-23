#include<bits/stdc++.h>

using namespace std;
int n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		long long int res = 0;
		for (int i = 0, a; i < n; i++){
			cin >> a;
			res += a;
		}		
		deque<int> d;
		for (int i = 0, a; i < n; i++){
			cin >> a;
			d.push_back(a);
		}
		while (d.size()>1){
			if (d.back()>d.front()){
				res += d.front();
				d.pop_front();
			} else {
				res += d.back();
				d.pop_back();
			}
		}
		cout << res << "\n";
	}
	
	return 0;
}
