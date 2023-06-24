#include <bits/stdc++.h>

using namespace std;

long int a[1000], IT[1000];
int x, y;
int INF = 1e3;

void build(int k, int l, int r){
	if (l==r) {
		IT[k] = a[l];
		return;
	}
	build(2*k,l,(l+r)/2);
	build(2*k+1,(l+r)/2+1,r);
	IT[k] = max(IT[2*k],IT[2*k+1]);
	return;
}

int searchT(int k, int l, int r){
	if (l>y||r<x) return -INF;
	if (x<=l&&r<=y) return IT[k];
	if (l==r) return IT[k];
	int findL = searchT(2*k,l,(l+r)/2);
	int findR = searchT(2*k+1,(l+r)/2+1,r);
	//cout << k << " " << l << " " << r << "   " << findL <<" " << findR<<endl;
	//if (x<=r) return findR;
	//if (l<=y) return findR;
	return max(findL,findR);
}

int main(){
	int n;
	cin >> n;
	a[0] =0;
	for (int i= 1; i <= n; i++){
		cin >> a[i];
		a[i] += a[i-1];
	}
	build(1,1,n);
	//for (int i= 1; i <= 4*n; i++) cout << i<<".  "<<IT[i] << endl;
	int m;
	for (int i = 1; i <= m; i++){
		cin >> x >> y;
		//cout << search
	}
	//cout << searchT(1,1,n);
	return 0;
}
