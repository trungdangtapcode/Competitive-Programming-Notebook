#include<bits/stdc++.h>

using namespace std;
int n;
typedef pair<int,int> ii;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		vector<ii> primeFact;	
		for (int i = 2; i*i <= n; i++) if (n%i==0){
			int cur =0;
			while (n%i==0) n/= i, cur++;
			primeFact.push_back({cur,i});
		}
		if (n>1) primeFact.push_back({1,n});
		sort(primeFact.begin(),primeFact.end());
		int res = 0;
		for (int i = 1; i <= (*primeFact.rbegin()).first; i++){
			int cur = 1;
			for (int j = 0; j < primeFact.size(); j++) if (primeFact[j].first>=i) cur *= primeFact[j].second;
			res += cur;
		}
		cout << res << "\n";
	}
	
	return 0;
}
