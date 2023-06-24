#include <bits/stdc++.h>

using namespace std;
int n;
const int p = 1e9+7;
struct matrix{
	int a[3][3];
	matrix(){
		memset(a,0,sizeof(a));
	}
	void setNum(int x){
		for (int i = 0; i < 3; i++) a[i][i] = x;
	}
	matrix operator*(matrix other){
		matrix product = matrix();
		for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) for (int k = 0; k < 3; k++){
			product.a[i][j] = (product.a[i][j]+1ll*a[i][k]*other.a[k][j])%p;
		}
		return product;
	}
};
matrix AmuB(matrix a, long long int b){
	matrix res = matrix();
	res.setNum(1);
	while (b>0){
		if (b%2) res = (res*a);
		a = (a*a);
		b /= 2;
	}
	return res;
};
int fibSum(long long n){
	matrix trans = matrix();
	trans.a[0][0] = 0; trans.a[0][1] = 1; trans.a[0][2] = 0; 
	trans.a[1][0] = 1; trans.a[1][1] = 1; trans.a[1][2] = 1; 
	trans.a[2][0] = 0; trans.a[2][1] = 0; trans.a[2][2] = 1;
	return AmuB(trans,n).a[1][2]; 
}
int main(){
	cin >> n;
	cout << fibSum(n);
}
