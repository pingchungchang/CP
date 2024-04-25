#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void solve(){
	int d,l;
	cin>>d>>l;
	int now = 0;
	l--;
	for(int i = 1;i<d;i++){
		if(l%2 != 0){
			now = now*2+2;
		}
		else now = now*2+1;
		l/=2;
	}
	cout<<now+1<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}

