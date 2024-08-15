//Creation of doubly linked list

// class Node{
//     public:
//     int data;
//     Node* prev;
//     Node* next;

//     //Constructor
//     Node(int d){
//         this->data = d;
//         this->prev = nullptr;
//         this->next = nullptr;
//     }

// };

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* a Node of the doubly linked list */
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x)
  {
      data = x;
      next = prev = NULL;
  }
};

void addNode(Node *head, int pos, int data);

Node *insert(Node *head, int x)
{
    if (head == NULL)
    {
        return new Node(x);
    }
    Node *n = new Node(x);
    
    head->next = n;
    n->prev = head;
    head = n;
    return head;
}

void printList(Node *head)
{
  // The purpose of below two loops is
  // to test the created DLL
  Node *temp=head;
  if (temp != NULL) {
    int ct1=0,ct2=0;
  while (temp->next!=NULL)
    temp=temp->next,ct1++;
  while (temp->prev!=NULL)
   temp = temp->prev,ct2++;
   if(ct1!=ct2){
       cout<<-1<<"\n";
       return;
   }
  }
  while (temp != NULL)
  {
      printf("%d ",temp->data);
      temp=temp->next;
  }
  
  cout << endl;
}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
  Node *head = NULL; 
  Node *root = NULL;
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
     int x;
     scanf("%d",&x);
     head = insert(head, x);
     if(root==NULL) root = head;
  }     
  head = root;
  int pos,data;
  cin>>pos>>data;
  addNode(head, pos, data);
  printList(head);
  }
  return 0;
}
// } Driver Code Ends


/* a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

//Function to insert a new node at given position in doubly linked list.
// void insertathead(Node*& head, int d)
// {
//     Node* temp = new Node(d);
//     temp->next = head;
//     if (head != nullptr) {
//         head->prev = temp;
//     }
//     head = temp;
// }

// void insertattail(Node* head, int d) {
//     Node* temp = new Node(d);
//     Node* curr = head;
//     while (curr->next != nullptr) {
//         curr = curr->next;
//     }
//     curr->next = temp;
//     temp->prev = curr;
// }

void addNode(Node* head, int pos, int data)
{
    
    int cnt = 0; 
    Node* temp=head;
    while (cnt < pos ) {
        temp = temp->next;
        cnt++;
    }
    
    Node* nodetoinsert = new Node(data);
    nodetoinsert->next = temp->next;
    if (temp->next != nullptr) {
        temp->next->prev = nodetoinsert;
    }
    temp->next = nodetoinsert;
    nodetoinsert->prev = temp;
}
