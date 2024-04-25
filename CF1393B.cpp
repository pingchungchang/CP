#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	map<int,int> cnt,mp;
	set<int> two;
	set<int> four;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		cnt[k]++;
		if(cnt[k]>=2)two.insert(k);
		if(cnt[k]>=4){
			two.erase(k);
			four.insert(k);
		}
	}
	int q;
	cin>>q;
	while(q--){
		char c;
		int k;
		cin>>c>>k;
		if(c == '+'){
			cnt[k]++;
			if(cnt[k]>=2)two.insert(k);
			if(cnt[k]>=4){
				two.erase(k);
				four.insert(k);
			}
		}
		else{
			cnt[k]--;
			if(cnt[k]<4&&four.find(k) != four.end())four.erase(k),two.insert(k);
			if(cnt[k]<2&&two.find(k) != two.end())two.erase(k);
		}
		if(four.size()>=2){
			cout<<"YES\n";
		}
		else if(four.size() == 0){
			cout<<"NO\n";
		}
		else{
			int c = 0;
			c += two.size()+(cnt[*four.begin()]-4)/2;
			if(c>=2)cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	return 0;
}
