#include <bits/stdc++.h>

using namespace std;
typedef pair<long long int, long long int> EB; //end, begin
vector <EB> a; 
int n;
int dp[1005]; //dp[n]<=dp[n+1]

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long int e, b;
		cin >> b >> e;
		a.push_back({e,b});
	}
	sort(a.begin(),a.end());
	dp[0] = 1;
	for (int i = 1; i < n; i++){
		dp[i] = dp[i-1];  
		for (int j = i; j >= 0; j--) if (a[j].first<=a[i].second) {
			dp[i] = max(dp[i],dp[j]+1);
			//cout << i << " " << j << " ss " << a[j].first << " "<<a[i].second<< endl; 
			break;
		}
		//cout << a[i].second << " " <<a[i].first<< " - " << dp[i]<< endl; 
	}
	cout <<dp[n-1];
	return 0;
}
