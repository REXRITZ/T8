#include<bits/stdc++.h>
using namespace std;
#define loop(i,n) for(int i=0;i<n;++i)
#define loop2(high,low) for(i=high;i>=low;--i)

void quickpass(vector<int>arr, int n) {
    loop(i,n) cout<<arr[i]<<" ";
}

int quicksort(vector<int>&arr, int low, int high) {
    int i;
    int j=high;
    loop2(high,low) {
        if(arr[low] < arr[i]) {
            swap(arr[i],arr[j]);
            --j;
        }
    }
    swap(arr[j],arr[low]);
    quickpass(arr,arr.size());
    cout<<"\n";
    return j;
}

void partition(vector<int>&arr, int low, int high) {

    if(high > low) {
        int pivot = quicksort(arr,low,high);
        partition(arr,low,pivot-1);
        partition(arr,pivot+1,high);
    }
}
int main() {
    int n;
    cin>>n;
    vector<int>arr(n);

    loop(i,n) {
        cin>>arr[i];
    }
    partition(arr,0,n-1);
    loop(i,n) cout<<arr[i]<<" ";
}
