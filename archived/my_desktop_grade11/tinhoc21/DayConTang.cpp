#include <bits/stdc++.h>

using namespace std;
vector <long long int> a; 
int n;
int dp[1005]; //dp[i] so luong tang dai nhat, ket thuc = a[i] (de de dang truy hoi) => ans = max(dp[i]) 
//~~dp[n]<=dp[n+1]~~ (kho truy hoi vl nhung dp[n] la ket qua luon)

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long int x;
		cin >> x; //cai nay cx quen
		a.push_back(x);
	}
	for (int i = 0; i < n; i++){
		dp[i] = 0; //0 both
		for (int j = i; j >= 0; j--) if (a[j]<=a[i]) {
			dp[i] = max(dp[i],dp[j]+1);
		}
		//cout << a[i].second << " " <<a[i].first<< " - " << dp[i]<< endl; 
	}
	//for (int i = 0; i < n; i++) cout <<dp[i]<< " ";
	int result = 0;
	for (int i = 0; i < n; i++) result = max(result,dp[i]); 
	cout << result;
	return 0;
}
