#include <bits/stdc++.h>

using namespace std;
bool isAllEven = false; 
//le -> chan; chan -> chi co the chia 2 => so lan lap /2 chi co the la log(a[i])
//=> worst case: (1+log(max))*n
int n;
vector<int> a;
string s;
int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> s;
	
	long long int res = 0; //sum
	for (int i = 0; i < n; i++) res += a[i];
	for (int i = 0; i < s.length(); i++){
		if (s[i]=='0'){
			for (int j = 0; j < n; j++) if (a[j]%2==0) a[j]/=2, res -= a[j];
			//mat di mot nua a[j]
		}
		if (s[i]=='1'&&!isAllEven){
			for (int j = 0; j < n; j++) if (a[j]%2==1) a[j]--, res--;
			isAllEven = true; //a[] da toan chan va se kbh duoc phuc hoi
		}
		cout << res << '\n';
	}
//	cout << res;
	
	return 0;
}
