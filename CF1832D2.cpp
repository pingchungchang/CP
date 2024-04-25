#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


const ll mxn = 2e5+10;

void f(vector<ll> v,vector<pll> req,vector<ll>& ans){
	int n = v.size();
	sort(v.rbegin(),v.rend());
	for(int i = 0;i<n;i++)v[i] += i+1;
	ll small = *min_element(v.begin(),v.end());
	ll pos = min_element(v.begin(),v.end())-v.begin();
	ll sh = 0;
	for(auto &i:v)sh += i-small;
	//for(auto &i:v)cout<<i<<' ';cout<<small<<','<<pos<<','<<sh<<endl;
	for(auto &i:req){
		assert(i.sc<ans.size());
		if(i.fs<=n+sh*2)ans[i.sc] = small+(i.fs-n+pos+1)-(pos+1);
		else{
			ll mv = i.fs-n-sh*2;
			mv>>=1;
			ans[i.sc] = small + (i.fs-n+pos+1)-(pos+1)-(mv+n-1)/n;
		}
	}
	return;
}
void f2(vector<ll> v,vector<pll> req,vector<ll> &ans){
	sort(v.begin(),v.end());
	ll lst = v.back();v.pop_back();
	ll n = v.size();
	reverse(v.begin(),v.end());
	for(int i = 0;i<n;i++)v[i] += i+1;
	ll small = *min_element(v.begin(),v.end());
	ll pos = min_element(v.begin(),v.end())-v.begin();
	ll sh = 0;
	for(auto &i:v)sh += i-small;
	for(auto &i:req){
		ll ss = small+i.fs-n+pos+1-pos-1;
		if(i.fs<=n+sh*2){
			ans[i.sc] = min(lst,small+i.fs-n+pos+1-(pos+1));
			continue;
		}
		if(lst>=ss){
			ll m = sh+lst-ss;
			if(i.fs<=m*2+n)ans[i.sc] = small+i.fs-n+pos+1-pos-1;
			else{
				ll mv = i.fs-n-m*2;
				mv>>=1;
				ans[i.sc] = small + (i.fs-n+pos+1)-(pos+1)-(mv+v.size())/(v.size()+1);
			}
		}
		else{
			if((sh+1LL*v.size()*(ss-lst))*2+n>=i.fs)ans[i.sc] = lst;
			else{
				//cout<<i.sc<<":"<<ss<<endl;
				i.fs -= n;
				i.fs>>=1;
				i.fs -= sh+1LL*v.size()*(ss-lst);
				ans[i.sc] = lst-(i.fs+v.size())/(v.size()+1);
			}
		}
	}
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,q;
	cin>>n>>q;
	vector<ll> v,ans;
	v = vector<ll>(n,-1);
	for(auto &i:v)cin>>i;
	sort(v.begin(),v.end());
	vector<pll> r1,r2;
	vector<pll> small;
	ans = vector<ll>(q,-1);
	if(n == 1){
		while(q--){
			int k;
			cin>>k;
			if(k&1){
				cout<<v[0]+k-(k-1)/2<<' ';
			}
			else{
				cout<<v[0]-k/2<<' ';
			}
		}
	}
	for(int i = 0;i<q;i++){
		int k;
		cin>>k;
		if(k<=n)small.push_back(make_pair(k,i));
		else if(k%2 == n%2)r1.push_back(make_pair(k,i));
		else r2.push_back(make_pair(k,i));
	}
	vector<ll> sans(n+1);
	ll p = v[0];
	sans[0] = p;
	for(int i = 1;i<=n;i++){
		p++;
		if(i != n)p = min(p,v[i]);
		sans[i] = p;
	}
	for(auto &i:small){
		ans[i.sc] = sans[i.fs];
	}
	f(v,r1,ans);
	f2(v,r2,ans);
	for(int i = 0;i<q;i++)cout<<ans[i]<<'\n';return 0;
}

/*
if k<n:
precompute by segtree?

else:
if k is same parity as n:
	if move to smallest >= k:
		ans = smallest
	else:
		ans = smallest-(k-move to smallest+n-1)/n+(k-(smallest position)+1)
else:
	trim last element do same

*/
