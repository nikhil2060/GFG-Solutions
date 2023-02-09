//{ Driver Code Starts
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
''
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)      //ANS*****
    {
        if(k==0){
            return head;
        }
        
        
        Node*temp=head;
        Node*temp2;
        Node*newhead=NULL;
        // k=k-1;
        
        while(--k)
        {
            temp=temp->next;
        }
        
        newhead=temp;
        
        
        // temp->next=NULL;
        
        while(temp->next!=NULL){
            temp=temp->next;
        }
        
        temp->next=head;
        head=newhead->next;
        newhead->next=NULL;
        
        return head;
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends