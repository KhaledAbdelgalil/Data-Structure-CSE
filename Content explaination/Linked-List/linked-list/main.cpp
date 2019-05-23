#include <bits/stdc++.h>
using namespace std;

class node
{
private:
    int value;
    node* next;
public:
    node(int v)
    {
        value=v;
        next=NULL;
    }
    node(int v,node *n)
    {
        value=v;
        next=n;
    }
    void set(int v)
    {
        value=v;
    }
    int get()
    {
        return this->value;
    }
 friend class linked_list;
 };
class linked_list
{
    node * root;

public:
        linked_list()
        {
            root=NULL;
        }
        //always ask if list is empty does function works well
        void push_front(int x)//O(1)
        {
            node* temp=new node(x);
            temp->next=root;
            root=temp;
            //must dynamic allocated to be created in heap so pointer that points to node will be deleted it's local but node itself will not
        }
        void push_back(int x)//O(n)
        {
            if(root==NULL){
                root=new node(x,NULL);
            }
            else
            {
                node* traverse_ptr=root;
                while(traverse_ptr->next!=NULL)
                {
                    traverse_ptr=traverse_ptr->next;
                }
                traverse_ptr->next=new node(x,NULL);
            }
        }
        node* getRoot()
        {
            return root;
        }
        void print_list()
        {
            if(root==NULL);
            else
            {
                node* temp=root;//in order not to play wrong with root take a copy from root
                while(temp->next!=NULL)
                {
                    cout<<temp->value<<"--->";
                    temp=temp->next;
                }
                cout<<temp->value<<endl;
            }
        }
        int get_front()
        {
            if(root!=NULL)
                return root->value;
            return -1000;//any indication for that list is empty
        }
        void remove_front()
        {
            if(root!=NULL)
            {
                node* temp=root;
                root=root->next;
                delete temp;
            }
        }
        void remove_back()
        {
            //this if works well if there is at least 2 elements in list so we added 2nd condition
            if(root!=NULL&&root->next!=NULL)
            {
                node* temp=root;
                node* prev=root;
                while(temp->next!=NULL)
                {
                    prev=temp;
                    temp=temp->next;
                }
                delete temp;
                prev->next=NULL;
            }
            else if(root!=NULL)
            {
                delete root;
                root=NULL;
            }
        }
        void remove(int x)
        {
            if(root!=NULL&&root->value==x)
            {
                remove_front();
            }
            else if(root!=NULL)
            {
                node* traverse_ptr=root;
                while(traverse_ptr->next!=NULL&&traverse_ptr->next->value!=x)
                {
                    traverse_ptr=traverse_ptr->next;
                }
                //you need to delete if next!=NULL as you find node
                if(traverse_ptr->next!=NULL)
                {
                    node* temp=traverse_ptr->next;
                    traverse_ptr->next=traverse_ptr->next->next;
                    delete temp;
                }
            }
        }
};
int main()
{
    linked_list l;
    cout<<l.get_front()<<endl;
    l.push_front(5);
    l.push_back(6);
    l.push_front(4);
    l.push_front(3);
    l.push_front(2);
    l.push_front(1);
    l.push_back(7);
    l.push_back(8);
    l.print_list();
    /*------------------------------*/
    l.remove_front();
    l.print_list();
    /*------------------------------*/
    l.remove_back();
    l.print_list();
    /*------------------------------*/
    l.remove(2);
    l.print_list();
    l.remove(3);
    l.print_list();
    l.push_back(8);
    l.push_back(9);
    l.remove(7);
    l.print_list();
    /*-----------------------------*/
    return 0;
}
