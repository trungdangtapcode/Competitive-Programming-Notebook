#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int q; cin >> q;
	multiset<int> ml, mr;
	while (q--){
		char c; int l, r;
		cin >> c >> l >> r;
		if (c=='+'){
			ml.insert(l);
			mr.insert(r);
		} else {
			ml.erase(ml.find(l));
			mr.erase(mr.find(r));
		}
		if (ml.empty()){
			cout << "NO\n";
			continue;
		}
		int mx = *ml.rbegin(), mn = *mr.begin();
		cout << (mx<=mn?"NO\n":"YES\n");
	}
	
	return 0;
}
