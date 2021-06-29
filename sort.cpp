#include <bits/stdc++.h>
using namespace std;

void Merge(vector<int> &list, int start, int end, int mid){
    int i = start, j = mid + 1, k=0;
    vector<int> temp_list(end - start + 1);

    while(i <= mid && j <= end){
        if(list[i] < list[j]) temp_list[k++] = list[i++];
        else temp_list[k++] = list[j++];
    }
    while(i <= mid) temp_list[k++] = list[i++];
    while(j <= end) temp_list[k++] = list[j++];

    for(int k=0; k<end-start+1; k++){
        list[k+start] = temp_list[k];
    }
}

void MySort(vector<int> &list, int start, int end){
    if(start >= end) return;
    int mid = (start + end) >> 1;
    MySort(list, start, mid);
    MySort(list, mid+1, end);
    Merge(list, start, end, mid);
}

int main(){
    vector<int> list = {1, 2, 4, 6, 3, 4, 1, 11};
    int n = list.size();

    MySort(list, 0, n-1);

    for(int i=0; i<n; i++){
        cout << list[i] << ' ';
    }
    return 0;
}
