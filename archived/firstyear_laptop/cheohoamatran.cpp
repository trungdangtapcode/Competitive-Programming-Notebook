#include<bits/stdc++.h>

using namespace std;

struct Matrix{
	#define ld long double
	const ld EPS = 1E-9; //sai so cho so thuc
	//eps = 1e-9, eps_eigen = 1e-5, eps_lambda = 2e-4, EPS_DET = 1e-15 
	int n, m;
	vector<vector<ld>> a;
	Matrix(int _n, int _m){
		n = _n;
		m = _m;
		a.resize(n,vector<ld>(m));
	}
	vector<ld>& operator[](int i){
		return a[i];
	}
	void swapRow(int i, int j){ //hoan doi 2 dong
		swap(a[i],a[j]);
	}
	void opRow(int j1, int j2, ld x, ld y){ //[i] = x*[i] + y*[j], x != 0
		for (int i = 0; i < m; i++) a[j1][i] = x*a[j1][i] + y*a[j2][i];
	}
	void pivotSwap(){ //chuan hoa cac dong a[pivot[i]][i] != 0
		//
	}
	void roundMatrix(){
		for (int i = 0; i < n; i++){
			for (int j =0; j < m; j++) a[i][j] = round(a[i][j]*1e6)*1e-6;
		}
	}
	void print(string s = ""){
		if (s=="") cout << n << "x" << m << ": \n";
		else cout << s << "\n";
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
	Matrix inverse(){ 
		assert(n==m);
		Matrix res(n,n);
		Matrix a = *this;
		for (int i = 0; i < n; i++) res[i][i] = 1;
		for (int i = 0; i < n; i++){
			int k = i;
			for (int j = i+1; j < n; j++) if (abs(a[j][i])>abs(a[k][i])) k = j;
			if (abs(a[k][i])<EPS){
				cout << "MA TRAN KHONG KHA NGHICH!\n";
				assert(0);
			}
			res.swapRow(i,k);
			a.swapRow(i,k);
			res.opRow(i,i,1/a[i][i],0);
			a.opRow(i,i,1/a[i][i],0);
			for (int j = 0; j < n; j++){
				if (j!=i && abs(a[j][i])>EPS){
					res.opRow(j,i,1,-a[j][i]);
					a.opRow(j,i,1,-a[j][i]);
				}
			}
		}
		return res;	
	}
	ld trace(){
		ld res = 0;
		assert(n==m);
		for (int i = 0; i < n; i++) res += a[i][i];
		return res;
	}
	ld prod(){
		ld res = 1;
		assert(n==m);
		for (int i = 0; i < n; i++) res *= a[i][i];
		return res;
	}
	ld findDet(bool check = 0){
		assert(n==m);
		Matrix a = *this;
		ld det = 1;
		for (int i = 0; i < n; i++){
			int k = i;
			for (int j = i+1; j < n; j++) if (abs(a[j][i])>abs(a[k][i])) k = j;
			if (abs(a[k][i])<EPS){
				return 0;
			}
			if (i!=k) det *= -1;
			a.swapRow(i,k);
			det *= a[i][i];
			a.opRow(i,i,1/a[i][i],0);
			for (int j = 0; j < n; j++){
				if (j!=i && abs(a[j][i])>EPS){
					a.opRow(j,i,1,-a[j][i]);
				}
			}
			if (check) a.print();
		}
		return det;	
	}
	Matrix operator+(Matrix other){
		assert(n==other.n&&m==other.m);
		Matrix res(n,m);
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) res[i][j] = a[i][j] + other[i][j];
		return res;
	}
	Matrix operator*(Matrix other){
		assert(m==other.n);
		Matrix res(n,other.m);
		for (int i = 0; i < n; i++) for (int j = 0; j < other.m; j++)
			for (int k = 0; k < m; k++) res[i][j] += a[i][k]*other[k][j];
		return res;
	}
	Matrix operator*(ld x){
		Matrix res(n,m);
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) res[i][j] = x*a[i][j];
		return res;
	}
	Matrix trans(){
		Matrix res(m,n);
		for (int i = 0; i < n; i++) for (int j =0; j < m; j++)
			res[j][i] = a[i][j];
		return res;
	}
	vector<vector<ld>> eigenVec(){
		Matrix a = *this;
		vector<int> depen;
		int rank = 0;
		a.roundMatrix();
		for (int i = 0, pivot = 0; i < n; i++){
			while (pivot<m){
				int k = i;
				for (int j = i+1; j < n; j++) if (abs(a[j][pivot])>abs(a[k][pivot])) k = j;
				if (abs(a[k][pivot])>1e-5){ //another EPS :(, rather 1e-5 than 1e-6
					a.swapRow(i,k);
					a.opRow(i,i,(ld)1/a[i][pivot],0);
					break;
				}
				depen.push_back(pivot);
				pivot++;
			}
			if (pivot>=m){
				break;
			}
			for (int j = 0; j < n; j++){
				if (j!=i && abs(a[j][pivot])>EPS){
					a.opRow(j,i,1,-a[j][pivot]);
				}
			}
			pivot++;
			rank++;
		}
//		a.print();
		vector<vector<ld>> res;
		for (int x: depen){ //SPECIAL: n==m
			//n: num row, m: num col
			//m val; rank pivot => m-rank be depened
			//1 pivot is for 1 equal and 1 dim 
			vector<ld> tmp;
			for (int i = 0; i < m; i++){
				tmp.push_back(-a[i][x]);
			}
			tmp[rank] = 1;
			rank++;
			res.push_back(tmp);
		}
		for (; rank < m; rank++){
			vector<ld> tmp(m);
			tmp[rank] = 1;
			res.push_back(tmp);
		}
		return res;
	}
	void addVec(vector<ld> vec){
		m++;
		assert(vec.size()==n);
		for (int i =0; i < n; i++) a[i].push_back(vec[i]);
	}
	void addVec(vector<vector<ld>> vec){
		for (auto it: vec) addVec(it);
	}
};
Matrix donvi(int n){
	Matrix res(n,n);
	for (int i =0; i < n; i++) res[i][i] = 1;
	return res;
}

