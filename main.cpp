#include <iostream>

//You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.
//Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
//You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
#include <iostream>
using namespace std;
int firstbadversion (int arr[], int x, int low, int high) {

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) { return mid; }

        if (arr[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return 0;
}

int main() {
    int n,x;
    cout<<" How many versions are created: ";
    cin>>n;
    cout<<" First bad version: ";
    cin>>x;
    int i=0;
    int low=i;
    int result;
    int arr[n];
    for (i=low;i<=n;i++)
    {
        arr[i]= i ;
        // cout<< arr[i]<<" "<<endl;
    }
    result= firstbadversion(arr,x,low ,n);
    if (result>0){cout<<"First bad version: "<<result<<endl;}
    else {cout<<" Not found "<<endl;}


}
