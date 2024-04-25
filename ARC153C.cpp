#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define int ll
#define fs first
#define sc second
#define pii pair<int,int>

const ll sh = 1;

void check(int arr[],int n){
	for(int i = 0;i<n;i++)assert(abs(arr[i])<1e12);
	//for(int i = 1;i<n;i++)assert(arr[i-1]<arr[i]);
	return;
}

void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	if(n == 1){
		cout<<"Yes\n0\n";
		return;
	}
	int sum = 0;
	pii pref = {-1,-1},suf = {-1,-1};
	for(int i = 0;i<n;i++){
		sum += arr[i];
		if(sum == -1)pref.fs = i;
		if(sum == 1)pref.sc = i;
	}
	sum = 0;
	for(int i = n-1;i>=0;i--){
		sum += arr[i];
		if(sum == -1)suf.fs = i;
		if(sum == 1)suf.sc = i;
	}
	ll ans[n];
	sum = 0;
	ll c = 0;
	for(int i = 0;i<n;i++){
		if(arr[i]>0&&(pref.sc>=0||suf.fs>=0))ans[i] = c+= sh;
		else if(arr[i]<0&&(pref.fs>=0||suf.sc>=0))ans[i] = c+= sh;
		else ans[i] = ++c;
		sum += ans[i]*arr[i];
	}
	//for(auto &i:ans)cout<<i<<' ';cout<<endl<<sum<<endl;
	if(sum == 0){
		cout<<"Yes\n";
		for(auto &i:ans){
			cout<<i<<' ';
		}
		return;
	}
	if(sum>0){
		if(pref.sc >= 0){
			for(int i = 0;i<=pref.sc;i++)ans[i] -= sum;
		}
		else if(suf.fs>=0){
			for(int i = n-1;i>=suf.fs;i--)ans[i] += sum;
		}
		else{
			cout<<"No\n";
			return;
		}
	}
	else{
		sum = abs(sum);
		if(pref.fs>=0)for(int i = 0;i<=pref.fs;i++)ans[i] -= sum;
		else if(suf.sc>=0)for(int i = n-1;i>=suf.sc;i--)ans[i] += sum;
		else{
			cout<<"No\n";
			return;
		}
	}
	//cout<<pref.fs<<','<<pref.sc<<','<<suf.fs<<','<<suf.sc<<endl;
	sum = 0;
	for(int i = 0;i<n;i++)sum += ans[i]*arr[i];
	assert(sum == 0);
	check(ans,n);
	cout<<"Yes\n";
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';//cout<<endl;
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
