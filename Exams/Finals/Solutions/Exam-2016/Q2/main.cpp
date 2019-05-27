//sift-up::look@parent only
//sift-down::look@both children and choose to swap with max
//in extraction of max::Replace leaf with any leaf then begin to sift down
//for changing priority----make sift up if new value>old value///sift-down if new value<old-value
//for remove element change its priority to infinity and then sift up and extractMax
#include <bits/stdc++.h>
using namespace std;
void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}
class heap
{
public: int* arr;//assume zero keying for binary heap
        int max_size;
        int used_size;
        heap(int size_max)
        {
            max_size=size_max;
            arr=new int[max_size];
            used_size=0;
        }
        //1-parent: return(i)/2 if key start from 1
        int parent(int index)
        {
            return (index+1)/2-1;
        }
        //2-leftChild(i) return 2*i if key start from 1
        int leftChild(int index)
        {
            return 2*index+1;
        }
         //3-rightChild(i) return 2*i+1 if key start from 1
        int RightChild(int index)
        {
            return 2*index+2;
        }
        //4-siftup(i) while(i>1&&arr[parent(i)]<arr[i]):
                            //swap (arr[parent(i)],arr[i])
                            //i<-parent(i)
        void siftUp(int index)
        {
            while (index != 0 && arr[index] > arr[parent(index)])
                {
                       for(int i=0;i<used_size;i++)
                            cout<<arr[i]<<" ";
                        cout<<endl;
                    swap(arr[index], arr[parent(index)]);
                       for(int i=0;i<used_size;i++)
                        cout<<arr[i]<<" ";
                        cout<<endl;
                    index = parent(index);
                }
        }
        //5-siftDown(i)
            //max_index=i;
            //l=leftChild(i)
            //if l<size and arr[l]>arr[maxIndex) //l<size in heap or not
                 //maxIndex=l
            //r=rightChild(i)
            //if r<size and arr[r]>arr[maxIndex)
                 //maxIndex=r
            //if i!= maxindex
                    //swap arr[i] and arr[maxIndex]
                    //shiftDown(maxIndex)

        void siftDown(int index)
        {
            int maxIndex=index;
            int l=leftChild(index);
            if(l<used_size&&arr[l]>arr[maxIndex])
                maxIndex=l;
            int r=RightChild(index);
            if(r<used_size&&arr[r]>arr[maxIndex])
                maxIndex=r;
            if(index!=maxIndex)
            {
                swap(arr[maxIndex],arr[index]);
                siftDown(maxIndex);
            }
        }
        //6-Insert(p) if size==max_size return ERROR
                      //size=size+1 arr[size]=p shiftUp(size)
        bool insert(int p)
        {
            if(used_size==max_size) return false;
            arr[used_size]=p;
               for(int i=0;i<used_size;i++)
                cout<<arr[i]<<" ";
            cout<<endl;
            siftUp(used_size);
            used_size++;
            for(int i=0;i<used_size;i++)
                cout<<arr[i]<<" ";
            cout<<endl;
            return true;
        }

};

int main()
{
    heap h(30);
    int n;
    cin>>n;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        h.insert(x);
    }
    return 0;
}
