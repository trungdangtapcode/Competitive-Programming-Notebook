#include<bits/stdc++.h>

using namespace std;
int dp[2005][1<<10]; //00: ko co, 01: (, 10: [, 11: { 

stack<int> mask2stack(int mask){
	stack<int> res;
	while (mask){
		res.push(mask%4);
		mask /= 4;
	}
	return res;
}
int stack2mask(stack<int> s){
	int res = 0;
	while (!s.empty()){
		res = res*4 + s.top();
		s.pop();
	}
	return res;
}

int main(){
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) for (int mask = 0; mask < 1<<10; mask++){
		if (dp[i][mask]==0) continue;
		if (s[i]=='?'){
			stack<int> s = mask2stack(mask);
			if (s.size()>=k) continue;
			s.push(1);
			dp[i+1][stack2mask(s)] += dp[i][]
		} 
	}
	
	return 0;
}
