#include<bits/stdc++.h>

using namespace std;
const int maxN = 5e5+5;
int n;
string s;
vector<int> fw, bw;
void solve(){
	cin >> n >> s;
	s = " " + s;
	fw.clear(); bw.clear();
	fw.push_back(0);
	for (int i = 1; i <= n; i++){
		if (s[i]=='>') fw.push_back(i);
		else bw.push_back(i);
	}
	bw.push_back(n+1);
	vector<long long> pref(fw.size(),fw[0]), preb(bw.size(),bw[0]);
	for (int i = 1; i < fw.size(); i++) pref[i] = pref[i-1] + fw[i];
	for (int i = 1; i < bw.size(); i++) preb[i] = preb[i-1] + bw[i];
	int pf = 0, pb = 0;
	for (int i = 1; i <= n; i++){
		while (pf<fw.size()&&fw[pf]<=i) pf++;
		pf--;
		while (pb<bw.size()&&bw[pb]<i) pb++;
		int tmp = min(pf+1,(int)bw.size()-pb);
		long long sumf = pref[pf]-(pf-tmp<0?0:pref[pf-tmp]), sumb = preb[pb+tmp-1]-(pb-1<0?0:preb[pb-1]);
//		cout << i << " " << tmp << " " << sumf << " " << sumb << "\n";
		long long res = -1;
		if (s[i]=='>'){
			if (pf-tmp+1==0){
				res = 2*(sumb-sumf) - 2*bw[pb+tmp-1] + i + fw[pf-tmp+1];
			} else {
				res = 2*(sumb-sumf) - bw[pb+tmp-1] + i;
			}
		} else {
			if (pb+tmp-1==(int)bw.size()-1){
				res = 2*(sumb-sumf) + 2*fw[pf-tmp+1] - i - bw[pb+tmp-1];
			} else {
				res = 2*(sumb-sumf) + fw[pf-tmp+1] - i;
			}
		}
		cout << res << " ";
	}
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

