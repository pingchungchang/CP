#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	int wa =0,ba = 0,bb = 0,wb = 0;
	int pre = 0;
	for(int i = 1;i<=2020;i++){
		int r = min(n,pre+i);
		if(i%4 == 1||i%4 == 0){
			wa += (r+1)/2-(pre+1)/2;
			ba += r/2-pre/2;
		}
		else{
			wb += (r+1)/2-(pre+1)/2;
			bb += r/2-pre/2;
		}
		pre = r;
	}
	cout<<wa<<' '<<ba<<' '<<wb<<' '<<bb<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
