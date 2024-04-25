#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	bitset<110> func[n];
	int price[n];
	for(int i = 0;i<n;i++){
		cin>>price[i];
		int c;
		cin>>c;
		func[i].reset();
		while(c--){
			int k;
			cin>>k;
			func[i][k] = true;
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(i == j)continue;
			//cout<<i<<' '<<j<<func[i].count()<<' '<<func[j].count()<<' '<<(func[i]|func[j]).count()<<endl;
			if(func[i].count() < func[j].count())continue;
			if((func[i]^func[j]).count() == 0){
				if(price[i] != price[j]){
					cout<<"Yes";
					return 0;
				}
			}
			else if((func[i]|func[j]).count() == func[i].count()&&price[i]<=price[j]){
				cout<<"Yes";
				return 0;
			}
		}
	}
	cout<<"No\n";
	return 0;
}
