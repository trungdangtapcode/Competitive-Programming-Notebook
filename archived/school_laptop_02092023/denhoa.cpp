#include<bits/stdc++.h>

using namespace std;

set<int> s;
multiset<int> ms;
int n, k;
int main(){
	freopen("input.txt","r",stdin);
	cin >> n >> k;
	for (int i = 0, x; i < n; i++){
		cin >> x;
		ms.insert(x);
		s.insert(x);
	}
	while (k){
		if (s.empty()) break;
		cout << *s.begin() << " ";
		ms.erase(ms.find(*s.begin()));
		s.erase(s.begin());
		k--;
	}
	while (k--){
		cout << *ms.begin() << " ";
		ms.erase(ms.begin());
	}
	
	
	return 0;
}
