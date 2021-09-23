//Problem: Given Sorted array find given element if element is found also find its number of occurence.

//Time Complexity :O(log(n))
// Space Complexity : O(1)



#include<bits/stdc++.h>

using namespace std;




int upper_bound(vector<int>&arr,int el){

    int n=arr.size();

    int l=0,r=n-1;


    int index=n;


    while(l<=r){

        int mid=(l+r)/2;

        if(arr[mid]>el){

            index=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }


    return index;
}


int lower_bound(vector<int>&arr,int el){

    int n=arr.size();

    int l=0,r=n-1;


    int index=n;


    while(l<=r){

        int mid=(l+r)/2;

        if(arr[mid]>=el){

            index=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }

    return index;
}


void solve(void){

    int n;

    cin>>n;

    int element;

    cin>>element;


    vector<int>nums(n);


    for(int i=0;i<n;++i){
        cin>>nums[i];
    }



    int upper_bound_index=upper_bound(nums,element); // Gives the index of first element that is strictly greater than target or return size of array.

    int lower_bound_index=lower_bound(nums,element); // Gives the index of first element that is strictly greater than target or return size of array.


    if(lower_bound_index==n || nums[lower_bound_index]!=element){
        cout<<"Not Present"<<(upper_bound_index-lower_bound_index)<<'\n';
        return;
    }


           cout<<"sPresent"<<(upper_bound_index-lower_bound_index)<<'\n';



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
© 2021 GitHub, Inc.
