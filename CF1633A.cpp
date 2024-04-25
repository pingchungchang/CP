#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	if(n%10>=n%7){
		cout<<n-n%7<<'\n';
	}
	else cout<<n+(7-n%7)<<'\n';
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
