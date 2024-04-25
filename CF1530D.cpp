#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		arr[i]--;
	}
	int v[n];
	memset(v,-1,sizeof(v));
	set<int> st;
	for(int i = 0;i<n;i++)st.insert(i);
	for(int i = 0;i<n;i++){
		if(st.find(arr[i]) != st.end()){
			st.erase(arr[i]);
			v[i] = arr[i];
		}
	}
	int ans = n-st.size();
	
	for(int i = 0;i<n;i++){
		if(v[i] == -1){
			v[i] = *st.rbegin();
			st.erase(*st.rbegin());
		}
		if(v[i] == i){
			v[i] = -1;
			for(int j = 0;j<n;j++){
				if(v[j] == arr[i]){
					v[j] = i;
					break;
				}
			}
			v[i] = arr[i];
		}
	}
	cout<<ans<<'\n';
	for(auto i:v)cout<<i+1<<' ';
	cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}

/*
2
3
2 1 2
7
6 4 6 2 4 5 6
*/
