#include <iostream>
using namespace std;
//Q2-a
class node
{
private:
    int val;
    int freq;
    node* next;
public:
    node(int v,int f)
    {
        next=NULL;
        val=v;
        freq=f;
    }
    int getVal()
    {
        return val;
    }
    int getFreq()
    {
        return freq;
    }
    node* getNext()
    {
        return next;
    }
friend class chain;
};
class chain
{
private:
    node* head;
public:
    chain(){head=NULL;}
    void insert(int v,int f);
    float getAverage();
    void print();
};
float chain::getAverage()
{
    if(head==NULL) return 0;
    node* temp=head;
    int sumValues=0;
    int sumFreq=0;
    while(temp!=NULL)
    {
        sumValues+=temp->freq * temp->val;
        sumFreq+=temp->freq;
        temp=temp->next;
    }
    return float(sumValues)/sumFreq;
}
void chain::insert(int v,int f)
{
    /* Special case for the head end */
    if (head == NULL || head->val >= v)
    {
        node* temp=new node(v,f);
        temp->next = head;
        head = temp;
    }
    else
    {
        /* Locate the node before the point of insertion */
        node* temp= head;
        while (temp->next!=NULL &&
            temp->next->val < v)
        {
            temp = temp->next;
        }
        node*temp2=new node(v,f);
        temp2->next = temp->next;
        temp->next = temp2;
    }
}
void chain::print(){
    if(head==NULL) return;
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<"value: "<<temp->val<<" Freq: "<<temp->freq<<endl;
        temp=temp->next;
    }

}
int main()
{
    int n,v,f;
    chain k;
    cout<<"enter number of nodes you want to insert"<<endl;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cout<<"enter v and f spaced between each other for node "<<i<<endl;
        cin>>v>>f;
        k.insert(v,f);
    }
    cout<<"nodes are in order"<<endl;
    k.print();
    cout<<"average is: "<<endl;
    cout<<k.getAverage();

    return 0;
}
