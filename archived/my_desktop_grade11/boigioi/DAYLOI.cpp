#include <bits/stdc++.h>

using namespace std;
int n;
long long int a[10005], f1[10010], f2[10005];
int main(){
	//memset(f,1,sizeof(f));
	
	ifstream fi("DAYLOI.INP");
	ofstream fo("DAYLOI.OUT");
	
	fi >> n;
	int res = 0;
	for (int i = 0; i < n; i++) fi >> a[i];
	for (int i = n-1; i >= 0; i--){
		f1[i] = 1; 
		for (int j = i; j < n; j++) if (a[j]>a[i]) {
			f1[i] = max(f1[i],f1[j]+1);
		}
	}
	for (int i = 0; i < n; i++){
		f2[i] = 1; 
		for (int j = i; j >= 0; j--) if (a[j]>a[i]) {
			f2[i] = max(f2[i],f2[j]+1);
		}
	}
	//for (int i = 0; i < n; i++) cout << f1[i] << " "; cout << endl;
	//for (int i = 0; i < n; i++) cout << f2[i] << " "; cout << endl;
	for (int i = 0; i < n; i++){
		if (f2[i]>1&&f1[i]>1) res = max(res,(int)(f2[i]+f1[i]-1));
	}
	fo << res;
	fi.close();
	fo.close();
	
	return 0;
}
