#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll f(int n){
	if(n>=101)return n-10;
	else return f(f(n+11));
}
int main(){
	int n;
	while(cin>>n){
		if(n==0)return 0;
		cout<<"f91("<<n<<") = "<<f(n)<<'\n';
	}
}
