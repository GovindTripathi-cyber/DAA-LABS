// Count number of comparison and shifts to sort array using insertion sort


#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;

    cin>>n;


    vector<int>arr(n);

    for(int i=0;i<n;++i){
        cin>>arr[i];
    }


    int shifts=0,comparison=0;

    for(int i=1;i<n;++i){

        int j=i-1;

        int key=arr[i];

        // ++comparison;

        while(j>=0 && key<arr[j]){

            ++comparison;

            arr[j+1]=arr[j];

            ++shifts;

            --j;
        }

        arr[j+1]=key;

        ++shifts;
    }


    for(auto it:arr){
        cout<<it<<' ';
    }

    cout<<'\n';

    cout<<"Comparison "<<comparison<<"\n"<<"Shifts "<<shifts<<'\n';
}

int main(){


    freopen("input.txt","r",stdin);

    freopen("output.txt","w",stdout);

    int test_cases;

    cin>>test_cases;

    while(test_cases--){
        solve();
    }

}
