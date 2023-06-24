/*
#include <bits/stdc++.h>

using namespace std;
typedef pair<int,long long int> ii;
int n, a[100005];
long long int k;
ii v[100005];
int val[100055];

void reset(){
	memset(val,0,sizeof(val));
}
void update(int x, int y){
	while (x<=1e5){
		val[x] += y;
		x += (x&-x);
	}
}
int getSum(int x){
	int res = 0;
	while (x>0){
		res += val[x];
		x -= (x&-x);
	}
	return res;
}

long long int f(int x){
	long long int res = 0;
	reset();
//	update(0+5,+1);
	for (int i = 0; i <= n; i++){
		cout << " getSum() = "<< getSum(a[i]-x) << endl;
		res += getSum(a[i]-x);
		update(a[i],+1);
	}
	return res;
}

int main(){	

	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> v[i].first;
//		a[i] = v[i].first;
		v[i].first += v[i-1].first;
		v[i].second = i;
	}
	for (int i = 0; i <= n; i++) cout << v[i].first << " "; cout << endl;
	sort(v,v+n+1);
	a[v[0].second] = 1;
	for (int i = 1, dem = 1; i <= n; i++){
		if (v[i].first!=v[i-1].first) dem++;
		a[v[i].second] = dem;
	}
	for (int i = 0; i <= n; i++) cout << a[i] << " "; cout << endl;
	cout << f(2);
	
	
	return 0;
}
*/
