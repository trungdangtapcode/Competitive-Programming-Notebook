#include<bits/stdc++.h> 
using namespace std;
typedef pair<long long,int> li;
const int p = 1e9+7;
struct matrix{
	int n, m;
//	vector<vector<int>> data;
	int data[13][13];
	decltype(data[0]) & operator[](int i){
		return data[i];
	}
	matrix(int n, int m){
		this->n = n, this->m = m;
//		data.assign(n,vector<int>(m,0));
		memset(data,0,sizeof(data));
	}
	matrix operator*(matrix other){
		assert(m==other.n);
		matrix res = matrix(n,other.m);
		for (int i = 0; i < n; i++) for (int j =0; j < other.m; j++) for (int k = 0; k < m; k++) (res[i][j] += 1ll*data[i][k]*other[k][j]%p)%=p;
		return res;
	}
	void print(){
		cout << "[size]: " << n<< "x" << m <<"\n";
		for (int i =0; i < n; i++){
			for (int j = 0; j < m; j++) cout << data[i][j] << " ";
			cout << "\n";
		}
	}
	void setNum(){
		for (int i =0; i < min(n,m); i++) data[i][i] = 1;
	}
};
long long int n;
int m, k;

vector<matrix> coef01Pow;
matrix getPow(matrix a, long long b){
	matrix res = matrix(a.n,a.m);
	res.setNum();
	for (int i = 1; b > 0; i++, b >>= 1) if (b&1) res = res*coef01Pow[i];
//	while (b>0){
//		if (b&1) res = res*a;
//		a = a*a;
//		b >>= 1;
//	}
	return res;
}
matrix fastPow(matrix a, long long b){
	for (int i = 1; b > 0; i++, b >>= 1) if (b&1) a = a*coef01Pow[i];
//	while (b>0){
//		if (b&1) res = res*a;
//		a = a*a;
//		b >>= 1;
//	}
	return a;
}

int dp[1005][1005], num[1005];
void sub1(){
	dp[0][0] = 1;
	for (int i = 0, s; i < m; i++){
		cin >> s;
		if (s>0) num[s] = 1;
		else num[-s] = -1;
	}
	int cur = 0, res  = 0;
	for (int i = 1; i <= n; i++){
		if (num[i]==1||!num[i]) for (int j = 0; j < k; j++)	(dp[i][0]+= dp[i-1][j])%=p;
		if (num[i]==-1||!num[i]) for (int j = 1; j <= k; j++) dp[i][j] = dp[i-1][j-1];
		if (!num[i]) (cur = 2*cur%p + dp[i][k]%p)%=p;
		else (cur += dp[i][k])%=p;
		(res += cur) %= p;
	}
	cout << res << "\n";
}

int main(){
	//k+1: used to ok so whatever
	//k+2: ans of before
	cin >> n >> m >> k;
	if (k>10) return sub1(),0;
	matrix coef0 = matrix(k+3,k+3);
	for (int i = 0; i < k; i++){
		coef0[i][0] = 1;
	}	
	//coef[old][new] old_elements -> new one
	coef0[k+1][k+1] = coef0[k][k+1] = 1;
	coef0[k+2][k+2] = coef0[k+1][k+2] = coef0[k][k+2] = 1;
	matrix coef1 = matrix(k+3,k+3);
	for (int i = 1; i <= k; i++){
		coef1[i-1][i] = 1;
	}
	coef1[k+1][k+1] = coef1[k][k+1] = 1;
	coef1[k+2][k+2] = coef1[k+1][k+2] = coef1[k][k+2] = 1;
	matrix coef01 = matrix(k+3,k+3);
	for (int i = 0; i < k; i++) coef01[i][0] = 1;
	for (int i = 1; i <= k; i++) coef01[i-1][i] = 1;
	coef01[k+1][k+1] = coef01[k][k+1] = 2;
	coef01[k+2][k+2] = coef01[k+1][k+2] = coef01[k][k+2] = 1;
//	coef1.print();
	matrix base = matrix(1,k+3);
	base[0][0] = 1;
//	matrix tmp = matrix(coef01.n,coef01.m); tmp.setNum();
//	coef01Pow.push_back(tmp);
	coef01Pow.push_back(coef01); coef01Pow.push_back(coef01);
	for (int i = 1; i <= 60; i++) coef01Pow.push_back(coef01Pow.back()*coef01Pow.back());
//	matrix tmp = base*getPow(coef01,4);
//	for (int i =0; i <= k+2; i++) cout << tmp[0][i] << " "; cout << "\n";
	vector<li> a;
	a.push_back({0,0});
	a.push_back({n+1,0});
	for (int i =0; i < m; i++){
		long long s;
		cin >> s;
		if (s>0){
			a.push_back({s,0});
		} else a.push_back({-s,1});
	}
	sort(a.begin(),a.end());
	for (int i = 1; i < a.size(); i++){
//		cout << a[i].first << " " << a[i].second << "\n";
//		if (a[i].second==0){
//			base = base*getPow(coef01,a[i].first-a[i-1].first-1)*coef0; //new-old-1 + (cur_matrix) = new-old [or] old -> new
//		} else base = base*getPow(coef01,a[i].first-a[i-1].first-1)*coef1;
		if (a[i].second==0){
			base = fastPow(base,a[i].first-a[i-1].first-1)*coef0; //new-old-1 + (cur_matrix) = new-old [or] old -> new
		} else base = fastPow(base,a[i].first-a[i-1].first-1)*coef1;
	}
//	for (int i = 0; i <= k+2; i++) cout << base[0][i] << " ";
	cout << base[0][k+2];
	
	return 0;
}
