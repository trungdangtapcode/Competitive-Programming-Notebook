#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;

int main(){
	vector<ii> x = {
		{1,1},
		{1,2},
		{1,3},
		{2,4},
		{2,5}
	};
	
	int dem = 0;
	do{
		for (int i = 0; i < 4; i++) if (x[i].first==x[i+1].first&&x[i].second==1&&x[i+1].second==2){
			cout << ++dem << ": ";
			for (int i = 0; i < 5; i++) cout << x[i].first << "(" << x[i].second << ") ";
			cout << endl;
			break;
		}
		 
		
	} while (next_permutation(x.begin(),x.end()));
	
	return 0;
}
