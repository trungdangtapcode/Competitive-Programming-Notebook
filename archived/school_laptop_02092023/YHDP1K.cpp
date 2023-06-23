#include<bits/stdc++.h>

using namespace std;
#define int long long
int fct[200005], inv[200005], h, w, n, dp[2005];
typedef pair<int,int> ii;
vector<ii> a;
const int p = 1e9+7;

int nCr(int n, int r){
	return fct[n]*inv[r]%p*inv[n-r]%p;
}
int calc(int s, int t){
	if (a[s].first>a[t].first||a[s].second>a[t].second) return 0;
	int x = a[t].first-a[s].first+1, y = a[t].second-a[s].second+1;
	return (nCr(x+y-2,x-1));
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	fct[0] = fct[1] = inv[0] = inv[1] = 1;
	for (int i = 2; i <= 2e5; i++) fct[i] = fct[i-1]*i%p;
	for (int i = 2; i <= 2e5; i++) inv[i] = inv[p%i]*(p-p/i)%p;
	for (int i = 2; i <= 2e5; i++) inv[i] = inv[i]*inv[i-1]%p;
	
	cin >> h >> w >> n;
	a.assign(n,{0,0});
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	a.push_back({1,1});
	a.push_back({h,w});
	sort(a.begin(),a.end());
	n = a.size();
	for (int i = 0; i < n; i++){
		dp[i] = calc(0,i);
		for (int j = 1; j < i; j++) dp[i] = (dp[i]-dp[j]*calc(j,i)%p)%p;
	}
	cout << (dp[n-1]+p)%p;
	
	return 0;
}
