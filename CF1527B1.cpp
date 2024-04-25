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
	string s;
	cin>>s;
	int cnt = 0;
	for(auto i:s){
		if(i == '0')cnt++;
	}
	string a = "ALICE",b = "BOB";
	if(cnt == 1){
		cout<<"BOB\n";
		return;
	}
	if(cnt == 2){
		cout<<"BOB\n";
		return;
	}
	else if(cnt == 3){
		cout<<"ALICE\n";
		return;
	}
	if(cnt %2 == 1){
		swap(a,b);
		cnt--;
	}
	cout<<b<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

