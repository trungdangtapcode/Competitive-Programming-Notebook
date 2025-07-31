#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, a[maxN];
void solve(){
	cin >> n;
	deque<int> d;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		d.push_back(a[i]);
	}
	int last = -1;
	string res;
	string s[] = {"LR","RL"};
	for (; ; d.size()>1){
		int u = d.front(), v = d.back();
//		cout << "hi\n" << d.size() << "\n";
		int rev = u>v;
		if (u>v) swap(u,v);
		int ans = (last<u);
//		cout << d.size() << " " << u << " " << v  << ": " << last << " " << u << "\n";
		res += s[ans^rev];
		d.pop_front(), d.pop_back();
		last = (ans^rev?u:v);
		if (d.size()<=1) break;
	}
	if (d.size())
	res += "L";
	cout << res << "\n";
	
	int ll = 1, rr = n;
	vector<int> tmp;
	for (int i = 0; i < n; i++){
//		cout << a[i] << " ";
		if (res[i]=='L'){
			tmp.push_back(a[ll]);
//			cout << a[ll] << "l\n";
			ll++;
		} else {
//			cout << a[rr] << "r\n";
			tmp.push_back(a[rr--]);
		}
	}
//	cout << tmp.size() << " " << ll << " " <<  rr << "\n";
	for (int i = 0; i < n; i++){
//		cout << tmp[i] << " ";
	}
//	cout << "\n";
}

int32_t main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

