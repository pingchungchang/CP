#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n;
pii a,b;

void mv(){
	a.fs++,b.fs--;
	a.fs = (a.fs+n-1)%n+1;
	b.fs = (b.fs+n-1)%n+1;
	return;
}
int main(){
	cin>>n>>a.fs>>a.sc>>b.fs>>b.sc;
	bool ans = false;
	if(a.fs == b.fs)ans = true;
	while(a.fs != a.sc&&b.fs != b.sc){
		mv();
		if(a.fs == b.fs)ans = true;
	}
	if(ans)cout<<"Yes";
	else cout<<"NO";
}

