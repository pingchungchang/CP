#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

vector<tuple<int,int,int>> req;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int arr[n];
	std::priority_queue<pii,vector<pii>,less<pii>> pq;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		pq.push({arr[i],-i});
	}
	int q;
	cin>>q;
	for(int i = 0;i<q;i++){
		int a,b;
		cin>>a>>b;
		req.push_back(make_tuple(a,b,i));
	}
	int ans[q];
	sort(req.begin(),req.end());
	ordered_set st;
	for(auto &i:req){
		int a = get<0>(i),b = get<1>(i);
		while(st.size()<a){
			st.insert(-pq.top().sc);
			pq.pop();
		}
		ans[get<2>(i)] = arr[*st.find_by_order(b-1)];
	}
	for(auto &i:ans)cout<<i<<'\n';
	return 0;
}
