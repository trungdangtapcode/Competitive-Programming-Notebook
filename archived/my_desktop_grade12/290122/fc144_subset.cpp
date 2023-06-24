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
int n, k, res, f[60*150+1][26*150+1], max2, max5;
main(){
	cin >> n >> k;
	for (int t2 = 0; t2 <= 60*n; t2++) for (int t5 = 0; t5 <= 26*n; t5++) f[t2][t5] = 1e9;
	f[0][0] = 0;
	
	for (int i = 0; i < n; i++){
		long long int x;
		cin >> x;
		int cnt2 = 0, cnt5 = 0;
		while (x%2==0) x/=2, cnt2++, max2++;
		while (x%5==0) x/=5, cnt5++, max5++;
		for (int t2 = max2; t2 >= 0; t2--) for (int t5 = max5; t5 >= 0; t5--) if (t2>=cnt2&&t5>=cnt5) f[t2][t5] = min(f[t2][t5],f[t2-cnt2][t5-cnt5]+1);
	}
	int res = 0;
	for (int t2 = 0; t2 <= 60*n; t2++) for (int t5 = 0; t5 <= 26*n; t5++) if (f[t2][t5]<=k) res = max(res,min(t2,t5));
	cout << res;
	
	return 0;
}


/*
#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
bool check[1005];
int n, k, res;
vector<iii> a, b, c;
int main(){
	cin >> n >> k;
	for (int i = 0, x; i < n; i++){
		cin >> x;
		int cnt2 = 0, cnt5 =0;
		while (x%2==0) x/=2, cnt2++;
		while (x%5==0) x/=5, cnt5++;
		a.push_back({{cnt2,cnt5},i});
		b.push_back({{cnt2,cnt5},i});
		c.push_back({{cnt2,cnt5},i});
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end(),[](iii a, iii b){
		return (a.first.second==b.first.second?a.first.first>b.first.first:a.first.second>b.first.second);
	});
	sort(c.begin(),c.end(),[](iii a, iii b){
		int cnta = min(a.first.second,a.first.first), cntb = min(b.first.second,b.first.first);
		return (cnta==cntb?a>b:cnta>cntb);
	});
	
	
	for (int i = 0, cnt2 = 0, cnt5 = 0; i < k; i++){
		int cnt2_2 = cnt2, cnt5_2 = cnt5;
		for (int l = 0; l < k-i-1; l++) if (!check1[c[l].second]){
			
		}
		for (int j = 0; j < k-i-1; j++) if (!check1[b[j].second]){
			tmp5 += b[j].first.first;
			tmp2 += b[j].first.second;
		}
		res = max(res,min(tmp2,tmp5));
	}
	cout << res;
	
	
	return 0;
}

*/
