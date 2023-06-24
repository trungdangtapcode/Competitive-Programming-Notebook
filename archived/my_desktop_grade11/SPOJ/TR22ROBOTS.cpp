#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> eb;
vector <eb> a;
int dp[1000000];
long long int f[1000000];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	memset(dp,0,sizeof(dp));
	dp[0] = 0;
	memset(f,1,sizeof(f));
	
	cin >> n;
	for (int i = 0; i < n; i++){
		long long int x, l;
		cin >> x >> l;
		a.push_back({x+l,x-l});
	}
	sort(a.begin(),a.end());
	
	int result = 0;
	//f[0] = -1e9;
	for (int i = 0; i < n; i++){
//		int l = 0, h = result, m, key = a[i].second;
//		while (l<=h){
//			m = (l+h)/2;
//			if (f[m]==key) break;
//			if (f[m]>key){
//				h = m-1;
//			} else {
//				l = m+1;
//			}
//		}
		//dp[i] = lower_bound(f,f+1000000,a[i].second)-f;
		dp[i] = dp[lower_bound(f,f+i,a[i].second)-f]+1;
		cout << dp[i] << endl;
		//dp[i] = m+1;
    	//f[dp[i]] = a[i].first;
    	f[i] = a[i].first;
    	result = max(result, dp[i]);
	}
	//cout << dp[n-1];
		
	return 0;
}
