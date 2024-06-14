#include<bits/stdc++.h>

using namespace std;

int n, a[5005], f[5005][5005], cost[5005][5005];

int main(){
	cin >> n;
	int total = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		for (int j = 1; j < i; j++) total += (a[j]>a[i]); 
	}
	for (int i = 1; i <= n; i++){
		int cur = 0;
		for (int j = i+1; j <= n; j++){
			cost[i][j] += cur;
			cur += (a[i]>a[j]?-1:1);
		}
	}
	for (int j = 1; j <= n; j++){
		int cur = 0;
		for (int i = j-1; i > 0; i--){
			cur += (a[j]<a[i]?-1:1);
			cost[i][j] += cur;
		}
	}
	
	for (int j = 1; j <= n; j++){
		for (int i = j-1; i; i--){
			f[i][j] = min({f[i+1][j-1],f[i+1][j],f[i][j-1],f[i+1][j-1]+cost[i][j]});
		}
	}
	cout << f[1][n]+total << "\n";
	
	return 0;
}
