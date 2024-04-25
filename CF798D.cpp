#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const ll mxn = 1e5+10;
int n;
vector<int> ans;
tlll arr[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>get<0>(arr[i]);
		get<2>(arr[i]) = i;
	}
	for(int i = 1;i<=n;++i)cin>>get<1>(arr[i]);
	sort(arr+1,arr+n+1,greater<tlll>());
	ans.push_back(get<2>(arr[1]));
	for(int i = 3;i<=n;i+=2){
		if(get<1>(arr[i-1])>get<1>(arr[i]))ans.push_back(get<2>(arr[i-1]));
		else ans.push_back(get<2>(arr[i]));
	}
	if(!(n&1))ans.push_back(get<2>(arr[n]));
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i<<' ';
}
