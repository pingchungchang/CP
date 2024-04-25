#include <bits/stdc++.h>

using namespace std;

int main(){
    unordered_map<int,pair<string,int>> a;
    unordered_map<int,pair<string,int>> b;
    a[1] = make_pair("Medium Wac",4);
    a[2] = make_pair("WChicken Nugget",8);
    a[3] = make_pair("Geez Burger",7);
    a[4] = make_pair("ButtMilk Crispy Chicken",6);
    a[5] = make_pair("Plastic Toy",3);
    b[1] = make_pair("German Fries",2);
    b[2] = make_pair("Durian Slices",3);
    b[3] = make_pair("WcFurry",5);
    b[4] = make_pair ("Chocolate Sunday",7);
    int n;
    int total = 0;
    while(cin>>n){
        if(n == 0){
            cout<<"Total: "<<total;
            return 0;
        }
        int k;
        if(n == 1){
            cin>>k;
            cout<<a[k].first<<' '<<a[k].second<<endl;
            total += a[k].second;
        }
        else{
            cin>>k;
            cout<<b[k].first<<' '<<b[k].second<<endl;
            total += b[k].second;
        }
    }
}
