#include <bits/stdc++.h>
//HDCS -> {3,2,1,0}
//AKQJT9 -> {1,12,11,10,9}

using namespace std;
typedef pair<int,int> ii;
ii a[5];

ii convert(string s){
	ii res;
	if (s[0]>='2'&&s[0]<='9') res.first = s[0]-'0';
	else if (s[0]=='T') res.first = 10;
	else if (s[0]=='J') res.first = 11;
	else if (s[0]=='Q') res.first = 12;
	else if (s[0]=='K') res.first = 13;
	else res.first = 1;
	if (s[1]=='H') res.second = 4;
	else if (s[1]=='D') res.second = 3;
	else if (s[1]=='C') res.second = 2;
	else res.second = 1;
	return res;
}
bool isMauThau(){
	for (int i = 0; i < 5; i++) if (a[i].first%2==1) return true;
	return false;
}
bool isDoi(){
	for (int i = 0; i < 4; i++) if (a[i].first==a[i+1].first) return true;
	return false;
}
bool isThu(){
	int res = 0;
	for (int i = 0; i < 4; i++) if (a[i].first==a[i+1].first) res++;
	return (res==2); //neu ko thanh sam r
}
bool isSam(){
	for (int i = 0; i < 3; i++) if (a[i].first==a[i+1].first&&a[i+1].first==a[i+2].first) return true;
	return false;
}
bool isSanh(){
	return ((a[4].first==a[3].first+1&&a[3].first==a[2].first+1&&a[2].first==a[1].first+1&&a[1].first==a[0].first+1)
		||(a[4].first==13&&a[3].first==12&&a[2].first==11&&a[1].first==10&&a[0].first==1));
}
bool isThung(){
	for (int i = 0; i < 4; i++) if (a[i].second!=a[i+1].second) return false;
	return true;
}
bool isCuLu(){
	return ((a[0].first==a[1].first&&a[1].first==a[2].first&&a[3].first==a[4].first)
		||(a[0].first==a[1].first&&a[2].first==a[3].first&&a[3].first==a[4].first));
}
bool isTuQuy(){
	for (int i = 0; i < 2; i++){
		bool ok = true;
		for (int j = i; j < i+3; j++) if (a[j].first!=a[j+1].first) ok = false;
		if (ok) return true;
	}
	return false;
}
bool isThungPhaSanh(){
	return (isThung()&&isSanh());
}
string solve(){
	if (isThungPhaSanh()) return "Thung pha sanh";
	if (isTuQuy()) return "Tu quy"; //lo viet hoa bi WA :))
	if (isCuLu()) return "Cu lu";
	if (isThung()) return "Thung";
	if (isSanh()) return "Sanh";
	if (isSam()) return "Sam";
	if (isThu()) return "Thu";
	if (isDoi()) return "Doi";
	if (isMauThau()) return "Mau thau";
	cout <<"hi";
}

int main(){
	for (int i = 0; i < 5; i++){
		string s;
		cin >> s;
		a[i] = convert(s);
	}
	sort(a,a+5);
	cout << solve();
}
