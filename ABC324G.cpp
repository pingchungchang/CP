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

typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int mxn = 2e5+10;
ordered_set st1[mxn],st2[mxn];

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		st1[0].insert({i,k});
		st2[0].insert({k,i});
	}
	//cout<<st1[0].order_of_key(make_pair(10,3))<<endl;//upper bound
	cin>>q;
	for(int i = 1;i<=q;i++){
		int t,s,x;
		cin>>t>>s>>x;
		if(t == 1){
			if(x*2>=st1[s].size()){
				vector<pii> add;
				while(st1[s].size()>x){
					pii tmp = *st1[s].rbegin();
					st1[s].erase(tmp);
					st2[s].erase({tmp.sc,tmp.fs});
					add.push_back(tmp);
				}
				sort(add.begin(),add.end());
				for(auto &j:add){
					j.fs = (st1[i].empty()?0ll:st1[i].rbegin()->fs+1);
					st1[i].insert(j);
					st2[i].insert({j.sc,j.fs});
				}
			}
			else{
				vector<pii> add;
				st1[s].swap(st1[i]);
				st2[s].swap(st2[i]);
				while(add.size() < x){
					pii tmp = *st1[i].begin();
					st1[i].erase(tmp);
					st2[i].erase({tmp.sc,tmp.fs});
					add.push_back(tmp);
				}
				sort(add.begin(),add.end());
				for(auto &j:add){
					j.fs = (st1[s].empty()?0ll:st1[s].rbegin()->fs+1);
					st1[s].insert(j);
					st2[s].insert({j.sc,j.fs});
				}
			}
		}
		else{
			x = st2[s].order_of_key(make_pair(x,mxn));
			if(x*2>=st2[s].size()){
				vector<pii> add;
				while(st1[s].size() != x){
					pii tmp = *st2[s].rbegin();
					st2[s].erase(tmp);
					st1[s].erase({tmp.sc,tmp.fs});
					add.push_back({tmp.sc,tmp.fs});
				}
				sort(add.begin(),add.end());
				for(auto &j:add){
					j.fs = (st1[i].empty()?0ll:st1[i].rbegin()->fs+1);
					st1[i].insert(j);
					st2[i].insert({j.sc,j.fs});
				}
			}
			else{
				st1[s].swap(st1[i]);
				st2[s].swap(st2[i]);
				vector<pii> add;
				while(add.size() != x){
					pii tmp = *st2[i].begin();
					st2[i].erase(tmp);
					st1[i].erase({tmp.sc,tmp.fs});
					add.push_back({tmp.sc,tmp.fs});
				}
				sort(add.begin(),add.end());
				for(auto &j:add){
					j.fs = (st1[s].empty()?0ll:st1[s].rbegin()->fs+1);
					st1[s].insert(j);
					st2[s].insert({j.sc,j.fs});
				}
			}
		}
		assert(st1[i].size() == st2[i].size());
		cout<<st1[i].size()<<'\n';
	}
	return 0;
}
