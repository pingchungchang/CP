#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	int a,b;
	cin>>a>>b;
	string s;
	int k;
	int sum = a+b;
	if(a>b)k = 0;
	else k = 1;
	for(int i = 0;i<sum;i++){
		if(i%2==k&& a != 0){
			s += "0";
			a--;
		}
		else if(i%2==k && a == 0){
			s += "1";
			b--;
		}
		else if(b != 0){
			s += '1';
			b--;
		}
		else{
			s += '0';
			a--;
		}
	}
	cout<<s<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

