#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e5+2;
int n, a[maxN], b[maxN], c[maxN], cnt[6], sum, dp[115][maxN*5+5];
int rescnt[6], res[maxN]; 

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) c[i] = abs(a[i]-b[i]), cnt[c[i]]++, sum += c[i];
	
	int T = 21;
	memset(dp,-1,sizeof(dp));
	dp[0][0] = 0;
	for (int i = 1; i <= 5; i++){
		for (int j = 0; j < T; j++){
			int x = 0, idx = (i-1)*T+j+1;
			if ((1<<j+1)-1<=cnt[i]){
				x = i<<j;
			} else if (j&&((1<<j)-1<=cnt[i])) x = (cnt[i]-(1<<j)+1)*i;
//			cout << x <<"\n";
			for (int k = 0; k <= sum/2; k++){
				if (dp[idx-1][k]!=-1){
					dp[idx][k] = k;
					continue;
				}
//				cout << x << "s\n";
//				if (k==1&&idx==1) cout << dp[idx-1][k-x] << "hi\n";
				if (x>k||dp[idx-1][k-x]==-1) continue;
				dp[idx][k] = k-x; 
			}
		}
	}
//	cout << dp[1][1] << "\n";
//	cout << "sum = " << sum << "\n";
//	for (int i = 1; i <= 10; i++){
//		cout << i << " = " << dp[5*T][i] << "\n";
//	}
	
	int nres;
	for (nres = sum/2; nres; nres--) if (dp[5*T][nres]!=-1) break; 
	
	cout << sum-2*nres << " \n";
	for (int idx = 5*T, last = nres; idx; idx--){
		int u = dp[idx][nres];
		if (idx%T==1) rescnt[idx/T+1] = (last - u)/(idx/T+1), last = u;
		nres = u;
	}
//	for (int i = 1; i <= 5; i++) cout << rescnt[i] << " ";
	vector<int> v;
	for (int i = 1; i <= n; i++){
		int take = 0;
		if (rescnt[c[i]]){
			take = 1;
			rescnt[c[i]]--;
		}
		if (take^(a[i]>b[i])) v.push_back(i); 
	}
	cout << v.size() << " ";
	for (int &x: v) cout << x << " ";
	
	return 0;
}
