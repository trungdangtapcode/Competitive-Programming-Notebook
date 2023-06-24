#include <bits/stdc++.h>

using namespace std;
int n,w = 1e6, h = 0;
string s;
int tro[100005];

int soluong1(char ch){
	int x = ch, res =0;
	//vector <char> sv;
	while (x > 0){
		//sv.push_back((x%2==0?'0':'1'));
		res += (x%2);
		x /= 2;
	}
	//reverse(sv.begin(),sv.end());
	//string s(sv.begin(),sv.end());
	return res;
}

int main(){
	
	//cout << char2stringBIT('b');
	cin >> n >> s;
	s = s + '#';
	tro[0] = -1;
	for (int i = 0; i < n+1; i++){
		if (s[i]=='#'){
			tro[++h] = i;
			w = min(w,tro[h]-tro[h-1]-1);	
			continue;
		}
	}
	int sum1 = 0, sum01 = 0;
	for (int i = 0; i < h; i++) {  //i = h => tan cung cuoi chuoi
		for (int j = 0; j < w; j++){
			sum1 += soluong1(s[tro[i]+1+j]);
			sum01 += 7;
			//cout << s[tro[i]+1+j]  <<"   ";
		}
		//cout << endl;
	}
	cout << h << " " << 7*w << endl;
	cout << fixed << setprecision(9) <<1.0*sum1/(sum01-sum1) << endl;
	
	return 0;
}
