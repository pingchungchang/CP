#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 1e5+10;
ll dif[mxn],arr[mxn];
ll pos = 0,neg = 0;
int n;

void del(int k){
	if(k>n)return;
	else if(k == 1)return;
	if(dif[k]>0)pos -= dif[k];
	else neg -= abs(dif[k]);
	return;
}
void add(int k){
	if(k>n)return;
	else if(k == 1)return;
	if(dif[k]>0)pos += dif[k];
	else neg += abs(dif[k]);
}
ll calc(ll k,ll dx){
	ll ta = pos-k,tb = neg-k;
	return ta+tb<=dx;
}
ll getans(){
	ll dx = neg-arr[1];
	if(dx>=0){
		ll l = -1e9-10,r = max(pos,neg);
		//cout<<dx<<":"<<pos<<' '<<neg<<'\n';
		while(l != r){
			ll mid = l+(r-l)/2;
			if(calc(mid,dx))r = mid;
			else l = mid+1;
		}
		return l;
	}
	else{
		if(max(neg,pos)-min(neg,pos)<=abs(dx))return max(neg,pos);
		else return (abs(dx)-(max(neg,pos)-min(neg,pos))+1)/2+max(neg,pos);
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i = 2;i<=n;i++){
		dif[i] = arr[i]-arr[i-1];
		if(dif[i]>0)pos += dif[i];
		else neg += abs(dif[i]);
	}
	cout<<getans()<<'\n';
	int q;
	cin>>q;
	while(q--){
		ll l,r,v;
		cin>>l>>r>>v;
		del(l);
		dif[l] += v;
		add(l);
		del(r+1);
		dif[r+1] -= v;
		add(r+1);
		if(l == 1)arr[1] += v;
		cout<<getans()<<'\n';
	}
	return 0;
}
