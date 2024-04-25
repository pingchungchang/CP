#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int r,c,m,k;
	cin>>r>>c>>k>>m;
	vector<vector<pair<int,int>>> arr(r+2,vector<pair<int,int>>(c+2,make_pair(-1,0)));
	for(int i =1;i<=r;i++){
		for(int j =1;j<=c;j++){
			int a;
			cin>>a;
			arr[i][j].first = a;
		}
	}
	for(int t =0;t<m;t++){
		for(int i =1;i<=r;i++){
			for(int j =1;j<=c;j++){
				if(arr[i+1][j].first != -1){
					arr[i+1][j].second += arr[i][j].first/k;
					arr[i][j].second -=arr[i][j].first/k;
				}
				if(arr[i][j+1].first != -1){
					arr[i][1+j].second += arr[i][j].first/k;
					arr[i][j].second -=arr[i][j].first/k;
				}
				if(arr[i][j-1].first != -1){
					arr[i][j-1].second += arr[i][j].first/k;
					arr[i][j].second-=arr[i][j].first/k;
				}
				if(arr[i-1][j].first != -1){
					arr[i-1][j].second += arr[i][j].first/k;
					arr[i][j].second -=arr[i][j].first/k;
				}
			}
		}
		for(int i =1;i<=r;i++){
			for(int j =1;j<=c;j++){
				arr[i][j].first += arr[i][j].second;
				arr[i][j].second = 0;
			}
		}
	}
	int smallest = INT_MAX,biggest = 0;
	for(int i =1;i<=r;i++){
		for(int j =1;j<=c;j++){
			if(arr[i][j].first>=0)smallest = min(smallest,arr[i][j].first);
			biggest = max(biggest,arr[i][j].first);
		}
	}
	cout<<smallest<<'\n'<<biggest;
}
