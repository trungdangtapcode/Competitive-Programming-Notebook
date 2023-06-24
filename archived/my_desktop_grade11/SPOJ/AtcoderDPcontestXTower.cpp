#include <bits/stdc++.h>

using namespace std;

struct block{
	int w, s, v;
	bool operator < (block other){
		return (w+s<other.w+other.s);
	}
};
int n;
long long int dp[20055];

int main(){
	
	cin >> n;
	vector<block> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i].w >> a[i].s >> a[i].v;
	}
	sort(a.begin(),a.end());
	for (int i = 0; i < n; i++){
		for (int j = a[i].s; j >= 0; j--)
			dp[j+a[i].w] = max(dp[j+a[i].w],dp[j]+a[i].v);
	}
	cout << *max_element(dp,dp+20005);
	
//	for (int i = 0; i < n; i++){
//		cout << a[i].s <<" "<< a[i].w <<" " << a[i].v << endl;
//	}
	
	return 0;
}
