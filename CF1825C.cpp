#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	ll n,m;
	cin>>n>>m;
	ll lef = 0,rig = 0;
	int taken[m+1] = {};
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		if(k>0)taken[k] = 1;
		else if(k == -1)lef++;
		else rig++;
	}
	for(int i = 1;i<=m;i++)taken[i] += taken[i-1];
	int ans = 0;
	//for(auto &i:taken)cout<<i<<' ';cout<<'\n';
	for(int i = 1;i<=m;i++){
		if(taken[i]== taken[i-1])continue;
		int l = 1,r = i;
		while(l != r){
			//cout<<l<<' '<<r<<endl;
			int mid = (l+r)>>1;
			if(i-mid+1<=taken[i]-taken[mid-1]+lef)r = mid;
			else l = mid+1;;
		}
		int tl = l;
		l = i,r = m;
		while(l != r){
			//cout<<"i"<<l<<' '<<r<<endl;
			int mid = (l+r+1)>>1;
			if(mid-i+1<=taken[mid]-taken[i-1]+rig)l = mid;
			else r = mid-1;
		}
		int tr = l;
		//cout<<i<<":"<<tl<<' '<<tr<<'\n';
		ans = max(ans,tr-tl+1+taken[m]-taken[tr]+taken[tl-1]);
	}
	int tmp = 0;
	for(int i = 1;i<=m;i++){
		if(taken[i] == taken[i-1]&&rig)tmp++,rig--;
	}
	ans = max(ans,tmp+taken[m]);
	tmp = 0;
	for(int i = m;i>=1;i--){
		if(taken[i] == taken[i-1]&&lef)tmp++,lef--;
	}
	ans = max(ans,tmp+taken[m]);
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
