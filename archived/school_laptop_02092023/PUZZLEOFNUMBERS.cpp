#include<bits/stdc++.h>

using namespace std;
int memo[55][2];
string a, b, c;
const int p = 1e9+7;
int f(int k, int carry){
	if (k==c.length()) return (carry==0);
	if (memo[k][carry]!=-1) return memo[k][carry];
	int& res = memo[k][carry] = 0;
	int mina = (a.length()!=1&&k==a.length()-1), maxa = 9,
	minb = (b.length()!=1&&k==b.length()-1), maxb = 9;
	if (k>=a.length()) mina = maxa = 0;
	else if (a[k]!='*') mina = maxa = a[k] - '0';
	if (k>=b.length()) minb = maxb = 0;
	else if (b[k]!='*') minb = maxb = b[k] - '0';
	for (int i = mina; i <= maxa; i++) for (int j = minb; j <= maxb; j++)
		if (c[k]=='*'||(i+j+carry)%10==c[k]-'0')
			res += f(k+1,(i+j+carry)/10), res %= p;
	return res; 
}

int main(){
	memset(memo,-1,sizeof(memo));
	cin >> a >> b >> c;
	if (max(a.length(),b.length())>c.length()){
		cout << 0;
		return 0;
	}
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	reverse(c.begin(),c.end());
	cout << f(0,0);
	
	return 0;
}
