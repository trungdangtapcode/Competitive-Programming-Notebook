#include <bits/stdc++.h>

using namespace std;
int n, k, a[100005];
bool dp[100005], hasValue[100005];

bool getDP(int x){
//	if (x==0) return false;
//	if (hasValue[x]) return dp[x];
//	
//	for (int i = 0; i < n; i++) if (x>=a[i]) dp[x] |= !(getDP(x-a[i]));
//	hasValue[x] = true;
	
	for (int i = 0; i <= k; i++){
		for (int j = 0; j < n; j++){
			if (i>=a[j]) dp[i] |= !(dp[i-a[j]]); 
		}
	}
	
	return dp[x];
}

int main(){
	hasValue[0] = true;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << (getDP(k)?"First":"Second");
	
	return 0;
}
