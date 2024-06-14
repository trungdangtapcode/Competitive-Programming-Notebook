#include<bits/stdc++.h>

using namespace std;
int n;
string s;
void print(deque<int> d, int f){
	while (d.size()){
		d.front();
		cout << (d.front()^f);
		d.pop_front();
	}
	cout << "\n";
}
void solve(){
	cin >> n >> s;
	s = " " + s;
	int res = 0;
	for (int k = 1; k <= n; k++){
		deque<int> d;
		int flip = 0;
		for (int i = 1, j = 0; i <= n-k+1; i++){
			while (j < min(i+k-1,n)){
				j++;
				d.push_back((s[j]-'0')^flip);
			}
			if ((d.front()^flip)==0) flip ^= 1;
//			print(d,flip);
//			if ((d.front()^flip)==0) flip ^= 1;
			d.pop_front();
		}
//		return;
		int check = 1;
		while (d.size()){
			if ((d.back()^flip)==0){
				check = 0;
				break;
			}
			d.pop_back();
		}
		if (check) res = max(res,k);
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

