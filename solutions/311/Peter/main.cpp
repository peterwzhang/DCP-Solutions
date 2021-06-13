#include <iostream>
#include <vector>
using namespace std;

int find_peak(vector<int> arr){
    
    int start = 0, end = arr.size() - 1;
    while (start <= end){
        int mid = (start + end) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            return arr[mid];
        else if (arr[mid+1] > arr[mid])
            start = mid + 1;
        else 
            end = mid - 1;
    }
    return 0;
}
int main(){
    vector<int> test1 = {3,5,4,7,5,8,10};
    vector<int> test2 = {1,3,2,7,8,9,10,11,12,13,4};
    vector<int> test3 = {3,10,7,1,2,3,4,5,0};

    cout << find_peak(test1) << endl;
    cout << find_peak(test2) << endl;
    cout << find_peak(test3) << endl;


}