#include <iostream>
#include <math.h>

using namespace std;

//long long int checkxx1(long long int n){
//	long long int delta = sqrt(1+4*n);
//	if (sqrt(1+4*n)-(double)delta!=0) return -1;
//	return (-1+delta)/2;
//}

long long int checkxx1(long long int n){
	long long int l = 1, h = sqrt(n), m;
	while (l<=h){
		m = (l+h)/2;
		//cout << l << " " << h << " " << m << " " << (m*(m+1)-n)<< endl;
		if (m*(m+1)==n) {return m;}
		if (m*(m+1)>n){
			h = m-1;
		} else {
			l = m+1;
		}
	}
	if (m*(m+1)==n) return m; else return -1;
}


long long int last, n,maxK, x;
bool b;
void solve(){
	scanf("%lld",&n);
	b = true;
	maxK = (long long int)pow(n,1.0/3);
	last = 0;
	for (long long int k = 1; k <= maxK; k++) if (n%k==0&&n%(k+1)==0) printf("%lld",k),printf("%c",' '), b = false, last = k;
	x = 0;
	for (long long int k = maxK; k >= 1; k--) if (n%k==0) {
		long long int ndk = n/k;
		x = checkxx1(ndk);
		if (x!=-1&&last!=x)  printf("%lld",x), printf("%c",' '), b = false;
//		while (x*(x+1)<ndk) x++;
//		if (x*(x+1)==ndk&&last!=x) printf("%lld",x), printf("%c",' '), b = false;
	}
	if (b) printf("%d",-1);
	printf("\n");
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	//cout << checkxx1(996146719112);
	int t;
	scanf("%d",&t);
	while (t--) solve();
	
	return 0;
}
