#include <bits/stdc++.h>

using namespace std;

string s[150];
int h, w;
int t, p = 1e9 + 7;

int cell2list(int x, int y){ //[1..h][1..w]
	return ((x-1)*w+(y-1));
}
struct Matrix{
	int a[105][105];
	
	void setAll(int x){
		for (int i = 0; i < h*w; i++){
			for (int j = 0; j < h*w; j++){
				a[i][j] = x;
			}
		}
	}
	
	void setNum(int x){
		for (int i = 0; i < h*w; i++) a[i][i] = x;
	}
	
	int getSum(){
		int sum = 0;
		for (int i = 0; i < h*w; i++){
			for (int j = 0; j < h*w; j++){
				sum = (sum+a[i][j])%p;
			}
		}
		return sum;
	}
	
	Matrix operator*(Matrix& other){
		Matrix product;
		product.setAll(0);
		for (int i = 0; i < h*w; i++){
			for (int j = 0; j < h*w; j++){
				for (int k = 0; k < h*w; k++) 
					product.a[i][j] = (product.a[i][j] + (long long int)a[i][k]*other.a[k][j])%p;
			}
		}
		return product;
	}
	
};
Matrix mat;

Matrix AmuB(Matrix a, int b){
	Matrix res;
	res.setAll(0);
	res.setNum(1);
	
	while (b > 0){
		if (b%2==1) res = res*a;
		b/=2;
		a = a*a;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> h >> w >> t;
	for (int i = 1; i <= h; i++){
		cin >> s[i];
		s[i] = '#' + s[i] + '#';
	}	
	for (int i = 0; i <= w+1; i++) s[0] = s[h+1] = '#';
	for (int i = 1; i <= h; i++){
		for (int j = 1; j <= w; j++){
			if ((s[i][j]=='R'||s[i][j]=='+')&&s[i][j+1]!='#'){
				mat.a[cell2list(i,j)][cell2list(i,j+1)] = 1;
			}
			if ((s[i][j]=='L'||s[i][j]=='+')&&s[i][j-1]!='#'){ //s[i][0] alway = '#'
				mat.a[cell2list(i,j)][cell2list(i,j-1)] = 1;
			}
			if ((s[i][j]=='U'||s[i][j]=='+')&&s[i-1][j]!='#'){ //s[0][j] alway = '#' => cell2list
				mat.a[cell2list(i,j)][cell2list(i-1,j)] = 1;
			}
			if ((s[i][j]=='D'||s[i][j]=='+')&&s[i+1][j]!='#'){ //s[w+1][j] alway = '#' 
				mat.a[cell2list(i,j)][cell2list(i+1,j)] = 1;
			}
		}
	}
	//cout << h << " " << w << endl;
	for (int i = 0; i < h*w; i++){
		if (i%w==0) cout << endl << "___________________" << endl; else cout << endl; 
		for (int j = 0; j < h*w; j++) {
			if (j%w==0) cout << "|"; else cout << " ";
			cout << AmuB(mat,t).a[i][j];
			//cout << "(" << i << ","<<j<<")";
		}
	}
	cout << AmuB(mat,t).getSum() << '\n';
	return 0;
}
