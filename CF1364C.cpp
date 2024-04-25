#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	int n;
	cin>>n;
	vector<int> arr(n);
	bool flag = true;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		if(arr[i]>i+1){
			flag = false;
		}
	}
	if(flag == false){
		cout<<-1<<'\n';
		return;
	}
	set<int> st;
	for(int i = 0;i<arr.back();i++)st.insert(i);
	for(int i = arr.back()+1;st.size()<n;i++){
		st.insert(i);
	}
	vector<int> ans(n);
	for(int i = n-1;i>=0;i--){
		if(i>0&&st.find(arr[i-1]) != st.end()){
			ans[i] = arr[i-1];
			st.erase(arr[i-1]);
		}
		else{
			ans[i] = *st.rbegin();
			st.erase(*st.rbegin());
		}
	}
	for(auto i:ans)cout<<i<<' ';cout<<'\n';return;
}
int main(){
	io
	int t;
	t = 1;
//	cin>>t;
	while(t--)solve();
}

