#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	string arr[n];
	set<string> st;
	int z = 0,o = 0,oz = 0;
	for(int i = 0;i<n;i++){
		string s;
		cin>>s;
		arr[i] = s;
		if(s[0] != s.back())oz = 1;
		else{
			if(s[0] == '0')o=1;
			else z = 1;
			continue;
		}
		string rs = s;
		reverse(rs.begin(),rs.end());
		if(st.find(rs) != st.end())st.erase(rs);
		else st.insert(s);
	}
	if(!oz){
		if(!o||!z){
			cout<<"0\n";
		}
		else cout<<"-1\n";
		return;
	}
	deque<int> va,vb;
	for(int i = 0;i<n;i++){
		if(st.find(arr[i]) != st.end()){
			if(arr[i][0] == '0')va.push_back(i+1);
			else vb.push_back(i+1);
		}
	}
	vector<int> ans;
	while(abs((int)va.size()-(int)vb.size())>1){
		if(va.size()>vb.size()){
			ans.push_back(va.back());
			vb.push_front(va.back());
			va.pop_back();
		}
		else{
			ans.push_back(vb.back());
			va.push_front(vb.back());
			vb.pop_back();
		}
	}
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
