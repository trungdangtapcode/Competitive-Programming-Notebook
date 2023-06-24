#include <bits/stdc++.h>
#define fix cout << "fixed "  << endl;

using namespace std;
int delta = 18, maxIndex = 1e5;
long long int baseK = 1;
double sumLog[100000];
long long int fac[100000];
string p;
double logP;
long long int modP;

const double esilon = 1e-2;
bool sosanh(double a, double b){
	return (abs(a-b) <= esilon);
}

long long int invertIt(long long int x, long long int p){
	long long int y = p - 2;
    long long int res = 1; 
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1; 
        x = (x * x) % p;
    }
    return res%p;
}

int mod(string num, long long int a)
{
    // Initialize result
    long long int res = 0;
 
    // One by one process all digits of 'num'
    for (int i = 0; i < num.length(); i++)
        res = (res * 10 + (int)num[i] - '0') % a;
 
    return res;
}

bool myEqual(int i, int j){
	return (sosanh(sumLog[j]-sumLog[i-1],logP)&&fac[j]*invertIt(fac[i-1],baseK)%baseK==modP);
}


int main(){
	for (int i = 1; i <= 31; i++) baseK = baseK*2; baseK--; //baseK = 63; baseK = 7;
	
	cin >> p; 
	int l = p.length();
	if (l <= delta) delta = l;
	logP = log(stoll(p.substr(0,delta)))/log(10)+(l-delta);
	modP = mod(p,baseK);//stoll(p.substr(l-delta,delta))%baseK;
	//cout << modP << endl;
	
	sumLog[0] = 0; //math error
	for (int i = 1; i <= maxIndex; i++) sumLog[i] = sumLog[i-1] + log(i)/log(10);//, cout <<i << " " << sumLog[i] << endl;;
	
	fac[0] = 1;
	for (int i = 1; i < maxIndex; i++) fac[i] = fac[i-1]*i%baseK;
	//cout << fac[3] <<" "<< fac[5]*invertIt(fac[4],baseK)%baseK << endl;
	
	int j = 1;
	for (int i = 1; i <= maxIndex; i++){
//		if (myEqual(i,j)){
//			cout << i << " " << j << endl;
//			//cout << fac[j]*invertIt(fac[i-1],baseK)%baseK <<" " <<modP << endl;
//			return 0;
//		}
		while (sumLog[i]-sumLog[j-1] > logP) {if (myEqual(j,i)) {cout << j << " " << i << endl; return 0;	}; j++;}
		//cout << j << " " << i << endl;
		if (myEqual(j,i)) {
			cout << j << " " << i << endl; return 0;
		}
		if (myEqual(j+1,i)){
			cout << j+1 << " " << i << endl; return 0;
		}
		if (myEqual(j-1,i)){
			cout << j-1 << " " << i << endl; return 0;
		}
		if (myEqual(j-2,i)){
			cout << j-3 << " " << i << endl; return 0;
		}
		if (myEqual(j-2,i)){
			cout << j-3 << " " << i << endl; return 0;
		}
	}
	//for (int i = 1; i <= maxIndex; i++) for (int j = i; j <= maxIndex; j++) if (myEqual(i,j)){cout << i << " " << j << endl; return 0;	}
}
