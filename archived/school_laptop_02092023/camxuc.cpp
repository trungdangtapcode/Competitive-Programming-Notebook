#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, q, p;
vector<int> res;
main(){
	freopen("input.txt","r",stdin);
	cin >> n;
	int q = 2*n, p = n;
	while (q){
		if (q&1){
			q--;
			res.push_back(p--);
		} else {
			q/=2;
			p--;
		}
	}
	cout << res.size() << "\n";
	for (int i = res.size()-1; i >= 0; i--) cout << res[i] << " ";
	
	
	return 0;
}
