#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1e5+10;
vector<int> cnt[31];
int arr[mxn];

void solve(){
	for(auto &i:cnt)i.clear();
	int n;
	cin>>n;
	int q;
	cin>>q;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		for(int j = 0;j<=30;j++){
			if(arr[i]&(1<<j)){
				cnt[j].push_back(i);
				break;
			}
		}
	}
	while(q--){
		int x;
		cin>>x;
		for(int j = x;j<=30;j++){
			while(!cnt[j].empty()){
				auto tmp = cnt[j].back();
				cnt[j].pop_back();
				cnt[x-1].push_back(tmp);
				arr[tmp] += 1<<(x-1);
			}
		}
	}
	for(int i =1;i<=n;i++)cout<<arr[i]<<' ';cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
