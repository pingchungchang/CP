#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll



main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	pii arr[n];
	for(auto &i:arr)cin>>i.fs>>i.sc;
	pii ans[n];
	for(int i = 0;i<n;i++){
		bool flag = true;
		for(int j = i-1;j>=0;j--){
			pii ta = {arr[i].fs,arr[i].fs+arr[i].sc-1},tb = ans[j];
			if(ta.fs == tb.fs)flag = false;
			if(ta.fs>tb.fs)swap(ta,tb);
			if(ta.sc>=tb.fs)flag = false;
		}
		if(flag){
			ans[i] = {arr[i].fs,arr[i].fs+arr[i].sc-1};
			continue;
		}
		vector<pii> all;
		for(int j = i-1;j>=0;j--)all.push_back(ans[j]);
		sort(all.begin(),all.end());
		int now = 1;
		for(auto &j:all){
			if(now+arr[i].sc-1<j.fs){
				ans[i] = {now,now+arr[i].sc-1};
				flag = true;
				break;
			}
			now = j.sc+1;
		}
		if(!flag)ans[i] = {now,now+arr[i].sc-1};
	}
	for(auto &i:ans)cout<<i.fs<<' '<<i.sc<<'\n';
	return 0;
}
