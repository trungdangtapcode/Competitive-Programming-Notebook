#include<bits/stdc++.h>

using namespace std;

int convert(long long int x){
	int res = 0;
	vector<bool> v;
	while (x){
		v.push_back(x&1);
		x/= 10;
	}
	reverse(v.begin(),v.end());
	for (int y: v) res = res*2+y;
	return res;
}
int q, x, cnt[(1<<18)+5];
long long int y;
char c;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> q;
	while (q--){
		cin >> c >> y;
		x = convert(y);
		if (c=='+'){
			cnt[x]++;
		} else if (c=='-'){
			cnt[x]--;
		} else {
			cout << cnt[x] << "\n";
		}
	}
	
	return 0;
}
