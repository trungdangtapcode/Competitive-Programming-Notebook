#include<bits/stdc++.h>

using namespace std;
int n;
multiset<long long> ms;
bool check(long long x){
	if (ms.count(x)){
		ms.erase(ms.find(x));
		return 1;
	}
	return (x!=0&&check(x/2)&&check(x-x/2));
}
void solve(){
	cin >> n;
	long long sum = 0;
	ms.clear();
	for (int i = 1; i <= n; i++){
		int a; cin >> a;
//		if (a==1){
//			sum++;
//			continue;
//		}
		sum += a;
		ms.insert(a);
	}
	cout << (check(sum)?"YES":"NO") << "\n";
	
	/*
	while (ms.size()>1){
		int u = *ms.begin(); ms.erase(ms.begin());
		if (!ms.count(u+1)){
			if (!ms.count(u)){
				cout << "NO\n";
				return;
			}
			ms.erase(ms.find(u));
			ms.insert(2*u);
		} else {
			ms.erase(ms.find(u+1));
			ms.insert(2*u+1);
		}
	}
	cout << "YES\n";
	*/
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

