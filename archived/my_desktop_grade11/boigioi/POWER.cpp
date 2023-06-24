#include <bits/stdc++.h>

//idea (greedy):
//x = p1^x1...pn^xn
//x | n^a (n = p1p2...pn)
//=> a >= max(x1,x2,...,xn) && a >= n (optimize a)
//N^N => a ~ kn => (kn)^(kn) = (k)^(kn)*(n)^(kn)  (n = const)
//x | (k)^(kn)*(n)^(kn) => x / (k)^(kn) |(n)^(kn) (optimize k)

using namespace std;


int a;
map <int, int> f;
int main(){
	cin >> a;
//	int da = 2;
//	while (a>1){
//		int da2;
//		if (a%da) da2 = a/da;
//		if (a%da&&da2!=da) while (a%da2==0) a/=da2, f[da2]++;
//		while (a%da==0) a /= da, f[da]++;
//		da++;
//		if (da*da>a) break;
//	}
	//bool b = true;
	vector <int> v;
	int a0 = a;
	for (int i = 2; i*i <= a0; i++) if (a%i==0){
		int j = a/i; 
		while (a%i==0) a /= i, f[i]++;
		//while (a%j==0) a /= j, v.push_back(j);
		//b = false;
	}
	//if (a>2) {cout << a;return 0;}
//	for (auto& it: v){
//		
//	}
	int myMax = 0;
	int n = 1;
	for (auto& it: f){
		n *= it.first;
		//cout << it.first << " " << it.second<< endl;
		myMax = max(it.second,myMax);
	}
	if (a>2) n *= a;
	int n0 = n;
	while (n0 < myMax) {
		n0 += n;
		map<int, int> g (f);
		int myMaxG = 0, k = n0/n;
		for (auto& it: g){
			while (k%it.first==0) k/=it.first, it.second-=n0;
			myMaxG = max(it.second,myMaxG);
		}
		//cout << n0 << " " << myMaxG << endl;
		if (n0 >= myMaxG){
			cout << n0 << endl;
			return 0;
		}
	}
	cout << n0; 
	
		
	return 0;
}




//Do tinh co so (n) rat kho nen ko the tinh (kn), ta tach thanh (k)*(n)

//N^N => a ~ kn => (kn)^(kn) = (k)^(kn)*(n)^(kn) 
//=> x / (k)^(kn) |(n)^(kn) (optimize kn)


//#include <bits/stdc++.h>
//
//using namespace std;
//
//
//int a;
//map <int, int> f;
//int main(){
//	cin >> a;
////	int da = 2;
////	while (a>1){
////		int da2;
////		if (a%da) da2 = a/da;
////		if (a%da&&da2!=da) while (a%da2==0) a/=da2, f[da2]++;
////		while (a%da==0) a /= da, f[da]++;
////		da++;
////		if (da*da>a) break;
////	}
//	//bool b = true;
//	vector <int> v;
//	int a0 = a;
//	for (int i = 2; i*i <= a0; i++) if (a%i==0){
//		int j = a/i; 
//		while (a%i==0) a /= i, f[i]++;
//		//while (a%j==0) a /= j, v.push_back(j);
//		//b = false;
//	}
//	//if (a>2) {cout << a;return 0;}
////	for (auto& it: v){
////		
////	}
//	int myMax = 0;
//	int n = 1;
//	if (a>2) n *= a;
//	for (int i = 1; i <= a; i++){	
//		for (auto& it: f) if (it.second>0){
//			n *= it.first;
//			it.second--;
//			//cout << it.first << " " << it.second<< endl;
//			myMax = max(it.second,myMax);
//		}
//		if (n>=myMax){
//			cout << n;
//			return 0;
//		}
//	}
//
//	int n0 = 1;
//	while (n0*n < myMax) n0 ++, n0;
//	cout << n0; 
//	
//		
//	return 0;
//}
