#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

ll com[110][110];

ll C(ll a,ll b){
	if(com[a][b] != -1)return com[a][b];
	if(b>a)return com[a][b] = 0LL;
	if(b == 0)return com[a][b] = 1;
	return com[a][b] = C(a-1,b)+C(a-1,b-1);
}

void print(ll k){
	string s;
	while(k){
		 s += '0'+k%10;
		 k/=10;
	}
	reverse(s.begin(),s.end());
	cout<<s<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(com,-1,sizeof(com));
	int n,m;
	while(cin>>n>>m){
		if(!n)return 0;
		cout<<C(n+m-1,m)<<'\n';
		//print(C(n+m-1,n-1));
	}
	return 0;
}
