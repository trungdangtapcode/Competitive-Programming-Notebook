#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	long int s[1005][1005];
	memset(s,0,sizeof(s));
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++){
			cin >> s[i][j];
			s[i][j] += s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		}	
	long int result = -1e6;
	for (int i = 1; i <= n-k+1; i++) 
		for (int j = 1; j <= n-k+1; j++)
			result = max(result,s[i+k-1][j+k-1]-s[i-1][j+k-1]-s[i+k-1][j-1]+s[i-1][j-1]);
	cout << result;
	return 0;
}
