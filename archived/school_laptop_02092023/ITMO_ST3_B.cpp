#include<bits/stdc++.h>

using namespace std;

int val[400005], n, m, a[100005];
void updt(int k, int l, int r, int x, int y){
	if (l>x||r<x) return;
	if (l==x&&r==x){
		val[k] += y;
		return;
	}
	int m = (l+r)/2;
	updt(2*k,l,m,x,y);
	updt(2*k+1,m+1,r,x,y);
	val[k] = val[2*k] + val[2*k+1];
}
int findd(int k, int l, int r, int s){
	if (l==r) return l;
	int m = (l+r)/2;
	if (s<val[2*k+1]) return findd(2*k+1,m+1,r,s);
	else return findd(2*k,l,m,s-val[2*k+1]);
}

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		updt(1,1,n,i,1);
	}
	vector<int> res;
	for (int i = n; i >= 1; i--){
		int tmp = findd(1,1,n,a[i]);
		res.push_back(tmp);
		updt(1,1,n,tmp,-1);
	}
	reverse(res.begin(),res.end());
	for (int x: res) cout << x << " ";
	
	return 0;
}
