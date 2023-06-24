#include <bits/stdc++.h>
using namespace std;
int duplicateNumber(std::vector<int> Tst){
	int n = Tst.size();
	vector<bool> check(n);
	for (int i = 0; i < n; i++){
		if (check[Tst[i]]) return Tst[i];
		check[Tst[i]] = true;
	}
}
int main(){
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << duplicateNumber(a);
	return 0;
}
