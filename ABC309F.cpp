#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
tuple<int,int,int> arr[mxn];
vector<int> all;
int bit[mxn];

void modify(int p,int v){
	for(;p<mxn;p+=p&-p)bit[p] = min(bit[p],v);
	return;
}
int getval(int p){
	int re = mxn;
	for(;p>0;p-= p&-p)re = min(re,bit[p]);
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		int tmp[3];
		for(auto &j:tmp)cin>>j;
		sort(tmp,tmp+3);
		arr[i] = make_tuple(tmp[0],tmp[1],tmp[2]);
	}
	all = {-1};
	for(int i = 1;i<=n;i++)all.push_back(get<0>(arr[i]));
	sort(all.begin(),all.end());
	all.resize(unique(all.begin(),all.end())-all.begin());
	for(int i = 1;i<=n;i++)get<0>(arr[i]) = lower_bound(all.begin(),all.end(),get<0>(arr[i]))-all.begin();

	all = {-1};
	for(int i = 1;i<=n;i++)all.push_back(get<1>(arr[i]));
	sort(all.begin(),all.end());
	all.resize(unique(all.begin(),all.end())-all.begin());
	for(int i = 1;i<=n;i++)get<1>(arr[i]) = lower_bound(all.begin(),all.end(),get<1>(arr[i]))-all.begin();

	all = {-1};
	for(int i = 1;i<=n;i++)all.push_back(get<2>(arr[i]));
	sort(all.begin(),all.end());
	all.resize(unique(all.begin(),all.end())-all.begin());
	for(int i = 1;i<=n;i++)get<2>(arr[i]) = lower_bound(all.begin(),all.end(),get<2>(arr[i]))-all.begin();

	fill(bit,bit+mxn,mxn);
	sort(arr+1,arr+n+1);
	int pt = 1;
	for(int i = 1;i<=n;i++){
		while(pt<=n&&get<0>(arr[pt])<get<0>(arr[i])){
			modify(get<1>(arr[pt]),get<2>(arr[pt]));
			pt++;
		}
		if(getval(get<1>(arr[i])-1)<get<2>(arr[i])){
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
	return 0;
}
