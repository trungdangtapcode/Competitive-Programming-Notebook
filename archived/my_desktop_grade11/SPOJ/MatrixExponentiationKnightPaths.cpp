#include <bits/stdc++.h>

using namespace std;
long long int k;
int vx[8] = {2,1,-1,-2,-2,-1,1,2}; //Oxy
int vy[8] = {1,2,2,1,-1,-2,-2,-1};
//long long int p = 4294967296;
//phan tu matrix (dem) la unsigned int (mod qua lon khong the hoat dong 2^32->2^64)
//con so buoc di van la long long int

struct matrix{
	unsigned int a[65][65];
	matrix(unsigned int x){
		for (int i = 0; i < 65; i++)
			for (int j = 0; j < 65; j++)
				a[i][j] = x;
	}
	void setNum(unsigned int x){
		for (int i = 0; i < 65; i++) a[i][i] = x;
	}
	matrix operator*(matrix other){
		matrix product = matrix(0);
		for (int i = 0; i < 65; i++) for (int j = 0; j < 65; j++)
			for (int k = 0; k < 65; k++) product.a[i][j] += a[i][k]*other.a[k][j]; 
		return product;
	}
	unsigned int getRes(){
		return a[0][64];
	}
};

matrix AmuB(matrix a, long long int b){
	matrix res = matrix(0);
	res.setNum(1);
	while (b!=0){
		if (b%2==1) res = res*a;
		b /= 2;
		a = a*a;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	
	cin >> k;
	matrix mat = matrix(0);
	mat.a[64][64] = 1;
	for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) for (int k = 0; k < 8; k++){
		mat.a[j*8+i][64] = 1;
		int x = i + vx[k], y = j + vy[k];
		if (x<0||x>=8||y<0||y>=8) continue;
		mat.a[j*8+i][y*8+x] = 1; //Oxy
	}
	cout << AmuB(mat,k+1).getRes() << '\n';
	
	return 0;
}


//#include <bits/stdc++.h>
//
//using namespace std;
//long long int k;
//int vx[9] = {0,2,1,-1,-2,-2,-1,1,2}; //Oxy
//int vy[9] = {0,1,2,2,1,-1,-2,-2,-1};
//long long int p = (1<<32);
//
//struct matrix{
//	long long int a[64][64];
//	matrix(long long int x){
//		for (int i = 0; i < 64; i++)
//			for (int j = 0; j < 64; j++)
//				a[i][j] = x;
//	}
//	void setNum(long long int x){
//		for (int i = 0; i < 64; i++) a[i][i] = x;
//	}
//	matrix operator*(matrix other){
//		matrix product = matrix(0);
//		for (int i = 0; i < 64; i++) for (int j = 0; j < 64; j++)
//			for (int k = 0; k < 64; k++) product.a[i][j] = (product.a[i][j]+a[i][k]*other.a[k][j]); 
//		return product;
//	}
//	long long int getRes(){
//		long long int res = 0;
//		for (int i = 0; i < 64; i++) res = (res+a[0][i]);
//		return res; 
//	}
//};
//
//matrix AmuB(matrix a, long long int b){
//	matrix res = matrix(0);
//	res.setNum(1);
//	while (b!=0){
//		if (b%2==1) res = res*a;
//		b /= 2;
//		a = a*a;
//	}
//	return res;
//}
//
//int main(){
//	
//	cin >> k;
//	matrix mat = matrix(0);
//	for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) for (int k = 0; k < 9; k++){
//		int x = i + vx[k], y = j + vy[k];
//		if (x<0||x>=8||y<0||y>=8) continue;
//		if (x==i&&y==j&&x!=0&&y!=0) continue;
//		mat.a[j*8+i][y*8+x] = 1;
//	}
////	mat = mat*mat;
////	for (int i = 0; i < 64; i++) for (int j = 0; j < 64; j++)
////		cout << i%8+1<<','<<i/8+1<<' '<<j%8+1<<','<<j/8+1<<' '<<mat.a[i][j]<<endl;
//	cout << AmuB(mat,k).getRes() << '\n';
//	
//	return 0;
//}
