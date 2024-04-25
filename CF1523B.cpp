#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		int tmp;
		cin>>tmp;
	}
	cout<<6*n/2<<'\n';
	for(int i = 1;i<=n/2;i++){
		int s= i,e = n+1-i;
		cout<<"2 "<<s<<' '<<e<<'\n';
		cout<<"1 "<<s<<' '<<e<<'\n';
		cout<<"2 "<<s<<' '<<e<<'\n';
		cout<<"1 "<<s<<' '<<e<<'\n';
		cout<<"2 "<<s<<' '<<e<<'\n';
		cout<<"1 "<<s<<' '<<e<<'\n';
	}
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}


/*
a b
a b-a 2
b b-a 1
b -a 2
b -a-b 1
-a -a-b 2
-a -b 1

a b
a+b b
a+b -a
b -a
b -a-b
-a -a-b
-a -b

a b
a b-a
b b-a
b -a
b -a-b
*/
