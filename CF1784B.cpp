#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>


void solve(){
	int n;
	cin>>n;
	string arr[n];
	int cnt[n][3] = {};
	string pool = "win";
	for(auto &i:arr)cin>>i;
	vector<int> v[10];
	for(int i = 0;i<n;i++){
		for(int j = 0;j<3;j++)if(arr[i][j] == 'w')cnt[i][0]++;else if(arr[i][j] == 'i')cnt[i][1]++;else cnt[i][2]++;
		vector<int> more,less;
		for(int j = 0;j<3;j++){
			for(int k = 1;k>cnt[i][j];k--)less.push_back(j);
			for(int k = 1;k<cnt[i][j];k++)more.push_back(j);
		}
		while(!more.empty()){
			v[more.back()*3+less.back()].push_back(i);
			more.pop_back();
			less.pop_back();
		}
	}
	vector<tuple<int,int,int>> ans;
	for(int i = 0;i<3;i++){
		for(int j = 0;j<3;j++){
			while(!v[i*3+j].empty()&&!v[j*3+i].empty()){
				ans.push_back(make_tuple(v[i*3+j].back(),v[j*3+i].back(),i*3+j));
				v[i*3+j].pop_back();
				v[j*3+i].pop_back();
			}
		}
	}
	int flag = 10;
	while(flag--){
		for(int i = 0;i<3;i++){
			for(int j = 0;j<3;j++){
				int now = i*3+j;
				for(int k = 0;k<3;k++){
					int nxt = k*3+i;
					if(v[now].empty()||v[nxt].empty())continue;
					ans.push_back(make_tuple(v[now].back(),v[nxt].back(),i*3+k));
					if(!v[j*3+k].empty()){
						ans.push_back(make_tuple(v[j*3+k].back(),v[now].back(),j*3+k));
						v[j*3+k].pop_back();
					}
					else v[k*3+j].push_back(v[now].back());
					v[now].pop_back();
					v[nxt].pop_back();
					k--;
				}
			}
		}

	}
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<get<0>(i)+1<<' '<<pool[get<2>(i)/3]<<' '<<get<1>(i)+1<<' '<<pool[get<2>(i)%3]<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
