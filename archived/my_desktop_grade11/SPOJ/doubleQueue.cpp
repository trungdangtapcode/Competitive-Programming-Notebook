#include <bits/stdc++.h>
#define fix cout << "fixed" << endl;

using namespace std;

typedef pair<int,int> id;
int n, p, k;
set<id> a;
id popMin(){
	id pM = *(a.begin());
	a.erase(a.begin());
	return pM;
}
id popMax(){
	auto it = a.end();
	--it;
	id pM = *(it);
	a.erase(it);
	return pM;
}

int main(){
	while (true) {
		cin >> n;
		if (n==0) return 0;
		if (n==1){
			cin >> k >> p;
			a.insert({p,k});
		}
		if (n==2){
			if (!a.empty()) cout << popMax().second << endl; else cout << 0 << endl;
		}
		if (n==3){
			if (!a.empty()) cout << popMin().second << endl; else cout << 0 << endl;
		}
	}
}
