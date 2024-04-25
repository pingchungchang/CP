#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
void solve(){
	ll s = 1;
	for(int i = 0;i<n-1;i++)s*=10;
	for(ll i = sqrt(s);i*i<s*10;i++){
		string s = to_string(i*i);
		bool error = false;
		for(char c:s){
			if((c-'0')%2 != 0)error = true;
		}
		if(error == false){
			cout<<i*i<<'\n';
			return;
		}
	}
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++){
		cin>>n;
		solve();
	}
} 
