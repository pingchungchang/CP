#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e5+10;
set<string> st;
string arr[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i =1;i<=n;i++)cin>>arr[i];
	for(int i = 0;i<m;i++){
		string k;
		cin>>k;
		st.insert(k);
	}
	for(int i = 1;i<=n;i++){
		if(st.find(arr[i]) != st.end())cout<<"Yes\n";
		else cout<<"No\n";
	}
}
