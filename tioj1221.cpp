#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 5e5+10;
const int inf = 1e9;
int n,k,p;
pii arr[mxn];
int pre[mxn];
multiset<int> st;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k>>p;
	for(int i = 1;i<=p;i++){
		cin>>arr[i].fs;
		arr[i].sc = inf;
		arr[pre[arr[i].fs]].sc = i;
		pre[arr[i].fs] = i;
	}
	//for(int i = 1;i<=p;i++)cout<<arr[i].sc<<' ';return 0;
	for(int i = 0;i<k;i++)st.insert(inf);
	int ans = 0;
	for(int i = 1;i<=p;i++){
		//cout<<i<<":";for(auto &j:st)cout<<j<<' ';cout<<endl;
		if(st.find(i) != st.end()){
			st.erase(st.find(i));
			st.insert(arr[i].sc);
		}
		else{
			ans++;
			st.erase(st.find(*st.rbegin()));
			st.insert(arr[i].sc);
		}
	}
	cout<<ans;
}
