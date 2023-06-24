#include <bits/stdc++.h>

using namespace std;
int n;
int a[200005], h[200005];
long long int val[200005];

void add(int x, long long int y){
	while (x <= n){
		val[x] = max(val[x],y);
		x += (x&-x);
	}
}
long long int getMax(int x){
	long long int res = 0;
	while (x>0){
		res = max(res,val[x]);
		x -= (x&-x);
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> h[i];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++){
		add(h[i],getMax(h[i]-1)+a[i]); //co the h[i], do h la cac hoan vi [1..n]. but no greedy
	}
	cout << *max_element(val+1,val+n+1); //no greedy
	
	
	
	return 0;
}
