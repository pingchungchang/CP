#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	string a,b;
	cin>>a>>b;
	if(min(a,b) == a&&min(a,b) != b){
		cout<<a<<'\n';
		return;
	}
	int n = a.size();
	for(int i = 0;i<n;i++){
		pair<char,int> p = {a.back(),n-1};
		for(int j = n-1;j>=i;j--){
			if(a[j]<p.fs)p = {a[j],j};
		}
		swap(a[i],a[p.sc]);
		if(min(a,b) == a&&min(a,b) != b){
			cout<<a<<'\n';
			return;
		}
		swap(a[i],a[p.sc]);
	}
	cout<<"---\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
