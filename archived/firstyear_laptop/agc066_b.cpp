#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;


vi mulnum(vi a, int k){
	int d = 0;
	for (int i = 0; i < (int)a.size() || d > 0; i++){
		if (i==(int)a.size()) a.push_back(0);
		d += a[i]*k;
		a[i] = d%10;
		d /= 10;
	}
	return a;
}
const int maxN = 1005;
int n;
vi a[maxN];
int s[maxN], c[maxN];
char b[101010];

bool check(){
	for (int i = 0; i < 50; i++){
		if (c[i]>=c[i+1]) return 0;
	}
	return 1;
}

void solve(){
	a[0] = {1};
	s[0] = 1;
	for (int i = 1; i <= 1000; i++){
		a[i] = mulnum(a[i-1],5);
		for (int x: a[i]) s[i] += x; 
	}
	int p = 0;
	while (!check()){
		assert(p+50<=1000);
		for (int i = 0; i <= 50; i++)
			c[i] += s[p+i];
		p++;
	}
	for (int i = 0; i < p; i++){
		for (int j = 0; j < 100; j++) b[i*100+j] = '0';
		for (int j = 0; j < (int)a[50+i].size(); j++){
			b[i*100 + 99-j] += a[50+i][j];
		}
	}
	int pos = 0;
	while (b[pos]=='0') pos++;
	printf("%s\n",b+pos);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

