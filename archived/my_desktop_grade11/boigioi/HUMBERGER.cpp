#include <bits/stdc++.h>

using namespace std;
long long int b = 0, s = 0, c = 0, nb, ns, nc, pb, ps, pc, r;
string st; 

bool check(long long int x){
	long long int can_b = max(b*x-nb,0ll)*pb
	, can_s = max(s*x-ns,0ll)*ps
	, can_c = max(c*x-nc,0ll)*pc;
	
	return (can_b+can_s+can_c<=r);
}

int main(){
	cin >> st;
	for (int i = 0; i < st.length(); i++) {
		if (st[i] == 'B') b++;
		if (st[i] == 'S') s++;
		if (st[i] == 'C') c++;
	};
	cin >> nb >> ns >> nc >> pb >> ps >> pc >> r;
	
	long long int l = 0, h = 1e13, m, res = -1;
	while (l<=h){
		m = (l+h)/2;
		if (check(m)){ //ok, tang hamburger
			res = m;
			l = m + 1;
		} else {
			h = m - 1;
		}
	}
	cout << res;
	
	
	return 0;
}
