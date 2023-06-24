#include <bits/stdc++.h>

using namespace std;

int n, a[20005], ap[20005][105], val[80005][105], q;
bool prime[105];

void buildTree(int k, int l, int r){
	//cout << k << " " << l << " " << r << endl;
	if (l==r){
		for (int i = 2; i <= 100; i++) val[k][i] = ap[l][i];	
		return;	
	}
	
	int m = (l+r)/2;
	buildTree(2*k,l,m);
	buildTree(2*k+1,m+1,r);
	for (int i = 2; i <= 100; i++) val[k][i] = val[2*k][i] + val[2*k+1][i];
}

int y[105];
void updateTree(int k, int l, int r, int x){
	if (x<l||x>r) return;
	if (l==r&&l==x){ //k bik co can l==x ko
		for (int i = 2; i <= 100; i++) val[k][i] += y[i];
		return;
	}
	
	int m = (l+r)/2;
	updateTree(2*k,l,m,x);
	updateTree(2*k+1,m+1,r,x);
	for (int i = 2; i <= 100; i++) val[k][i] = val[2*k][i] + val[2*k+1][i];
}

int returnVal[80005][105];  //use to return an array
void getTree(int k, int l, int r, int u, int v){
	if (v<l||r<u){
		for (int i = 2; i <= 100; i++) returnVal[k][i] = 0;
		return;
	}
	
	if (u<=l&&r<=v){
		for (int i = 2; i <= 100; i++) returnVal[k][i] = val[k][i];
		return;
	}
	
	int m = (l+r)/2;
	getTree(2*k,l,m,u,v);
	getTree(2*k+1,m+1,r,u,v);
	for (int i = 2; i <= 100; i++) returnVal[k][i] = returnVal[2*k][i] + returnVal[2*k+1][i];
	return;
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	memset(prime,true,sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i <= 100; i++) if (prime[i]){
		for (int j = 2*i; j <= 100; j+=i) prime[j] = false;
	}
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i]; //vai nay for tu 0 k segment tree dc
	
	for (int i = 1; i <= n; i++){
		int j = 2;
		while (a[i]!=1){
			while (a[i]%j==0) a[i]/=j, ap[i][j]++;
			j++;
		}
	}
	
	buildTree(1,1,n);
	
	
//	for (int i = 0; i < n; i++){
//		cout << i << ": ";
//		for (int j = 2; j <= 100; j++) if (ap[i][j]>0) cout << j << "^" << ap[i][j] << " ";
//		cout << endl;
//	}
//	y[2] = 3;
//	updateTree(1,1,n,4);
//	for (int j = 2; j <= 100; j++) if (val[1][j]>0) cout << j << "^" << val[1][j] << " ";

	cin >> q;
	while (q--){
		int x;
		cin >> x;
		if (x==2){
			int val, pos;
			cin >> pos >> val;
			memset(y,0,sizeof(y));
			for (int i = 2; i <= 100; i++) while (val%i==0) val/=i, y[i]++;
			updateTree(1,1,n,pos);
		} else {
			int l, r;
			cin >> l >> r;
			getTree(1,1,n,l,r);
			bool check = true;
			for (int i = 2; i <= 100; i++) if (returnVal[1][i]%2==1) check = false;
			cout << (check?"YES":"NO") << '\n';
		}
		
	}
	
//	getTree(1,1,n,1,n);
//	for (int j = 2; j <= 100; j++) if (returnVal[1][j]>0) cout << j << "^" << returnVal[1][j] << " ";
	
	
	return 0;
}
