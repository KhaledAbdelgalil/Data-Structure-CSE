#include <iostream>
using namespace std;
//Q4-a
int parent(int i)
{
    return (i+1)/2-1;
}
int left(int i)
{
    return 2*i+1;
}
int right(int i)
{
    return 2*i+2;
}
//Q4-b
void merge(int out[],int arr1[],int arr2[],int n1,int n2)
{
    int i=0;
    int j=0;
    int k=0;
    while(i<n1&&j<n2)
    {
        if(arr1[i]>arr2[j])
        {
            out[k]=arr1[i];
            i++;
        }
        else
        {
            out[k]=arr2[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        out[k++]=arr1[i++];
    }
    while(j<n2)
    {
        out[k++]=arr2[j++];
    }
}


//Q4-d

        void siftDown(int arr[],int n,int index,int step)
        {
            int maxIndex=index;
            int l=left(index);
            if(l<n&&arr[l]>arr[maxIndex])
                maxIndex=l;
            int r=right(index);
            if(r<n&&arr[r]>arr[maxIndex])
                maxIndex=r;
            if(index!=maxIndex)
            {

                swap(arr[maxIndex],arr[index]);
                cout<<"step"<<step<<endl;
                for(int j=0;j<n;j++)
                cout<<arr[j]<<"\t";
                cout<<endl;
                siftDown(arr,n,maxIndex,step++);

            }
        }

        //7-Extract Max() result=arr[1] arr[1]=arr[size] size-- shiftDown(0) return result;
        int Extract_max(int arr[],int&n)
        {
            int i=3;
            cout<<"step1"<<endl;
            for(int i=0;i<n;i++)
                cout<<arr[i]<<"\t";
            cout<<endl;
            int result=arr[0];
            arr[0]=arr[--n];
            cout<<"step2"<<endl;
            for(int i=0;i<n;i++)
                cout<<arr[i]<<"\t";
            cout<<endl;
            siftDown(arr,n,0,i);
            return result;
        }





int main()
{
    int heap1[]={15,9,8,7,5,3};
    int n1=sizeof(heap1)/sizeof(heap1[0]);
    int heap2[]={10,6,4,2};
    int n2=sizeof(heap2)/sizeof(heap2[0]);
    int n3=n1+n2;
    int *merged_array=new int[n3];
   /* merge(merged_array,heap1,heap2,n1,n2);

    for(int i=0;i<n3;i++)
        cout<<merged_array[i]<<"\t";
    cout<<endl;*/
    Extract_max(heap2,n2);
    return 0;
}
