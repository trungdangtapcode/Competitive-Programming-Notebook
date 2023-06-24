#include<bits/stdc++.h>

using namespace std;
int n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		multiset<int> s;
		for (int i = 0, a; i < n; i++){
			cin >> a;
			s.insert(a);
		}
		int res =0;
		while (s.size()){
			int u = *s.begin();
			s.erase(s.find(u));
			while (s.find(u+1)!=s.end()) s.erase(s.find(++u));
			res++;
		}
		cout << res << "\n";
	}
	
	return 0;
}
