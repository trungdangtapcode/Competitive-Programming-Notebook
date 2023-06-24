#include <bits/stdc++.h>

using namespace std;
long long int m[30], n, res = 0, check = 0;
string s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	cin >> s;
	n = (long long int)s.length();
	
	memset(m,0,sizeof(m));
	//long long int res = n*(n-1)/2 + 1;
	for (int i = 0; i< n; i++){
		res += i - m[s[i]-'a'];
		m[s[i]-'a']++;
		if (m[s[i]-'a']>1) check = 1; 
		//cai vd khong phai no khong thay doi ma la doi cho 2 chu a (a,a) 
		//nhung khong trung nhung gi da tao (baca, cbaa, acba, aacd, abac)
		//con abca (de bai) chua co nen chi can doi cho (1,4) la co roi
		//vay tat ca la 6: (baca, cbaa, acba, aacd, abac)
		//tom lai la khong co vu res ban dau bang 1 (res=1) (do tinh la 1 cach, KHONG DOI KHONG TINH LA 1 CACH)
		//ma la cai ma cai cach no doi roi ma ra giong de nhung chua trung voi ai van tinh la 1 cach (dac biet)
	}
	cout << res + check;
	return 0;
}


//#include <bits/stdc++.h>
//
//using namespace std;
//long long int m[30], n, res = 0;
//string s;
//
//int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	
//	
//	cin >> s;
//	n = (long long int)s.length();
//	
//	memset(m,0,sizeof(m));
//	//long long int res = n*(n-1)/2 + 1;
//	for (int i = 0; i< n; i++){
//		//res += i - m[s[i]-'a'];
//		m[s[i]-'a']++;
//	}
//	for (int i = 0; i <= 'z'-'a'; i++)res += (n-m[i])*m[i]; res /= 2;
//	for (int i = 0; i <= 'z'-'a'; i++) if (m[i]>1) res++;
//	
//	if (n<100) {cout << res; return 0;}
//	
//	memset(m,0,sizeof(m));
//	res = 1;
//	for (int i = 0; i< n; i++){
//		res += i - m[s[i]-'a'];
//		m[s[i]-'a']++;
//	}
//	cout << res;
//	return 0;
//}

