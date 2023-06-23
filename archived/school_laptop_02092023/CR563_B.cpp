#include<bits/stdc++.h>

using namespace std;
int n, cl[2];
vector<int> a;
int main(){
	
	cin >> n;
	a.assign(n,0);
	for (int i = 0; i < n; i++){
		cin >> a[i];
		cl[a[i]%2] = true;
	}
	if (cl[0]&&cl[1]) sort(a.begin(),a.end());
//	sort(a.begin(),a.end(),[](int a, int b){
//		if ((a+b)%2) return (a<b);
//		return false;
//	});
	
	for (auto it: a) cout << it << " ";
	
	return 0;
}
