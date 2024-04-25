#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1010;
int arr[mxn];
int n;

inline void move(int s,int e){
	vector<int> Q = {0};
	for(int i = 1;i<=n;i++)if(i != s&&i != s+1)Q.push_back(arr[i]);
	vector<int> tmp;
	for(int i = 1;i<=e;i++)tmp.push_back(Q[i]);
	tmp.push_back(arr[s]);
	tmp.push_back(arr[s+1]);
	for(int i = e+1;i<Q.size();i++)tmp.push_back(Q[i]);
	//for(auto &i:tmp)cout<<i<<",";cout<<endl;
	for(int i = 1;i<=n;i++)arr[i] = tmp[i-1];
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	//move(1,1);for(int i = 1;i<=n;i++)cout<<arr[i]<<' ';cout<<endl;return 0;
	vector<pii> ans;
	for(int i = n;i>=3;i--){
		int p = 1;
		while(arr[p] != i)p++;
		//for(int i = 1;i<=n;i++)cout<<arr[i]<<' ';cout<<endl;
		if(p == i)continue;
		if(p == 1){
			ans.push_back({1,1});
			move(1,1);
		}
		p = 1;
		while(arr[p] != i)p++;
		//cout<<p<<' '<<arr[p]<<endl;
		ans.push_back({p-1,i-2});
		move(p-1,i-2);
	}
	for(int i = 1;i<=n;i++){
		if(arr[i] != i){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes\n";
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i.fs<<' '<<i.sc<<'\n';
	return 0;
}
