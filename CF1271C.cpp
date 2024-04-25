#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	pii s;
	cin>>n>>s.fs>>s.sc;
	int L = 0,U = 0,D = 0,R = 0;
	for(int i = 0;i<n;i++){
		pii p;
		cin>>p.fs>>p.sc;
		if(p.fs<s.fs)L++;
		else if(p.fs>s.fs)R++;
		if(p.sc<s.sc)U++;
		else if(p.sc>s.sc)D++;
	}
	int mx = max({L,U,R,D});
	cout<<mx<<'\n';
	if(mx == L)cout<<s.fs-1<<' '<<s.sc;
	else if(mx == U)cout<<s.fs<<' '<<s.sc-1;
	else if(mx == D)cout<<s.fs<<' '<<s.sc+1;
	else cout<<s.fs+1<<' '<<s.sc;
}
