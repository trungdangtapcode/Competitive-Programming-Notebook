#include<bits/stdc++.h>

using namespace std;

const int p = 1000000123;
struct matrix{
	vector<vector<int>> data;
	int n, m;
	vector<int> & operator [](int i){
		return data[i];
	}
	matrix(int n, int m){
		this->n = n;
		this->m = m;
		data.assign(n,vector<int>(m,0));
	}
	void print(){
		cout << "size " << n << "x" << m << "\n";
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++) cout << data[i][j] << " ";
			cout << "\n";
		}
	}
	matrix operator*(matrix other){
//		cout << n << "x" << m << " * " << other.n << "x" << other.m << endl;
		assert(m==other.n);
		matrix res = matrix(n,other.m);
		for (int i = 0; i < n; i++) for (int j = 0; j < other.m; j++) for (int k = 0; k < m; k++) (res[i][j] += 1ll*data[i][k]*other[k][j]%p)%=p;
		return res;
	}
};

int last, odd_idx[6][6];
int idx(int even_oddFreq, int odd_oddFreq, int added_odd){
	assert(odd_oddFreq<=added_odd);
	return last*even_oddFreq + odd_idx[odd_oddFreq][added_odd];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int added_odd = 0; added_odd <= 5; added_odd++) for (int odd_oddFreq = 0; odd_oddFreq <= added_odd; odd_oddFreq++) odd_idx[odd_oddFreq][added_odd] = last++;	
	
	matrix base = matrix(idx(5,5,5)+2,idx(5,5,5)+2);
	for (int even_oddFreq = 0; even_oddFreq <= 5; even_oddFreq++){
		for (int added_odd = 0; added_odd <= 5; added_odd++) for (int odd_oddFreq = 0; odd_oddFreq <= added_odd; odd_oddFreq++){
			if (even_oddFreq) base[idx(even_oddFreq,odd_oddFreq,added_odd)][idx(even_oddFreq-1,odd_oddFreq,added_odd)] += even_oddFreq;
			if (even_oddFreq<5) base[idx(even_oddFreq,odd_oddFreq,added_odd)][idx(even_oddFreq+1,odd_oddFreq,added_odd)] += 5-even_oddFreq;
			if (added_odd<5) base[idx(even_oddFreq,odd_oddFreq,added_odd)][idx(even_oddFreq,odd_oddFreq+1,added_odd+1)] += 5-added_odd;
			if (odd_oddFreq) base[idx(even_oddFreq,odd_oddFreq,added_odd)][idx(even_oddFreq,odd_oddFreq-1,added_odd)] += odd_oddFreq;
			if (odd_oddFreq<added_odd) base[idx(even_oddFreq,odd_oddFreq,added_odd)][idx(even_oddFreq,odd_oddFreq+1,added_odd)] += added_odd-odd_oddFreq;
			if (!even_oddFreq&&odd_oddFreq==added_odd) base[idx(even_oddFreq,odd_oddFreq,added_odd)][idx(5,5,5)+1]++;
		}
	}
	base[idx(5,5,5)+1][idx(5,5,5)+1] = 1;
	
	matrix ans = matrix(1,idx(5,5,5)+2);
	ans[0][idx(1,0,0)] = 4;
	ans[0][idx(0,1,1)] = 5;
//	cout << (ans*base*base*base*base*base*base*base)[0][idx(5,5,5)+1];
	vector<matrix> base_pow;
	base_pow.push_back(base);
	for (int i = 1; i <= 60; i++) base_pow.push_back(base_pow.back()*base_pow.back());
	long long n;
	while (cin >> n){
		matrix res = ans;
		for (int i = 0; n; n >>= 1, i++) if (n&1) res = res*base_pow[i];
		cout << res[0][idx(5,5,5)+1] << "\n";
	}
	
	return 0;
}
