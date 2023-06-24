#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
string s, a[15];
int dp[105], n;
ii trace[105];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> s >> n;
		s = "#" + s;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 1; i < s.length(); i++) dp[i] = 1e9, trace[i] = {-1,-1};
		for (int i = 1; i < s.length(); i++){
			for (int j = 0; j < n; j++){
				if (s.substr(i,min(a[j].length(),s.length()-i+1))==a[j]){
					for (int p = i; p <= i+a[j].length()-1; p++) if (dp[p] > dp[i-1]+1){
						dp[p] = dp[i-1]+1;
						trace[p] = {j,i-1};
					}
				}	
			}
		}
		if (dp[s.length()-1]!=1e9){
			cout << dp[s.length()-1] << "\n";
			int x = s.length()-1;
			while (x!=0){
				cout << trace[x].first+1 << " " << trace[x].second+1 << "\n";
				x = trace[x].second;
			}
		} else cout << -1 << "\n";
	}
	return 0;
}
