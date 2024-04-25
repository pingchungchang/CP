#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	pii tmp;
	for(int i = 0;i<k*2;i++)cin>>tmp.fs>>tmp.sc;
	string ans;
	for(int i = 0;i<n-1;i++)ans += 'U';
	for(int i = 0;i<m-1;i++)ans += 'R';
	for(int i = 0;i<n;i++){
		if(i%2 == 0)ans += string(m-1,'L');
		else ans += string(m-1,'R');
		if(i != n-1)ans += 'D';
	}
	cout<<ans.size()<<'\n';
	cout<<ans<<'\n';
}
