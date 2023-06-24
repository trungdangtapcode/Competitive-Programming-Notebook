#include <bits/stdc++.h>

using namespace std;

int maxN = 1e6;
int n, a, b, k;
int f[1000006];
bool p[1000006];
int s[1000006][10];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	
	memset(f,false,sizeof(f));
	memset(p,true,sizeof(p));
	memset(s,0,sizeof(f));
	for (int i = 2; i * i <= maxN; i++) if (p[i]){
    	for (int j = i*i; j <= maxN; j += i)
			p[j] = false;
    }//f[1] = 0;
	for (int i = 2; i <= maxN; i++) if (p[i]){
		for (int j = i; j <= maxN; j += i){
			f[j]++;
		}
	}
	for (int i = 2; i <= maxN; i++){
		for (int j = 1; j <= 7; j++) if (f[i]==j){
			s[i][j] = s[i-1][j] + 1;
		} else s[i][j] = s[i-1][j];
	}
	
//	for (int i = 2; i <= 200; i++) {
//		for (int j = 1; j <= 7; j++) cout << s[i][j] << " "; cout << endl;
//	}
	
	for (int i = 0; i < n; i++){
		cin >> a >> b >> k;
		cout << s[b][k] - s[a-1][k] << '\n';
	}
	//for (int i = 2; i <= 200; i++) cout << i << " " << f[i] << endl; 
	
	return 0;
}
