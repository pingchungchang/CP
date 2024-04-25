#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    bool ok = false;
    vector<int> v;
    for (int i = 0; i < 3;i++){
        int m;
        cin >> m;
        v.push_back(m);
    }
    sort(v.begin(),v.end());
    if(v[2]<v[1]+v[0]){
        ok = true;
    }
    cout << v[0] <<' '<< v[1] <<' '<< v[2]<<endl;
    if(ok){
        if(v[2]*v[2]>v[1]*v[1]+v[0]*v[0]){
            cout << "Obtuse";
        }
        else if(v[2]*v[2]==v[1]*v[1]+v[0]*v[0]){
            cout << "Right";
        }
        else{
            cout << "Acute";
        }

    }
    else{
        cout << "No";
    }

}