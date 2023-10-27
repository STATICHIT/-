#include<bits/stdc++.h>
using namespace std;

void Merge(int arr[],int L,int M,int R)
{
    int LEFT_SIZE = M-L;
    int RIGHT_SIZE = R-M+1;
    int left[LEFT_SIZE];
    int right[RIGHT_SIZE];
    int i,j,k;

    //填充左边数组
    for(int i=L; i<M; i++)left[i-L]=arr[i];
    //填充右边数组
    for(int i=M; i<=R; i++)right[i-M]=arr[i];
    //把两个数组排序放到arr里去
    i=0,j=0, k=L;
    while(i<LEFT_SIZE && j<RIGHT_SIZE)
    {
        if(left[i]<right[j])
        {
            arr[k]=left[i];
            k++;
            i++;
        }
        else
        {
            arr[k]=right[j];
            k++;
            j++;
        }
    }
    while(i<LEFT_SIZE)
    {
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<RIGHT_SIZE)
    {
        arr[k]=right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int L,int R)
{
    if(R == L)return;
    else
    {
        int M=(L+R)/2;
        mergeSort(arr,L,M);
        mergeSort(arr,M+1,R);
        Merge(arr,L,M+1,R);
    }
}

int main()
{
    int arr[]= {3,6,2,5,1,7,9,4};
    int L=0,R=7;
    mergeSort(arr,L,R);
    for(int i=0; i<R; i++)
        cout<<arr[i]<<endl;
    return 0;
}
