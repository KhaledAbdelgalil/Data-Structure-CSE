#include <bits/stdc++.h>

using namespace std;
//3rd application: median is the number @ which all numbers above are greater than it and all numbers below less than it it's @middle
//median of 1 2 3 4 5 6 7 is 4 median of 1 2 3 4 5 6 7 8 is (4+5)/2;
double median(double arr[],int n)
{
    sort(arr,arr+n);
    if(n%2==0)
        return (arr[n/2]+arr[n/2-1])/2;

    return arr[n/2];
}
//4th application:mode is the most repeated element in the array
int mode_slow_version(int arr[],int n)
{
    int result;
    int maxCount;
    for(int i=0;i<n;i++)
    {
        int mode=arr[i];
        int countt=0;
        for(int j=0;j<n;j++)
        {
            if(arr[j]==mode)
                countt++;
        }
        if(i==0||countt>maxCount)
        {
            maxCount=countt;
            result=mode;
        }
    }
    return result;
}
int mode_fast_version(int arr[],int n)
{
    sort(arr,arr+n);
    int result;
    int maxCount;
    bool first_time=true;
    for(int i=0;i<n;i++)
    {
        int countt=1;
        int mode=arr[i];
        while(i<n-1&&arr[i]==arr[i+1])
        {
            countt++;
            i++;
        }
        if(first_time)
        {
            maxCount=countt;
            result=mode;
            first_time=false;
        }
        if(countt>maxCount)
        {
            result=mode;
            maxCount=countt;
        }
    }
    return result;
}
//5th application: find pair with targetsum=sumTarget
struct int_pair{
    int x;
    int y;
    int_pair(int i,int j)
    {
        x=i;
        y=j;
    }
};
list<int_pair> findpair_fast_version(int arr[],int n,int sumTarget)
{
	sort(arr, arr+n); // nlogn
	list<int_pair> result;
	for (int i = 0,j=n-1; i<j;) // n
	{
		if (arr[i] + arr[j] == sumTarget)
		{
			result.push_back(int_pair(arr[i], arr[j]));
			i++;
			j--;
		}
		else if (arr[i] + arr[j] > sumTarget)
			j--;
		else if (arr[i] + arr[j] < sumTarget)
			i++;
	}
	return result;
}

list<struct int_pair> findpair_slow_version(int arr[],int n, int sumTarget)
{
	list<int_pair> result;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] + arr[j] == sumTarget)
				result.push_back(int_pair(arr[i], arr[j]));
		}
	}
	return result;
}
int main()
{
    double arr[]={1,2,3,4,5,6,7,8};
    cout<<median(arr,8);
    int arr2[]={1,3,4,4,5,7,2,6,2,6};
    cout<<endl;
    cout<<mode_slow_version(arr2,8);
    cout<<endl<<mode_fast_version(arr2,8)<<endl;
    list<struct int_pair>re=findpair_fast_version(arr2,10,8);
    for(std::list<struct int_pair>::iterator it =re.begin();it!= re.end();it++)
    {
        struct int_pair s=*it;
        cout<<s.x<<" "<<s.y<<endl;
    }
    return 0;
}
