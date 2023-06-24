#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};
int main()
{
	ifstream fi("Sortlist.inp");
	ofstream fo("Sortlist.out");
    Node* head = NULL;
    Node* last = NULL;
    int n;
    fi >> n;
    for (int i = 0; i < n; i++){
    	Node* x = new Node();
    	int y; fi >> y;
    	if (i==0) {
			head = x;
			x->data = y;
			//x.next = NULL;
		} else {
			last->next = x;
			x->data = y;
		}
		last = x;
	}
	
	Node* x = NULL;
	bool sorted = false;
	while(!sorted) {
	    sorted = true;  
		x = head;
	
	    while(x->next != NULL) {
	        if(x->data > x->next->data) {
	            swap(x->data, x->next->data);
	            sorted = false;
	        }
	       	x = x->next;
	    }       
	}
	
	x = head;
    while(x != NULL) {
       	fo << x->data <<" ";
       	x = x->next;
    }   
	//cout << (head->next->next==NULL);
    fi.close();
    fo.close();
    
    return 0;
}
 
