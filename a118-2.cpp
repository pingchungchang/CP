#include <bits/stdc++.h>
using namespace std;

int main(){
	int k;
	cin>>k;
	int v = 1<<k;
	if(k%2 == 0&&k != 0){
		v>>=2;
		cout<<v<<' '<<v<<' '<<v<<' '<<v;
	}
	else cout<<0;
	
}
