#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

int ask(int k){
	cout<<"? "<<k<<endl;
	int re;
	cin>>re;
	return re;
}

void solve(){
	int n;
	cin>>n;
	int l = 1,r = n;
	while(r-l>1){
		int mid = (l+r)>>1;
		if(ask(mid) == 0)l = mid;
		else r = mid;
	}
	cout<<"! "<<min(l,r)<<endl;
}
int main(){
	int t = 1;
	while(t--)solve();
}
