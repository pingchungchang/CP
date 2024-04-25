#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double


int n,m;
int main(){
	io
	cin>>n>>m;
	vector<string> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	vector<int> vio(m,0);
	for(int i = 1;i<m;i++){
		for(int j = 1;j<n;j++){
			if(v[j][i-1] == 'X'&&v[j-1][i] == 'X')vio[i]++;
		}
	}
	for(int i = 1;i<m;i++)vio[i] += vio[i-1];
	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		if(vio[b-1]-vio[a-1] == 0)cout<<"YES\n";
		else cout<<"NO\n";
	}	
	return 0;
}

