#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
map<int,int> mp;
ordered_set st;


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int q;
	cin>>q;
	while(q--){
		string s;
		cin>>s;
		if(s[0] == 'a'){
			int k;
			cin>>k;
			if(mp.find(k) == mp.end()){
				st.insert(k);
			}
			mp[k]++;
		}
		else if(s[0] == 'e'){
			int k;
			cin>>k;
			if(mp.find(k) != mp.end()){
				mp[k]--;
				if(!mp[k]){
					mp.erase(k);
					st.erase(k);
				}
			}
		}
		else{
			int k;
			cin>>k;
			k--;
			cout<<*st.find_by_order(k)<<'\n';
		}
	}
	return 0;
}
