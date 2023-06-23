#include<bits/stdc++.h>

using namespace std;
int n;
map<int,bool> m;
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
	int t; cin >> t;
	while (t--){
		cin >> n;
		m.clear();
		bool res = true;
		for (int i = 0, a; i < n; i++){
			cin >> a;
			if (m.count(a)) res = false;
			m[a] = true;	
		}
		cout << (res?"YES\n":"NO\n");
	}
	
	return 0;
}
