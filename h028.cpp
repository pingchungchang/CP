#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll inf = 1e9+10;


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,L;
	cin>>n>>L;
	ll arr[n],h[n];
	set<pll> st;
	for(auto &i:arr)cin>>i;
	for(auto &i:h)cin>>i;
	st.insert({0,inf});
	st.insert({L,inf});
	for(int i = 0;i<n;i++)st.insert({arr[i],i});
	bool done[n] = {};
	queue<int> q;
	ll cnt = 0,ans = 0;
	for(int i = 0;i<n;i++){
		if(arr[i]-h[i]>=0&&(i == 0||arr[i]-h[i]>=arr[i-1])){
			st.erase(st.find({arr[i],i}));
			done[i] = true;
			q.push(i);
		}
		else if(arr[i]+h[i]<=L&&(i == n-1||arr[i]+h[i]<=arr[i+1])){
			st.erase(st.find({arr[i],i}));
			done[i] = true;
			q.push(i);
		}
	}
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		//cout<<now<<endl;
		cnt++;
		ans = max(ans,h[now]);
		auto it = st.lower_bound({arr[now],now});
		if(it != --st.end()&&it != st.begin()){
			if(it->fs-h[it->sc] >= 0 && it->fs-h[it->sc]>=prev(it)->fs){
				done[it->sc] = true;
				q.push(it->sc);
				st.erase(it);
			}
		}
		it = --st.lower_bound({arr[now],now});
		if(it != --st.end()&&it != st.begin()){
			if(it->fs+h[it->sc]<=L&&it->fs+h[it->sc]<=next(it)->fs){
				done[it->sc] = true;
				q.push(it->sc);
				st.erase(it);
			}
		}
	}
	cout<<cnt<<'\n'<<ans;
}
