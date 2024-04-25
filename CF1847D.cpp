#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;


typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
#define int ll 
#define ll long long
#define pll pair<int,int>
#define pii pll
#define fs first
#define sc second

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m,q;
	cin>>n>>m>>q;
	string s;
	cin>>s;
	vector<pll> v;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		v.push_back({a,b});
	}
	vector<int> vv;
	set<int> st;
	for(int i = 0;i<n;i++)st.insert(i);
	for(auto &i:v){
		auto it = st.lower_bound(i.fs);
		vector<int> tmp;
		while(it != st.end()&&*it<=i.sc){
			vv.push_back(*it);
			tmp.push_back(*it);
			it++;
		}
		for(auto &j:tmp)st.erase(j);
	}
	int pos[n];
	ordered_set os;
	fill(pos,pos+n,-1);
	for(int i = 0;i<vv.size();i++){
		pos[vv[i]] = i;
	}
	int len = vv.size();
	for(int i = 0;i<n;i++){
		if(pos[i] == -1){
			pos[i] = vv.size();
			vv.push_back(i);
		}
	}
	int cnt = 0;
	for(int i = 0;i<vv.size();i++){
		if(s[vv[i]] == '1')os.insert(i);
	}

	/*
	cout<<'\n';
	for(auto &i:vv)cout<<i<<' ';cout<<'\n';
	cout<<os.order_of_key(1)<<'\n'<<'\n';

   */

	while(q--){
		int p;
		cin>>p;
		p--;
		if(s[p] == '1'){
			os.erase(pos[p]);
			s[p] = '0';
		}
		else{
			os.insert(pos[p]);
			s[p] = '1';
		}
		if(os.empty())cout<<"0\n";
		else{
			int cc = min(len,(ll)os.size());
			cout<<cc-os.order_of_key(cc)<<'\n';
		}
		/*
		cout<<p<<":"<<pos[p]<<'\n';
		for(auto &i:os)cout<<vv[i]<<',';cout<<'\n';
	   */
	}
	return 0;
}
