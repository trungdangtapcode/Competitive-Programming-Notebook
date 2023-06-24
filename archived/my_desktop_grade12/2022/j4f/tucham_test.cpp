#include<bits/stdc++.h>

using namespace std;

const string NAME = "a";
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

void sinhtest(ostream& cout){
	for (int i = 1; i <= 100; i++) cout << i << " ";
	
}

int main(){
	
	int ntest;
	cin >> ntest;
	for (int itest = 1; itest <= ntest; itest++){
		ofstream inp((NAME+".inp").c_str());
		sinhtest(inp);
		inp.close();	
	}
	
	return 0;
}
