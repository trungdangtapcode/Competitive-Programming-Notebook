#include<bits/stdc++.h>

using namespace std;

const int p = 1e9+9;
struct matrix{
//	vector<vector<int>> data;
	int data[2][2];
	int n, m;
	matrix(int n = 2, int m = 2){
		this->n = n; this-> m = m;
		memset(data,0,sizeof(data));
//		data.assign(n,vector<int>(m,0));
	}
	decltype(data[0]) & operator[](int i){
		return data[i];
	}
	void setNum(){
		for (int i = 0; i < min(n,m); i++) data[i][i] = 1;
	}
	matrix operator*(matrix other){
		matrix res = matrix(n,other.m);
		for (int i =0; i < n; i++) for (int j = 0; j < other.m; j++) for (int k = 0; k < m; k++) (res[i][j] += 1ll*data[i][k]*other[k][j]%p) %= p;
		return res;
	}
	matrix operator+(matrix other){
		matrix res = matrix(n,m);
		for (int i = 0; i < n; i++) for (int j =0; j < m; j++) (res[i][j] = data[i][j]+other[i][j])%= p;
		return res;
	}
	matrix operator-(matrix other){
		matrix res = matrix(n,m);
		for (int i = 0; i < n; i++) for (int j =0; j < m; j++) (res[i][j] = data[i][j]-other[i][j])%= p;
		return res;
	}
	void print(){
		cout << "size: " << n << "x" << m << "\n";
		for (int i =0; i < n; i++){
			for (int j = 0; j < m; j++) cout << data[i][j] << " ";
			cout << "\n";
		}
	}
};

//vector<matrix> coefPow, ;
matrix coefPow[300005], lazy[1200005];
int val[1200005], a[300005], n, m;

void build(int k, int l, int r){
	if (l==r){
		val[k] = a[l];
		return;
	}
	int m = (l+r)/2;
	build(2*k,l,m);
	build(2*k+1,m+1,r);
	(val[k] = val[2*k]+val[2*k+1])%=p;
}
void down(int k, int m, int l, int r){
	if (lazy[k][0][1]==0) return;
	lazy[2*k] = lazy[2*k] + lazy[k];
	lazy[2*k+1] = lazy[2*k+1] + lazy[k]*coefPow[m-l+1];
	(val[2*k] += (lazy[k]*(coefPow[m-l+2]-coefPow[1]))[0][1])%=p;
	(val[2*k+1] += (lazy[k]*coefPow[m-l+1]*(coefPow[r-m+1]-coefPow[1]))[0][1])%=p;
	lazy[k][0][0] = lazy[k][0][1] = lazy[k][1][0] = lazy[k][1][1] = 0;
}
void updte(int k, int l, int r, int u, int v){
	if (l>v||u>r) return;
	if (u<=l&&r<=v){
		lazy[k] = lazy[k] + coefPow[l-u+1];
		(val[k] += (coefPow[l-u+1]*(coefPow[r-l+2]-coefPow[1]))[0][1])%=p;
		return;
	}
	int m = (l+r)/2;
	down(k,m,l,r);
	updte(2*k,l,m,u,v);
	updte(2*k+1,m+1,r,u,v);
	(val[k] = val[2*k] + val[2*k+1])%=p;
}
int gett(int k, int l, int r, int u, int v){
	if (l>v||u>r) return 0;
	if (u<=l&&r<=v) return val[k];
	int m = (l+r)/2;
	down(k,m,l,r);
	return (gett(2*k,l,m,u,v)+gett(2*k+1,m+1,r,u,v))%p;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];	
//	coefPow.assign(n+3,matrix(2,2));
	coefPow[1] = matrix(2,2);
	coefPow[1][0][0] = 0; coefPow[1][0][1] = 1;
	coefPow[1][1][0] = 1; coefPow[1][1][1] = 1;
	for (int i = 2; i <= n+2; i++) coefPow[i] = coefPow[i-1]*coefPow[1];
	build(1,1,n);
//	cout << val[1];
//	updte(1,1,n,1,4);
//	updte(1,1,n,4,4);
//	for (int i = 1; i <= n; i++) cout << gett(1,1,n,i,i) << " ";
	while (m--){
		int op, l, r;
		cin >> op >> l >> r;
		if (op==1){
			updte(1,1,n,l,r);
		} else {
			cout << (gett(1,1,n,l,r)+p)%p << "\n";
		}
	}
	return 0;
}
