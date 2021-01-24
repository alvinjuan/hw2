#include <iostream>
using namespace std;

class Node {
    public: 
        int data;
        Node *next, *prev;
};

Node *split(Node *head);

// inserts a new node in front of the list
void insert(Node **head, int data){  
    Node *tmp = new Node(); 
    tmp->data = data;  
    tmp->next = *head;
    *head = tmp; 
}

// searches for a value in the list and determines if the value is present
// returns the position of the number in the ascended list
void search(int num, Node *head){
    int pos = 0;
    if (head == NULL){
        cout << "\nlinked list is empty";
        return;
    }
    Node *tmp = head;
    while(tmp != NULL){
        if (tmp->data == num){
            cout << "\nvalue: " << num << ", pos: " << pos;
            return;
        }
        pos++;
        if (tmp->next != NULL){
            tmp = tmp->next;
        }
        else {
            break;
        }
    }
    cout << "\nthe value (" << num << ") does not exist";
}

// splits doubly linked list to 2 doubly linked list
Node *split(Node *head){  
    Node *first = head;
    Node *second = head;
    while (first->next && first->next->next)  
    {  
        first = first->next->next;  
        second = second->next;  
    }  
    Node *tmp = second->next;  
    second->next = NULL;  
    return tmp;  
}

// combine linked lists
Node *merge(Node *firstList, Node *otherList){  
    if (firstList == NULL){
        return otherList; 
    }
    if (otherList == NULL){
        return firstList;
    }  
    if (otherList->data < firstList->data){    
        otherList->next = merge(firstList,otherList->next);  
        otherList->next->prev = otherList;  
        otherList->prev = NULL;  
        return otherList;  
    }  
    else {  
        firstList->next = merge(firstList->next,otherList);  
        firstList->next->prev = firstList;  
        firstList->prev = NULL;  
        return firstList;  
    }  
} 

// function to merge sort list 
Node *mergeSort(Node *head){  
    if (!head || !head->next){
        return head; 
    }   
    Node *other = split(head);  
    // recurse for both left and right
    head = mergeSort(head);  
    other = mergeSort(other);  
    return merge(head,other); 
}

// prints nonsorted linked list
void printList(Node *head){
    Node *curr = head;
    if (head == NULL){
        cout << "List is empty";
    }
    while(curr != NULL){
        cout << curr->data << "  ";
        curr = curr->next;
    }
}

// prints linked list ascend and descend order
void printSorted(Node *head){  
    Node *tmp = head;  
    cout << "Ascending order(cm): ";  
    while (head){  
        cout << head->data << " ";  
        tmp = head;  
        head = head->next;  
    }  
    cout << "\nDescending Order(cm): ";  
    while (tmp){  
        cout << tmp->data << " ";  
        tmp = tmp->prev;  
    }  
} 

int main(){
    Node *head = NULL;  //list with objects
    Node *empty = NULL; // empty list

    // 10 objects
    cout << "\nNBA players height(cm) before sorting: ";
    insert(&head, 185);
    insert(&head, 187);
    insert(&head, 188);
    insert(&head, 184);
    insert(&head, 189);
    insert(&head, 181);
    insert(&head, 182);
    insert(&head, 186);
    insert(&head, 183);
    insert(&head, 190);

    // sorting (O(nlogn) for both ascending and descending)
    printList(head);
    cout << "\n";

    head = mergeSort(head);
    cout << "\nSorted List:\n";
    printSorted(head);
    cout << "\n";
    
    // searching (O(n) for time complexity)
    search(185, head);  //num present in list
    search(191, head);  //num doesnt exist
    search(180, empty); //empty list
};
