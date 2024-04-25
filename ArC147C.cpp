#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

vector<pll> mv;
const int mxc = 1e7+10;
const int mxn = 3e5+10;
pll arr[mxn];
ll ans = 4e18;
ll same = 0;
struct node{
	ll sum,cnt,ctr;
	node(){}
};
node ls,rs;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	//ls,rs: 0:sum 1:cnt 2:contribution
	for(int i = 1;i<=n;i++){
		cin>>arr[i].fs>>arr[i].sc;
		mv.push_back({arr[i].fs,i});
		mv.push_back({arr[i].sc+1,-i});
	}
	sort(mv.rbegin(),mv.rend());
	for(auto &i:mv){
		if(i.sc>0){
			rs.ctr += rs.sum-rs.cnt*arr[i.sc].fs;
			rs.sum+=arr[i.sc].fs;
			rs.cnt++;
		}
	}
	for(ll i = 1;i<mxc;i++){
		while(!mv.empty()&&mv.back().fs == i){
			auto tmp = mv.back();
			mv.pop_back();
			if(tmp.sc>0){
				same++;
				rs.cnt--;
				rs.sum -= arr[tmp.sc].fs;
				rs.ctr -= rs.sum-rs.cnt*arr[tmp.sc].fs;
			}
			else{
				tmp.sc = -tmp.sc;
				same--;
				ls.ctr += ls.cnt*arr[tmp.sc].sc-ls.sum;
				ls.sum += arr[tmp.sc].sc;
				ls.cnt++;
			}
		}
		ll tans = rs.sum-rs.cnt*i+ls.cnt*i-ls.sum;
		tans *= same;
		tans += ls.ctr+rs.ctr+rs.sum*ls.cnt-ls.sum*rs.cnt;
		ans = min(ans,tans);
	}
	cout<<ans;
}
