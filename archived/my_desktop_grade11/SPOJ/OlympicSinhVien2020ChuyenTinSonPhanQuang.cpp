#include <bits/stdc++.h>

using namespace std;
const int maxN = 63; //60
long long int a, b, x,y;
long long int base2[maxN];
long long int phuhop[maxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	base2[0] =1; phuhop[0] = 1;
	for (int i = 1; i <= maxN; i++) base2[i] = base2[i-1]*2, phuhop[i] = base2[i];
	
	cin >> a >> b;
	long long int res =0;
	//cout << (base2[4])*(long long int)(a/base2[4])+((a%base2[4])?base2[4]:0);
	for (int i = 1; i <= maxN; i++){
		//long long int x,y;
		//x = (base2[i])*(long long int)(a/base2[i])+((a%base2[i])?base2[i]:0);
		//y = (base2[i])*(long long int)(b/base2[i]);
		//cout << x << " " << y <<  "  base: " << base2[i]<<endl;
		x = (long long int)(a/base2[i])+((a%base2[i])?1:0);
		y = (long long int)(b/base2[i]);
		//cout << x << " " << y << "    base: " << base2[i] << endl;
		if (x<=y) res += (y-x+1);
	}
	cout << res;
	
	
	return 0;
}
