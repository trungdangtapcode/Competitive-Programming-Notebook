#include<bits/stdc++.h>

using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

const string NAME = "tht21_tphcm_slc_square";

void sinhtest(ostream& cout){
	for (int i = 0; i < 3; i++) cout << rd()%100+1 << " ";
}

int main(){
	int ntest; cin >> ntest;
	for (int i = 1; i <= ntest; i++){
		ofstream inp("input.inp");
		sinhtest(inp);
		inp.close();
		system((NAME+"_assign.exe").c_str());
		system((NAME+"_brute.exe").c_str());
		if (system(("fc output.out output.ans"))){
			cout << "WRONG!\n";
			return 0;
		}
		cout << "OK!\n";
	}
		
	return 0;
}
