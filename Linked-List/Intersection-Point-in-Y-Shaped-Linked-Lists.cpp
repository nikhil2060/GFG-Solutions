//{ Driver Code Starts

#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)           //ANS****
{   
    
    int l1=0;
    int l2=0;
    
    Node*temp1=head1;
    Node*temp2=head2;
    
    while(temp1!=NULL){
        l1++;
        temp1=temp1->next;
    }
    
    // cout<<l1<<endl;
    
    while(temp2!=NULL){
        l2++;
        temp2=temp2->next;
    }
    
    // cout<<l2<<endl;
    int d=abs(l1-l2);
    
    temp1=head1;
    temp2=head2;
    
    while(d--){
        if(l1>l2){
            temp1=temp1->next;
        }
        else{
            temp2=temp2->next;
        }
    }
    
    // cout<<temp1->data<<" "<<temp2->data<<endl;
    
    while(temp1!=NULL && temp2!=NULL){
        if(temp1==temp2){
            return temp1->data;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return -1;
}

