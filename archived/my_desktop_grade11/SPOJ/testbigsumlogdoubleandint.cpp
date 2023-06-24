#include <bits/stdc++.h>
#define fix cout << "fixed "  << endl;

using namespace std;

int main(){
	
	sumLog[0] = 0; //math error
	for (int i = 1; i <= maxIndex; i++) sumLog[i] = sumLog[i-1] + log(i)/log(10), cout <<i << " " << sumLog[i] << endl;;
	
}
