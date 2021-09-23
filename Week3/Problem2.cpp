//Find number of comaprison and swap in selection sort

#include<bits/stdc++.h>

using namespace std;


void solve(void){

    int n;

    cin>>n;


    vector<int>arr(n);

    for(int i=0;i<n;++i){
        cin>>arr[i];
    }


    int comparison=0,shifts=0;

    for(int i=0;i<n-1;++i){

        int index = i;

        for(int j=i+1;j<n;++j){

            ++comparison;

            if(arr[j]<arr[index]){
                index=j;
            }
        }

        if(index!=i){
            ++shifts;
            swap(arr[index],arr[i]);
        }
    }


    for(auto it:arr){
        cout<<it<<' ';
    }

    cout<<'\n';


    cout<<"Comparison "<<comparison<<"\n"<<"Shifts "<<shifts<<'\n';
}


int main(){

    freopen("input1.txt","r",stdin);

    freopen("output1.txt","w",stdout);

    int test_cases;

    cin>>test_cases;

    while(test_cases--){
        solve();
    }
}
