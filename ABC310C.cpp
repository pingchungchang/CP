#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	set<string> st;
	for(int i = 0;i<n;i++){
		string s;
		cin>>s;
		string rs = s;reverse(rs.begin(),rs.end());
		string arr[] = {s,rs};
		sort(arr,arr+2);
		st.insert(arr[0]);
	}
	cout<<st.size();
}
