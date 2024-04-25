#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	int pos = 0,neg = 0;
	for(auto &i:v){
		cin>>i;
		if(i>0)pos++;
		else if(i<0)neg++;
	}
	if(neg){
		cout<<"NO\n";
		return;
	}
	if(pos){
		cout<<"YES\n 200\n";
		for(int i = 0;i<200;i++)cout<<i<<' ';cout<<'\n';
	}
	else{
		cout<<"YES\n200\n";
		for(int i = 0;i<200;i++)cout<<-i<<' ';cout<<'\n';
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
