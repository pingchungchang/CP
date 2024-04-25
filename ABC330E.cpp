#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e5+10;
set<int> cans;
multiset<int> st;
int arr[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i = 1;i<=n;i++)cin>>arr[i],st.insert(arr[i]);
	for(int i = 0;i<=5e5;i++){
		if(st.find(i) == st.end()){
			cans.insert(i);
		}
	}
	while(q--){
		int a,b;
		cin>>a>>b;
		st.erase(st.find(arr[a]));
		if(st.find(arr[a]) == st.end())cans.insert(arr[a]);
		arr[a] = b;
		st.insert(arr[a]);
		while(st.find(*cans.begin()) != st.end())cans.erase(cans.begin());
		cout<<*cans.begin()<<'\n';
	}
	return 0;
}
