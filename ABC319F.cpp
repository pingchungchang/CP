#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll

const int mxn = 505;
ll dp[1<<11];
vector<int> wall[1<<11];
vector<int> tree[mxn];
struct node{
	ll tp,hp,up;
	node(){
		tp = hp = up = 0;
	}
};

vector<int> potion;
node arr[mxn];
int n;

ll calc(ll hp,vector<int> v,vector<int>& rest){
	priority_queue<pll,vector<pll>,greater<pll>> pq;
	for(auto &i:v)pq.push(make_pair(arr[i].hp,1ll*i));
	rest.clear();
	while(!pq.empty()){
		auto now = pq.top();
		if(arr[now.sc].tp == 2){
			rest.push_back(now.sc);
			pq.pop();
			continue;
		}
		if(now.fs>hp)break;
		pq.pop();
		hp += arr[now.sc].up;
		for(auto nxt:tree[now.sc]){
			pq.push(make_pair(arr[nxt].hp,1ll*nxt));
		}
	}
	while(!pq.empty()){
		rest.push_back(pq.top().sc);
		pq.pop();
	}
	sort(rest.begin(),rest.end());
	return hp;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 2;i<=n;i++){
		int p;
		cin>>p;
		tree[p].push_back(i);
		cin>>arr[i].tp>>arr[i].hp>>arr[i].up;
		if(arr[i].tp == 2)potion.push_back(i);
	}
	arr[1].tp = 1;
	dp[0] = calc(1,vector<int>(1,1),wall[0]);
	for(int i = 1;i<(1<<potion.size());i++){
		for(int j = 0;j<potion.size();j++){
			if(i&(1<<j)){
				int pre = i^(1<<j);
				vector<int> tmp;
				bool flag = false;
				ll hp = dp[pre];
				for(auto &ii:wall[pre]){
					if(potion[j] == ii){
						flag = true;
						hp *= arr[potion[j]].up;
						for(auto nxt:tree[ii])tmp.push_back(nxt);
					}
					else tmp.push_back(ii);
				}
				if(hp>=1e9){
					cout<<"Yes";
					return 0;
				}
				vector<int> re;
				int val = calc(hp,tmp,re);
				if(dp[i]<val){
					wall[i] = re;
					dp[i] = val;
				}
			}
		}
	}
	ll big = 0;
	for(int i = 1;i<=n;i++){
		if(arr[i].tp == 1)big = max(big,arr[i].hp);
	}
	/*
	for(auto &i:potion)cout<<i<<' ';cout<<'\n';
	for(int i = 0;i<(1<<potion.size());i++){
		cout<<i<<":"<<dp[i]<<';';for(auto &j:wall[i])cout<<j<<',';cout<<'\n';
	}
   */
	if(dp[(1<<potion.size())-1]>=big)cout<<"Yes";
	else cout<<"No";
}
