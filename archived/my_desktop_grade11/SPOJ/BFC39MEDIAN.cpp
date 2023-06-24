#include <bits/stdc++.h>

using namespace std;
int n, sum[100005], val[200055], a, k;
void reset(){
	memset(val,0,sizeof(val));
}
void update(int x, int y){
	while (x<=2e5+5){
		val[x] = val[x] + y;
		x += (x&-x);
	}
}
int getSum(int x){
	int res = 0;
	while (x>0){
		res = res + val[x];
		x -= (x&-x);
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	
	reset();
	update(0+n+1,+1);
	int sum = 0;
	long long int res = 0;
	for (int i = 0; i < n; i++){
		cin >> a;
		a = (a>=k?1:-1);
		sum += a;
		res += getSum(sum+n+1);
		update(sum+n+1,+1);
	}
	cout << res;
	
	return  0;
}
