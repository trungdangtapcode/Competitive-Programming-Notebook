#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> a;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--){
		cin >> n;
		a.assign(n,0);
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		int pref = 0;
		for (;;){
			int tmp = pref;
			int* p;
			for (int& x: a) if (x!=-1){
					if ((pref|x)>tmp){
					tmp = pref|x;
					p = &x;	
				}
			}
			if (tmp==pref) break;
			cout << *p << " ";
			*p = -1;
			pref = tmp;
		}
		for (int x: a) if (x!=-1) cout << x << " "; cout << "\n";
	}
	
	return 0;
}
