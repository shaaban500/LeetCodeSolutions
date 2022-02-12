struct Node
{
    int val;
    Node* next;
    
    Node(int val)
    {
        this->val = val;
        next = NULL;
    }
        
};


class MyLinkedList {
public:
    
    int sz;
    Node* head;
    
    MyLinkedList() 
    {
       sz = 0;
       head = new Node(0); 
    }
    
    int get(int index) 
    {
        if(index >= sz) return -1;
        
        Node* temp = head->next;
        for(int i = 0 ; i < index ; i++)
            temp = temp->next;
        
        return temp->val;
    }
    
    void addAtHead(int val)
    {
        Node* temp = head->next;
        head->next = new Node(val);
        head->next->next = temp;
        sz++;
    }
    
    void addAtTail(int val) 
    {
        Node* temp = head;        
        while(temp->next != NULL)
            temp = temp->next;
        
        temp->next = new Node(val);
        sz++;
    }
    
    void addAtIndex(int index, int val) 
    {
        if(index > sz) return;
        
        Node* temp = head;        
        for(int i = 0 ; i < index ; i++)
            temp = temp->next;

        Node* temp1 = temp->next;
        temp->next = new Node(val);
        temp->next->next = temp1;
        sz++;
    }
    
    void deleteAtIndex(int index)
    {
        if(index >= sz) return;
        Node* temp = head;
        for(int i = 0 ; i < index ; i++)
            temp = temp->next;

        Node* temp1 = temp->next;
        temp->next = temp1->next;
        sz--;
    }
    
    void print(Node* list)
    {
        while(list->next != NULL)
        {
            list = list->next;
            cout << list->val << " ";
        }
        cout << endl;
    }
    
};
