#include <bits/stdc++.h>

using namespace std;
int n, sum[200005], val[800005];
string s;
void reset(){
	memset(val,1,sizeof(val));
}
void update(int x, int y){
	while (x<=8e5){
		val[x] = min(val[x],y);
		x += (x&-x);
	}
}
int getMin(int x){
	int res = 1e7;
	while (x>0){
		res = min(res,val[x]);
		x -= (x&-x);
	}
	return res;
}

int f(char x){
	sum[0] = 0;
	for (int i = 1; i <= n; i++) sum[i] = sum[i-1] + (s[i-1]==x?1:-1);
	reset();
	update(0+2*n,0);
	int res = 0; //cout << x << endl;
	for (int i = 1; i <= n; i++){
//		cout << i << " " << getMin(sum[i]-1+2*n) << endl;
		res = max(res,i-getMin(sum[i]-1+2*n));
		update(sum[i]+2*n,i);
	}
	return res;
}
int main(){
	
	cin >> n >> s;
	cout << max({f('a'),f('b'),f('c')});
	
	return 0;
}


/*
int f(char x){
	sum[0] = 0;
	for (int i = 1; i <= n; i++) sum[i] = sum[i-1] + (s[i-1]==x?1:-1);
	set<pair<int,int>> s;
	int res = 0; 
	s.insert({0,0});
	for (int i = 1, pos; i <= n; i++){
		res = max(res,i-pos+1), s.insert({sum[i],i});
		auto it = s.upper_bound({sum[i],i}); it--;
		pos = (*it).second-1; cout << i << " " << pos << endl;
		
	}
	return res;
}
*/
