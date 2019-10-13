#include <iostream>
#include <stdlib.h>
#include <stack>
#include <string>
#include <ctype.h>



using namespace std;

int main(){

	string s = "3 6 + 8 4 / -";

	  while (s) {

    	if( stoi(s)){
    		
    		cout << s << "digit" << endl;
    	}else{
    		
    		cout << s << "tempChar" << endl;
    		
    	}
        cout << s << endl;
    }

	return 0;

}