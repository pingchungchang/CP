#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,x,y;
	cin>>n>>x>>y;
	string a,b;
	cin>>a>>b;
	vector<int> v;
	for(int i = 0;i<n;i++){
		if(a[i] != b[i])v.push_back(i);
	}
	if(v.size()&1){
		cout<<-1<<'\n';
		return;
	}
	if(v.size()!=2)cout<<1LL*y*v.size()/2<<'\n';
	else{
		if(v[0]+1 != v[1]){
			cout<<y<<'\n';
		}
		else if(v[0] != 2||v[1] != n-1){
			cout<<min(y*2LL,1LL*x*(v[1]-v[0]))<<'\n';
		}
		else{
			cout<<1LL*x*(v[1]-v[0])<<'\n';
		}
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
