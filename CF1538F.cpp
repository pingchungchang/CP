#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll f(int n){//get 10^n
	if(n == 0)return 1;
	return 10*f(n-1)+1;
}
ll upper(string s){
}
void solve(){
	ll upper = 0;
	ll lower = 0;
	string a,b;
	ll na,nb;
	cin>>na>>nb;
	a = to_string(na);
	b = to_string(nb);
	while(a.size()!=b.size())a = "0"+a;
	int n = b.size();
	for(int i = 0;i<n;i++){
		upper += 1LL*(b[i]-'0')*f(n-1-i);
		lower += 1LL*(a[i]-'0')*f(n-1-i);
	}
	cout<<upper-lower<<'\n';
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
