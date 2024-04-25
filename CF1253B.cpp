#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	deque<pii> ans;
	ans.push_back({0,0});
	set<int> in,done;
	int arr[n];
	for(auto &i:arr)cin>>i;
	int C = 0;
	for(auto &i:arr){
		C++;
		if(i>0){
			if(in.find(i) != in.end()){
				cout<<"-1";
				return;
			}
			if(done.find(i) != done.end()){
				cout<<"-1\n";
				return;
			}
			in.insert(i);
		}
		else{
			i = -i;
			if(in.find(i) == in.end()){
				cout<<"-1\n";
				return;
			}
			in.erase(i);
			done.insert(i);
		}
		if(in.empty()){
			ans.push_back({ans.back().sc+1,C});
			in.clear();
			done.clear();
		}
	}
	ans.pop_front();
	if(!in.empty()){
		cout<<"-1\n";
		return;
	}
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i.sc-i.fs+1<<' ';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