const ld EPS = 1e-15, INF = 1e9;
const int loopLIM = 1e8;
int main(){
	cout << setprecision(15);
	int n;
	cout << "nhap kich thuoc: ";
	cin >> n;
	cout << "nhap " << n*n << " gia tri cua ma tran: \n";
	Matrix x(n,n);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) cin >> x[i][j];
	}
	set<ld> s;
	Matrix P(n,0), D = donvi(n);
	for (int i = -100; i <= 100; i++){
		ld lambda = (ld)i/2;
		//NEWTON'S METHOD
		for (int i =0; i<100; i++){
			Matrix tmp = x+donvi(n)*lambda;
			if (abs(tmp.findDet())==0) break;
			ld dx = 1/tmp.inverse().trace();
			lambda -= dx;
		}
		Matrix tmp = x+donvi(n)*lambda;
		if (abs(tmp.findDet())>EPS) continue;
		auto it = s.lower_bound(lambda+2e-4); //EPS v2 :(
		if (it!=s.end()&&abs(*it-lambda)<2e-4) continue;
		it = s.lower_bound(lambda-2e-4);
		if (it!=s.end()&&abs(*it-lambda)<2e-4) continue;
//		cout << lambda << "\n";
		auto vvec = tmp.eigenVec();
		for (int i = P.m; i < P.m+vvec.size(); i++) D[i][i] *= -lambda;
		P.addVec(vvec);
		s.insert(lambda);	
	}
//	P.print();
	if (P.m<n){
		cout << "MA TRAN KHONG CHEO HOA DUOC!\n";
		return 0;
	}
	Matrix Pi = P.inverse();
	P.roundMatrix();
	P.print("P: ");
	D.roundMatrix();
	D.print("D: ");
	Pi.roundMatrix();
	Pi.print("P^-1: ");
	
//	(res*res2*res.inverse()).print();
	
	return 0;
}
//https://pastebin.com/xfPYM4dc
//https://pastebin.com/tbeTDmuv
//https://pastebin.com/QcGZzz22
