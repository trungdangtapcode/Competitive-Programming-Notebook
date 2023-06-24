#include<bits/stdc++.h>

using namespace std;

int val[4000005], n, q;
long long sum[4000005];
void updt(int k, int l, int r, int u, int v){
	if (l>u||r<u) return;
	if (l==r){
		val[k] = sum[k] = v;
		return;
	}
	int m = (l+r)/2;
	updt(2*k,l,m,u,v);
	updt(2*k+1,m+1,r,u,v);
	val[k] = min(val[2*k],val[2*k+1]);
	sum[k] = sum[2*k] + sum[2*k+1];
}
int findd(int k, int l, int r, int lb, int mmin){
	if (val[k]>mmin||r<lb) return 1e9;
	if (l==r) return l;
	int m = (l+r)/2;
	if (lb<=l) if (val[2*k]<=mmin) return findd(2*k,l,m,lb,mmin);
	else return findd(2*k+1,m+1,r,lb,mmin);
	else return min(findd(2*k,l,m,lb,mmin),findd(2*k+1,m+1,r,lb,mmin));
}
int getMin(int k, int l, int r, int u, int v){
	if (l>v||u>r) return 1e9;
	if (u<=l&&r<=v) return val[k];
	int m = (l+r)/2;
	return min(getMin(2*k,l,m,u,v),getMin(2*k+1,m+1,r,u,v));
}
void queryAndChange(int u, int v, int x){
	if (u<=v){
		int mmin = getMin(1,1,n,u,v);
		int pos = findd(1,1,n,u,mmin);
		updt(1,1,n,pos,x);
		return;
	}
	int mmin =min(getMin(1,1,n,u,n),getMin(1,1,n,1,v));
	int pos = findd(1,1,n,u,mmin);
//	if (pos==1e9) cout<< "oh no!\n";
	if (pos==1e9) pos = findd(1,1,n,1,mmin);
//	cout << "pos = " << pos << "\n";
	updt(1,1,n,pos,x);
}
long long getSum(int k, int l, int r, int u, int v){
	if (l>v||u>r) return 0;
	if (u<=l&&r<=v) return sum[k];
	int m = (l+r)/2;
	return getSum(2*k,l,m,u,v) + getSum(2*k+1,m+1,r,u,v);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1, a; i <= n; i++){
		cin >> a;
		updt(1,1,n,i,a);
	}
	int x = 0;
	while (q--){
		int type, s, t, p, d;
		cin >> type;
		if (type==1){
			cin >> d;
			x-= d;
			x = (x%n+n)%n;
		} else if (type==2){
			cin >> s >> t >> p;
			s = (s+x-1)%n+1;
			t = (t+x-1)%n+1;
			queryAndChange(s,t,p);
		} else if (type==3){
			cin >> s >> t;
			s = (s+x-1)%n+1;
			t = (t+x-1)%n+1;
			if (s<=t) cout << getSum(1,1,n,s,t) << "\n";
			else cout << getSum(1,1,n,s,n) + getSum(1,1,n,1,t) << "\n";
		};
//		for (int i = 1; i<= n; i++){
//			int j = (i+x-1)%n+1;
//			cout << getMin(1,1,n,j,j) << " ";
//		} cout << "\n";
	}
	
	return 0;
}
