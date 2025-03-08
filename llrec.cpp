#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

// void llpivotHelper(Node *& headOfSubList, Node *& headOfMainList)
// {

//     while(headOfSubList->next != nullptr)
//     {

//         headOfSubList = headOfSubList->next;

//     }

//     headOfSubList->next = headOfMainList;

//     return;

// }

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{

    // cout << "Executing llpivot!" << endl;

    if(head == nullptr)
    {

        // cout << "Empty linked list!" << endl;

        smaller = nullptr;

        larger = nullptr;

        return;

    }

    llpivot(head->next, smaller, larger, pivot);    

    if(head->val <= pivot)
    {

        // cout << "Head val is less/equal than pivot!" << endl;

        // cout << "Head->val is " << head->val << endl;

        // llpivotHelper(smaller, head);

        Node* originalSmallerHead = smaller;

        smaller = head;

        smaller->next = originalSmallerHead; 

    }

    else if(head->val > pivot)
    {

        // cout << "Head val is greater than pivot!" << endl;

        // cout << "Head->val is " << head->val << endl;

        Node* originalLargerHead = larger;

        larger = head;

        larger->next = originalLargerHead;

    }

    if(head == smaller || head == larger)
    {

        head = nullptr;

    }

}
