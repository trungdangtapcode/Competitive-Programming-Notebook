#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> button, dp, trace;
const int cost[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	button.assign(m,0);
	for (int i = 0; i < m; i++){
		cin >> button[i];
	}
	sort(button.begin(),button.end());
	
	dp.assign(n+1,-1e9); trace.assign(n+1,-1);
	dp[0] = 0;
	for (int i = 1; i <= n; i++){
		for (auto num: button) if (i-cost[num]>=0){
			if (i==n&&num==0&&n!=cost[0]) continue; //anti so them cuoi la so 0 nhung ko loai truong hop chi co so 0
			if (dp[i]<=dp[i-cost[num]]+1){
				dp[i] = dp[i-cost[num]]+1;
				trace[i] = num;
			}
		}
	}
	
//	for (int i = 0; i <= n; i++) cout << i << " = " << dp[i] << " " << trace[i] << endl;
	//alway have ans
	int tmp = n;
	while (tmp>0){
		cout << trace[tmp];
		tmp -= cost[trace[tmp]];
	}
	
	return 0;
}
