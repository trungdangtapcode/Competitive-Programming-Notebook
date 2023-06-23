#include<bits/stdc++.h>

using namespace std;

int n, s, a[100005], res = 1e9;

stack<pair<bitset<1001>,int>> s1, s2; //s1[..3.2.1] s2[..7.8.9]: ra va vao

void them(int x){
	bitset<1001> tmp = s2.top().first;
	s2.push({tmp|(tmp<<x),x});
}
void xoa(){
	if (s1.size()==1){
		while (s2.size()>1){
			int x = s2.top().second; s2.pop();
			bitset<1001> tmp = s1.top().first;
			s1.push({tmp|(tmp<<x),x});
		}
	}
	s1.pop();
}
bool check(){
	bitset<1001> x = s1.top().first, y = s2.top().first;
	for (int i = 0; i <= s; i++) if (x[i]&y[s-i]) return true;
	return false;
}

int main(){
	s1.push({bitset<1001>(1),0});
	s2.push({bitset<1001>(1),0});
	
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> a[i];
//	them(1);
//	them(3);
//	xoa();
	for (int i = 0, j = -1; i < n; i++){
		while (j<n-1&&!check()) them(a[++j]);
//		cout << i << " " << j << " " << check() << endl;
		if (check()){
			res = min(res,j-i+1);
		}
		xoa();
	}
	cout << (res==1e9?-1:res);
	
	return 0;
}
