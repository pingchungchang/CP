#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	int n;
	cin>>n;
	vector<int> v(n+1,0);
	vector<bool>goneto(n+1,0);
	set<int> st;
	for(int i = 1;i<=n;i++){
		cin>>v[i];
		if(v[i]<=0||v[i]>n||st.find(v[i]) != st.end()){
			cout<<-1;
			return 0;
		}
		st.insert(v[i]);
	}
	int ans = 0;
	for(int i = 1;i<=n;i++){
		if(!goneto[i]){
			ans++;
			int now = i;
			while(!goneto[now]){
				goneto[now] = true;
				now = v[now];
			}
		}
	}
	cout<<ans;
}

