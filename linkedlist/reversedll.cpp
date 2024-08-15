//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};

Node *newNode(int data)
{
    Node *temp=new Node(data);
    
    return temp;
}




void displayList(Node *head)
{
    //Head to Tail
    while(head->next)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<head->data;
    
    
    
}


int getLength(Node * head)
{
    Node *temp=head;
    
    int count=0;
    while(temp->next!=head)
    {
        count++;
        temp=temp->next;
    }
    return count+1;
}




bool verify(Node* head)
{
    int fl=0;
    int bl=0;
    
    Node *temp=head;
    
    while(temp->next)
    {
        temp=temp->next;
        fl++;
    }
    
    while(temp->prev)
    {
        temp=temp->prev;
        bl++;
    }
    
    return fl==bl;
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/
class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        //Your code here
        // Node* temp=head;
        // stack<int>st;
        // while(temp!=NULL){
        //     st.push(temp->data);
        //     temp=temp->next;
        // }
        // temp=head;
        // while(!st.empty()){
        //     temp->data=st.top();
        //     st.pop();
        //     temp=temp->next;
        // }
        // return head;
        
        if (head == NULL || head->next == NULL) {
            return head; // If the list is empty or has only one node, no need to reverse
        }

        Node* prev = NULL;  // To keep track of the previous node
        Node* curr = head;  // To traverse the list starting from the head
        Node* forward = NULL; // To keep track of the next node

        while (curr != NULL) {
            // Store the next node
            forward = curr->next;

            // Reverse the current node's next and prev pointers
            curr->next = prev;
            curr->prev = forward;

            // Move prev and curr one step forward
            prev = curr;
            curr = forward;
        }

        // After the loop, prev will be the new head of the reversed list
        return prev;
        
    }
};



//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    Node *head=NULL, *tail=NULL;
        int x;
	    cin>>x;
	    head = newNode(x);
	    tail = head;
	    
	    for(int i=0;i<n - 1;i++)
	    {
	        cin>>x;
	        Node* temp=newNode(x);
	        tail->next=temp;
	        temp->prev= tail;
	        tail = temp;
	    }
	    Solution ob;
	    head=ob.reverseDLL(head);
	    
	    
	    if(verify(head))
	    displayList(head);
	    else
	    cout<<"Your pointers are not correctly connected";
 
	    cout<<endl;
	}
	return 0;
}


// } Driver Code Ends