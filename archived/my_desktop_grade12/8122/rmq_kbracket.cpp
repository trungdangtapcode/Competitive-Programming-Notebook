#include<bits/stdc++.h>

using namespace std;

string s;
int n, k, pos[100005];

int rmq[100005][20];
int getMax(int i, int j){
	int h = __lg(j-i+1);
	return max(rmq[i][h],rmq[j-(1<<h)+1][h]);
}

int dp[100005];
long long int Count(int k){
	memset(dp,0,sizeof(dp));
	long long int res = 0;
	for (int i = 1; i <= n; i++) if (pos[i]&&getMax(pos[i],i)-rmq[pos[i]-1][0]<=k)
		dp[i] = dp[pos[i]-1]+1, res += dp[i];
	return res;
}
int maxLength(int k){
	memset(dp,0,sizeof(dp));
	dp[0] = 0;
	int res = 0-1;
	for (int i = 1; i <= n; i++) if (pos[i]&&getMax(pos[i],i)-rmq[pos[i]-1][0]<=k){
		dp[i] = dp[pos[i]-1] + i - pos[i] + 1;
		if (getMax(i-dp[i]+1,i)-rmq[i-dp[i]][0]==k) res = max(res,dp[i]);
	} 
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> s >> k;
	n = s.length();
	s = " " + s;
	
	stack<int> st;
	for (int i = 1, cur = 0; i <= n; i++){
		if (s[i]=='('){
			cur++;
			st.push(i);
		} else {
			cur--;
			if (st.size()){
				pos[i] = st.top();
				st.pop();
			}
		}
		rmq[i][0] = cur;		
	}
	for (int i = 1; i < 20; i++){
		for (int j = 1; j <= n-(1<<i)+1; j++) rmq[j][i] = max(rmq[j][i-1],rmq[min(j+(1<<(i-1)),n)][i-1]);
	}
	cout << Count(k)-Count(k-1) << "\n" << maxLength(k);

//	int res1 = 0;
//	for 
//	
	return 0;
}
