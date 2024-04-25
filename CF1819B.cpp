#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define int ll

void solve(){
	ll n;
	cin>>n;
	pll arr[n];
	ll area = 0;
	map<ll,vector<ll>> row,col;
	ll mh = 0,mw = 0;
	for(auto &i:arr)cin>>i.fs>>i.sc,area += i.fs*i.sc,mh = max(mh,i.fs),mw = max(mw,i.sc);
	for(int i = 0;i<n;i++){
		row[arr[i].fs].push_back(i);
		col[arr[i].sc].push_back(i);
	}
	vector<pll> ans;
	auto calc = [&](int th,int tw){
		pii tans = {th,tw};
		bool done[n] = {};
		bool flag = true;
		auto trow = row,tcol = col;
		//cout<<tans.fs<<' '<<tans.sc<<endl;
		while(th&&tw){
			if(!flag)break;
			//cout<<th<<' '<<tw<<endl;
			if(trow.find(th) != trow.end()){
				for(auto &i:trow[th]){
					if(done[i])continue;
					if(arr[i].sc>tw){
						flag = false;
						break;
					}
					done[i] = true;
					tw -= arr[i].sc;
				}
				trow.erase(th);
			}
			else if(tcol.find(tw) != tcol.end()){
				for(auto &i:tcol[tw]){
					if(done[i])continue;
					if(arr[i].fs>th){
						flag = false;
						break;
					}
					done[i] = true;
					th -= arr[i].fs;
				}
				tcol.erase(tw);
			}
			else{
				flag = false;
				break;
			}
		}
		for(int i = 0;i<n;i++)if(!done[i])flag = false;
		if(flag)ans.push_back({tans.fs,tans.sc});
	};
	if(area%mh==0)calc(mh,area/mh);
	if(area%mw == 0)calc(area/mw,mw);
	sort(ans.begin(),ans.end());
	ans.resize(unique(ans.begin(),ans.end())-ans.begin());
	assert(ans.size());
	cout<<ans.size()<<'\n';
	for(auto i:ans)cout<<i.fs<<' '<<i.sc<<'\n';
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
