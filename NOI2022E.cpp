#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 4e5+10;

ll ans[mxn];
int N;
int req[mxn],cost[mxn],used[mxn];
ll sum = 0;
set<pll> st;
int pre = 0;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(used,-1,sizeof(used));
	cin>>N;
	for(int i = 1;i<=N;i++)cin>>req[i];
	req[0] = 0;req[N+1] = N+1;
	for(int i = 1;i<=N;i++)cin>>cost[i],st.insert(pll(cost[i],i));
	bool f = true;

	for(int i = 1;i<=N;i++){
		if(!f);
		else if(req[i] == -1){
			if(!st.empty()){
				used[i] = st.rbegin()->sc;
				sum += st.rbegin()->fs;
				st.erase(*st.rbegin());
			}
		}
		else if(req[pre]>req[i])f = false;
		else{
			for(int j = pre+1;j<i;j++){
				if(used[j] == -1)continue;
				sum -= cost[used[j]];
				st.insert(pll(cost[used[j]],used[j]));
				used[j] = -1;
			}
			used[i] = req[i];
			st.erase(st.find(pll(cost[req[i]],req[i])));
			sum += cost[req[i]];
			vector<pll> v;
			for(int j = req[pre]+1;j<req[i];j++){
				v.push_back(pll(cost[j],j));
				st.erase(st.find(pll(cost[j],j)));
			}
			sort(v.begin(),v.end());
			for(int j = pre+1;j<i;j++){
				if(v.empty())break;
				used[j] = v.back().sc;
				sum += v.back().fs;
				v.pop_back();
			}
			pre = i;
		}
		ans[i] = max(ans[i-1],sum);
		cout<<i<<" "<<sum<<":";for(int j = 1;j<=N;j++)cout<<used[j]<<' ';cout<<endl;
	}

	for(int i = 1;i<=N;i++)cout<<ans[i]<<' ';cout<<'\n';
	return 0;
}
