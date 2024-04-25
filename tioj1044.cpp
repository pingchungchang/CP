#include "lib1044.h"
#include <bits/stdc++.h>
using namespace std;

int main(){
	int l = 0;
	int r = Initialize();
	while(l != r){
		int mid = (l+r)/2;
		if(Guess(mid)){
			r = mid;
		}
		else{
			l = mid+1;
		}
	}
	Report(r);
}
