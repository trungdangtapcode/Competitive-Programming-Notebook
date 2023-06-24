#include <bits/stdc++.h>

using namespace std;

int n;
string ss, s, ms;
bool bs1[5005];
int scount[3], mcount[5005][3];

//ca + cb + cc = na + nb + nc // 0 0 0 0 0 0 => true => co the chay tu 1 -> n
bool check(int ca, int cb, int cc, int na, int nb, int nc){ //tham lam: all in c
	//cout << ca << " " << cb << " " << cc << "  " << na << " " << nb << " " << nc << endl;
	if (ca<0||cb<0||cc<0||na<0||nb<0||nc<0) return false; //neu Slavko da het chu (scount)
	if (cc+cb<na) return false; //dinh a
	if (min(cb,na)+cc+ca<na+nb) return false; //dinh b
	//if  (min(cb,na)+((cb<na)?)>na+nb) return false;
	if (cc>na+nb) return false; //dinh c
	return true;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	cin >> ss >> ms;
	
	memset(scount,0,sizeof(scount));
	memset(mcount,0,sizeof(mcount));
	for (int i = 0; i < n ; i++){
		scount[ss[i]-'a']++;
	}
	for (int i = n-1; i >= 0; i--){
		for (int j =0; j < 3; j++) mcount[i][j] = mcount[i+1][j];
		mcount[i][ms[i]-'a'] =  mcount[i+1][ms[i]-'a']+1; 
		//cout << i << " "<< ms[i]-'a' << endl;
	}
//	for (int i = 0; i < 3; i++){
//		for (int j = 0; j < n; j++){
//			cout << scount[i] << " ";
//		}
//		cout << endl;
//	}
	
	for (int i = 0; i < n; i++){
		//cout << scount[0] <<" "<< scount[1] << " "<< scount[2] << endl;
		for (int j = 0; j < 3; j++) if (j!=ms[i]-'a'){
			//cout << ms[i] - 'a' <<  " == " << j << endl;
			if (j==0)
				if (check(scount[0]-1,scount[1],scount[2],mcount[i+1][0],mcount[i+1][1],mcount[i+1][2])){
					cout << 'a';
					scount[0]--;
					break;
				}
			if (j==1)
				if (check(scount[0],scount[1]-1,scount[2],mcount[i+1][0],mcount[i+1][1],mcount[i+1][2])){
					cout << 'b';
					scount[1]--;
					break;
				}
			if (j==2)
				if (check(scount[0],scount[1],scount[2]-1,mcount[i+1][0],mcount[i+1][1],mcount[i+1][2])){
					cout << 'c';
					scount[2]--;
					break;
				}
		}
	}
	
	s = "";
	
	//cout << check(0,1,3,1,0,3);
	
	return 0;
}
