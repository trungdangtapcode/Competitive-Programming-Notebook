#include <bits/stdc++.h>

using namespace std;

string pnum(std::vector<int> A, std::vector<int> B){
	bool check[50005];
	memset(check,false,sizeof(check));
	check[0] = true;
	int na = A.size(), nb = B.size();
	sort(A.begin(),A.end());
	for (int i = 0; i < 5000; i++){
		for (int j = 0; j < na; j++){
			if (check[i]) break;
			if (A[j]>i) break;
			check[i] |= check[i-A[j]];		
		}
	}
	string res; res.resize(nb);
	for (int i = 0; i < nb; i++){
		bool ok = false;
		for (int j = 0; j < na; j++){
			ok |= check[B[i]%A[j]];
		}
		res[i] = (char)(ok+'0');
	}
	return res;
}
int main(){
	int na, nb;
	cin >> na >> nb;
	vector<int> a(na), b(nb);
	for (int i = 0; i < na; i++) cin >> a[i];
	for (int i = 0; i < nb; i++) cin >> b[i];
	cout << pnum(a,b);
	return 0;
}

//string res LTE
//if (i>=A[j]) check[i] |= check[i-A[j]]; LTE
