#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n, a[100005], k, d[100005], f[100005];
int solve(int x){
	for (int i = 1; i <= n; i++) d[i] = (a[i]%x==0);
	stack<ii> st;
	for (int i = 1; i <= n; i++){
		int maxF = f[i-1];
		while (!st.empty()&&a[st.top().first]>=a[i]){
			maxF = max(maxF,st.top().second);
			st.pop();
		};
		f[i] = max(f[(st.empty()?0:st.top().first)],maxF+d[i]);
		st.push({i,maxF});
	}
	return f[n];
}

int main(){
	cin >>n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int mmax = *max_element(a+1,a+n+1);
	vector<int> p;
	for (int i = 1; i <= mmax; i++) if (mmax%i==0) p.push_back(i);
	int res = 1;
	for (int d: p){
		if (solve(d)>=k) res = max(res,d);
	}
	cout << res;
	
	return 0;
}
