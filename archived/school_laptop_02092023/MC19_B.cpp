#include<bits/stdc++.h>

using namespace std;
int n, a[2005], res = 1e9;
set<int> s;
int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < n; i++){
		for (int j = n-1; j >= -1; j--){
			if (j<0||s.find(a[j])!=s.end()){
				res = min(res,j-i+1);
				for (int jj = j+1; jj < n; jj++) s.erase(a[jj]);
				break;
			}
			s.insert(a[j]);
		}
		if (s.find(a[i])!=s.end()) break;
		s.insert(a[i]);
	}
	cout << res;
	
	
	return 0;
}
