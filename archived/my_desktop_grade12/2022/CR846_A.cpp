#include<bits/stdc++.h>

using namespace std;
int n, a[100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		vector<int> ev, od;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			if (a[i]%2&&od.size()<3) od.push_back(i);
			if (a[i]%2==0&&ev.size()<3) ev.push_back(i);
		}
		if (od.size()==3){
			cout << "YES\n";
			for (int i: od) cout << i << " "; cout << "\n";
		} else if (od.size()&&ev.size()>=2){
			cout << "YES\n";
			cout << od[0] << " " << ev[0] << " " << ev[1] << "\n";
		} else cout << "NO\n";
	}
	
	return 0;
}
