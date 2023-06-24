#include<bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")

using namespace std;
long long x, y;
unordered_map<long long,int> mp;
int s[12000005];
int l = 0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> x >> y;
	cout << x/y << ".";
	x %= y;
	mp[x] = 0;
	while (true){
		x *= 1000,000,000;
		s[l++] = (x/y);
		x %= y;
 		if (mp.count(x)){
			for (int i = l; i > mp[x]; i--) s[i] = s[i-1];
			s[mp[x]] = -1;
			++l;
			s[l++] = -1;
			break;
		}
		mp[x] = l;
	}
	cout.width(9);
	cout.fill('0');
	for (int i = 0; i < l; i++) cout << s[i];
//	cout << s;
	
	
	return 0;
}

/*
#include<bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")

using namespace std;
long long x, y;
unordered_map<long long,int> mp;
char s[12000005];
int l = 0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> x >> y;
	cout << x/y << ".";
	x %= y;
	mp[x] = 0;
	while (true){
		x *= 10;
		s[l++] = (x/y+'0');
		x %= y;
 		if (mp.count(x)){
			for (int i = l; i > mp[x]; i--) s[i] = s[i-1];
			s[mp[x]] = '(';
			++l;
			s[l++] = ')';
			break;
		}
		mp[x] = l;
	}
	for (int i = 0; i < l; i++) cout << s[i];
//	cout << s;
	
	
	return 0;
}
*/
