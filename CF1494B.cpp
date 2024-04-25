#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	int n,u,r,d,l;
	cin>>n>>u>>r>>d>>l;
	for(int i = 0;i<16;i++){
		int dd,du,dl,dr;
		dd = du = dl = dr = 0;
		if(i&1){
			du--;
			dl--;
		}
		if(i&2){
			du--;
			dr--;
		}
		if(i&4){
			dd--;
			dl--;
		}
		if(i&8){
			dd--;
			dr--;
		}
		du += u;dd += d;dl += l;dr += r;
		int arr[] = {du,dd,dl,dr};
		if(*min_element(arr,arr+4) >=0&&*max_element(arr,arr+4)<=n-2){
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

