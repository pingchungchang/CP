#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n;
	cin>>n;
	string s;
	while(n !=0){
		if((n&1) == 1)s = '2'+s;
		else s = '0'+s;
		n>>=1;
	}
	cout<<s;
}
