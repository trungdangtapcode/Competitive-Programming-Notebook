#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int n, m, pi[maxN], d[maxN], ch[maxN], y[maxN];
string s;
const int p = 1e9+7;
int main(){
	cin >> n >> m;
	cin >> s;
	int sl = s.length();
	s = "#" + s;
	pi[1] = 0;
	vector<int> vec;
	vec.push_back(1);
	for (int i = 2, r = 1, cr = -1; i < s.length(); i++){
		if (i<=r) pi[i] = min(pi[i-cr+1],r-i+1);
		while (pi[i]+i<s.length()&&s[pi[i]+1]==s[i+pi[i]]){
			pi[i]++;
//			cout << pi[i]+i << "\n";
			if (pi[i]+i>r){
				r = pi[i] + i - 1;
				cr = i;
			}
		}
		if (pi[i]+i==s.length()){
//			cout << i << "..\n";
			ch[i] = 1;
			vec.push_back(i);
		}
//		cout << i << " = " << pi[i] << "\n";
	}
//	cout << sl << "\n";
//	for (int x: vec) cout << x << "\n";
	for (int i = 1; i <= m; i++){
		cin >> y[i];
		if (i>1&&y[i]-y[i-1]<sl&&!ch[(y[i]-y[i-1])+1]){
			cout << 0 << "\n";
//			cout << i << "|n";
//			d[y[i-1]]++;
//			d[y[i]+1]--;
//			cout << ch[sl-(y[i]-y[i-1])+1] << " " << sl-(y[i]-y[i-1])+1<< "ch\n";
			return 0;
		}
		d[y[i]]++;
		d[y[i]+sl]--;
	}
	int res= 1;
	for (int i = 1; i <= n; i++){
		d[i] += d[i-1];
		if (d[i]==0){
			res = (1ll*res*26)%p;
		}
	}
	cout << res;
	
	return 0;
}
