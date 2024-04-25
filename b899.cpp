#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<pair<int,int>> points;
    for(int i = 0;i<3;i++){
        int a,b;
        cin>>a>>b;
        points.push_back(make_pair(a,b));
    }
    vector<int> chosen(3.0);
    vector<pair<int,int>> vecs;
    int center = -1;
    for(int i = 0;i<3;i++){
        chosen[i] = 1;
        vector<pair<int,int>> ans;
        for(int j =0;j<3;j++){
            if(chosen[j] != 1){
                ans.push_back(make_pair(points[j].first-points[i].first,points[j].second-points[i].second));
            }
        }
        if(ans[0].first*ans[1].first+ans[1].second*ans[0].second == 0){
            vecs = ans;
            center = i;
            break;
        }
        chosen[i] = 0;
    }
    //cout<<vecs[0].first<<vecs[0].second<<vecs[1].first<<vecs[1].second<<endl;
    cout<<points[center].first+vecs[0].first+vecs[1].first<<" "<<points[center].second+vecs[1].second+vecs[0].second;
}
