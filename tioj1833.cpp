#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<int> v;
int findroot(int a){
	while(a != v[a]){
		v[a] = v[v[a]];
		a = v[a];
	}
	return a;
}
int main(){
	io
	int n,q;
	cin>>n>>q;
	v = vector<int>(n+1);
	for(int i = 1;i<=n;i++)v[i] = i;
	for(int i = 0;i<q;i++){
		string t;
		cin>>t;
		if(t == "Masuta"){
			int a,b;
			cin>>a>>b;
			v[findroot(b)] = findroot(a);
		}
		else{
			int x;
			cin>>x;
			cout<<findroot(x)<<'\n';
		}
	}
}

