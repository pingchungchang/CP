#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn =1e6+10;
int buck[mxn];
int good;
vector<int> ans;

void add(int k){
	if(buck[k] == 1)good++;
	buck[k]++;
	return;
}
void del(int k){
	buck[k]--;
	if(buck[k] == 1)good--;
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m,k;
	cin>>n>>m>>k;
	ll len = 0,cnt = 0;
	int p = 0;
	int now = 1;
	if(k<n){
		cout<<-1;
		return 0;
	}
	k -= n;
	for(int i = 0;i<n;i++){
		ans.push_back(now);
		now++;
		if(now>m)now -= m;
		add(ans.back());
		while(good)del(ans[p++]);
		//for(auto &j:ans)cout<<j<<' ';cout<<":"<<p<<' '<<cnt<<' '<<k<<endl;
		if(i-p+cnt>k){
			del(ans.back());
			ans.pop_back();
			ll need = k-cnt;
			ans.push_back(ans.end()[-need-1]);
			add(ans.back());
			cnt = k;
		}
		else cnt += i-p;
	}
	if(cnt != k)cout<<-1<<'\n';
	else for(auto &i:ans)cout<<i<<' ';
}
