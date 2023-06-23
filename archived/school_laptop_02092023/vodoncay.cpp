#include<bits/stdc++.h>

using namespace std;
int n, h[4000005], r[4000005], l[4000005], dp[4000005], trace[4000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i];
	
	stack<int> s;
	for (int i = 1; i <= n; i++){
		l[i] = i;
		while (s.size()&&s.top()>i-h[i]){
			l[i] = min(l[i],l[s.top()]);
			s.pop();
		};
		s.push(i);
	}
	while (s.size()) s.pop();
	for (int i = n; i > 0; i--){
		r[i] = i;
		while (s.size()&&s.top()<i+h[i]){
			r[i] = max(r[i],r[s.top()]);
			s.pop();
		}
		s.push(i);
	}
	while (s.size()) s.pop();
	dp[0] = 0;
	for (int i = 1; i <= n; i++){
		dp[i] = dp[l[i]-1]+1;
		trace[i] = -i;
		while (s.size()&&r[s.top()]<i) s.pop();
		if (s.size()&&dp[i]>dp[s.top()-1]+1){
			dp[i] = dp[s.top()-1] + 1;
			trace[i] = s.top();
		}
		if (s.empty()||dp[s.top()-1]>dp[i-1]) s.push(i);
	}
	cout << dp[n] << "\n";
	int u = n;
	while (u>0){
		cout << trace[u] << " ";
		if (trace[u]>0){
			u = trace[u] - 1;
		} else u = l[u] - 1;
	}
	
	return 0;
}
