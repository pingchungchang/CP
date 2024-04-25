#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
const int inf = 1e9+10;
map<int,pii> fence;
vector<tuple<int,int,int>> v;
int n;
vector<int> lis;
map<int,int> dp;
vector<int> re[mxn];
vector<int> ans;


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		fence[k].fs = i;
	}
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		v.push_back(make_tuple(fence[k].fs,i,k));
		fence[k].sc = i;
	}
	sort(v.rbegin(),v.rend());
	int big = 0;
	for(auto &i:v){
		auto val = -get<1>(i),id = get<2>(i);
		int pos = lower_bound(lis.begin(),lis.end(),val)-lis.begin();
		dp[id] = pos;
		big = max(pos,big);
		if(pos == lis.size())lis.push_back(val);
		else lis[pos] = val;
		//cout<<id<<":"<<pos<<endl;
		re[pos].push_back(id);
	}
	pii now = {0,0};
	/*
	for(int i = 1;i<=big;i++){
		cout<<i<<":";
		for(auto &j:re[i])cout<<j<<' ';cout<<endl;
	}

   */
	for(int i = big;i>=0;i--){
		sort(re[i].rbegin(),re[i].rend());
		for(auto &j:re[i]){
			auto tmp = fence[j];
			if(tmp.fs>now.fs&&tmp.sc>now.sc){
				now = tmp;
				ans.push_back(j);
				break;
			}
		}
	}
	for(auto &i:ans)cout<<i<<' ';
	return 0;
}
