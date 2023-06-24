#include <bits/stdc++.h>

using namespace std;
long long int n, k;
int p = 1e9+7;

struct matrix{
	int n, m; //row, col
	vector<vector<int>> a;
	matrix(int n, int m){
		this->n = n;
		this->m = m;
		a.resize(n,vector<int>(m));
	}
	void setNum(int x){
		for (int i = 0; i < min(n,m); i++) a[i][i] = x;
	}
	int getSum(){
		int res = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) res = (res+a[i][j])%p;
		return res;
	}
	matrix operator*(matrix other){
		matrix product = matrix(n,other.m);
		for (int i = 0; i < n; i++) for (int j = 0; j < other.m; j++) for (int k = 0; k < m; k++){
			product.a[i][j] = (product.a[i][j]+1ll*a[i][k]*other.a[k][j])%p;
		}
		return product;
	}
};

matrix AmuB(matrix a, long long int b){
	matrix res = matrix(a.n,a.m);
	if (b<0) return res;
	res.setNum(1);
	while (b!=0){
		if (b%2==1) res = (res*a);
		a = a*a;
		b /= 2;
	}
	return res;
}

int main(){
	
	matrix trans = matrix(3,3);
	trans.a[0][0] = 0; trans.a[0][1] = 1; trans.a[0][2] = 1; //[end 10, 01, 00]
	trans.a[1][0] = 1; trans.a[1][1] = 0; trans.a[1][2] = 1;
	trans.a[2][0] = 1; trans.a[2][1] = 1; trans.a[2][2] = 1;
	matrix fibo = matrix(2,2); //trans2
	fibo.a[0][0] = 0; fibo.a[0][1] = 1; //[end 1, end 0]
	fibo.a[1][0] = 1; fibo.a[1][1] = 1;
	
	matrix mat1 = matrix(1,3); //right
	mat1.a[0][0] = mat1.a[0][1] = mat1.a[0][2] = 1;
	matrix mat2 = matrix(1,2); //left
	mat2.a[0][0] = mat2.a[0][1] = 1;
	matrix leftBad = matrix(1,3);
	leftBad.a[0][1] = 1; leftBad.a[0][0] = leftBad.a[0][2] = 0;
	matrix rightBad = matrix(1,2);
	rightBad.a[0][0] = 1; rightBad.a[0][1] = 0; //reverse
	
	cin >> n >> k;
	matrix x = mat1*AmuB(trans,n-k-1);
	matrix y = mat2*AmuB(fibo,2*k-1);
	long long int z = 1ll*(leftBad*AmuB(trans,n-k-1)).a[0][0]*(rightBad*AmuB(fibo,2*k-1)).a[0][0];
	if (n==k){ //no need left
//		cout << x.a[0][0] << " " << x.a[0][1] << " " << x.a[0][2] << endl;
		x.a[0][2] = 1; 
	}
	if (k==0){ //no need right
		cout << ((x.getSum()-1-2*n-(leftBad*AmuB(trans,n-k-1)).a[0][0])%p+p)%p;
		return 0;
	}
	cout << ((1ll*x.getSum()*y.getSum()-1-2*n-1ll*x.a[0][1]*y.a[0][0]-1ll*x.a[0][0]*y.a[0][0]+z)%p+p)%p;
//	cout << AmuB(fibo,10).a[0][1];
	return 0;
}

//Jan. 22, 2022, 8:28 a.m.

//	matrix mat1 = matrix(1,3);
//	mat1.a[0][0] = mat1.a[0][1] = 1; mat1.a[0][2] = 0;
//	matrix mat2 = matrix(1,2);
//	mat2.a[0][0] = 1; mat2.a[0][1] = 0;

//	cout << (x.getSum()-1)*(y.getSum()-1)-x.a[0][1]*y.a[0][0]-x.a[0][0]*y.a[0][0];
//-0*x.a[2][1]*y.a[0][0];
