#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 3e6+10;
int N;
int arr[mxn],pos[mxn];

void change(int a,int b){
	swap(pos[arr[a]],pos[arr[b]]);
	swap(arr[a],arr[b]);
	a = N-a+1,b = N-b+1;
	swap(pos[arr[a]],pos[arr[b]]);
	swap(arr[a],arr[b]);
	return;
}

void solve(){
	cin>>N;
	for(int i = 1;i<=N;i++)cin>>arr[i],pos[arr[i]] = i;
	vector<pii> ans;
	for(int i = 1;i+i<=N;i++){
		if(pos[i] == i)continue;
		ans.push_back(pii(i,pos[i]));
		change(i,pos[i]);
	}
	for(int i = 1;i<=N;i++){
		if(arr[i] != i){
			cout<<"-1\n";
			return;
		}
	}
	cout<<ans.size()<<' '<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i.fs<<' '<<i.sc<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
