#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
void solve(){
	int n;
	cin>>n;
	int arr[n];
	deque<int> ans;
	for(int i = 0;i<n;i++)cin>>arr[i];
	int p1 = 0,p2 = n-1;
	if(*max_element(arr,arr+n) != max(arr[0],arr[n-1])){
		cout<<"-1\n";
		return;
	}
	if(arr[0]>=arr[n-1])ans.push_back(arr[p1++]);
	else ans.push_back(arr[p2--]);
	while(p1<=p2){
		if(arr[p1]<ans.back())ans.push_front(arr[p1++]);
		else if(arr[p2]>ans.front())ans.push_back(arr[p2--]);
		else{
			cout<<"-1\n";
			return;
		}
	}
	for(auto &i:ans)cout<<i<<' ';
	cout<<'\n';	
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

