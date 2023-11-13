#ifndef LIST_H //include guards
#define LIST_H

#include <string>
#include <iostream> //include statements

using namespace std; //using namespace

class List{ //making the linkedlist class

    private:

        struct ListNode{ //defining the linked list node structure inside the linkedlist class

            string monName; //this stores the monster name
            ListNode *next; //allows us to move forward through the list

        };

        ListNode *head; //head and tail for start and end of list
        ListNode *tail;
    
    public:

    List(){ //when constructing, set the head and tail to null
    
        head = NULL;
        tail = NULL;
    }

    ~List(){

        ListNode* tempN;
        tempN = head; //defining the temporary node used for deletion

        while (tempN){ //goes until tempN reaches the end/is still a valid node
            head = tempN->next; //move head up
            delete tempN; //delete temp
            tempN = head; //assign temp to head to continue deletion

        }
    }

// TA: Great use of @param, consider also trying @name and @brief and playing with all the @ attributes.
/*
    appendNode: allows us to append a new element to the end of the linked list
    @param newName the monster name we are appending
*/
    void appendNode(string newName){ 

        ListNode *appendNode; //the node to attach the new monster name
        appendNode = new ListNode;
        appendNode->monName = newName; //initializes the appendnode to null and with the new monster name
        appendNode->next = NULL;

        if(!head){
            head = appendNode;
            tail = appendNode; //if the list is empty, sets head and tail to appendnode
        }else{
            tail->next = appendNode; //if list is not empty, makes the tail node point to appendnode
            tail = appendNode; //then make tail be the appendnode (tail is last node in the list)
        }
    }

    /*
        deleteNode:
        @param compName the variable used to find the node to delete
    */
    void deleteNode(string compName){

        ListNode *foreNode; //fore and backnode allow us to be able to traverse the list
        ListNode *backNode; //and patch it when we cut out the node to delete

        if(!head){ //if the list doesn't exist quit the function // TA: Great!
        return;
        }

        if(head->monName == compName){ // TA: Fantastic edge catch

            foreNode = head->next; //if the head is the node we have to delete
            delete head; //delete head and assign head to the next node up
            head = foreNode;

        }else{

            foreNode = head;

            while(foreNode != NULL && foreNode->monName != compName){ //starting from the beginning and while we don't hit the end/find the name

                backNode = foreNode;
                foreNode = foreNode->next; //move each node up

            }
            if(foreNode->monName == compName){ //if we find monster to delete // TA: Bad, the way we know if we found a monster is if foreNode != NULL,
            // TA: Consider that if it is NULL then this line will crash the program with a segmentation fault. -1

                if(foreNode == tail){ // TA: Awesome!
                    tail = backNode; //if tail is monster to delete we assign tail one node down
                }

                    backNode->next = foreNode->next; //now we delete the the node and make the previous node...
                    delete foreNode; //point to the node in front of the node we delete
                }   
        }
    }

    /*
        insertNode: allows us to insert a node at a given point (alphabetically in this case)
        @param injectorStr the string we are inserting/injecting into the list
    */
    void insertNode(string injectorStr){

        ListNode * injectionNode; //making node to insert
        ListNode * tempNode;

        injectionNode = new ListNode;
        injectionNode->monName = injectorStr;
        injectionNode->next = NULL; //assigning injection node proper values

        if(!head){

            head = injectionNode; //if the list is empty, head and tail should equal the injection node
            tail = injectionNode; //because theres only one node, it is the start and end of the list

        }else{

            tempNode = head; //we start from the beginning of the list

            while(tempNode->monName < injectionNode->monName && tempNode->next != tail){

                tempNode = tempNode->next; //now we traverse the list either until the end or we find the spot to inject node to
                
                if(tempNode->monName > injectionNode->monName){ //if we find the spot, break out of the while loop
                    break;
                }

            }
            
            if(tempNode == tail){ // TA: Good catch, though we also need a catch for the head node.
                tail = injectionNode;
            } //if we reached the end of the list, injection node becomes the tail

            injectionNode->next = tempNode->next; //now we assign the injection node to the proper place in the list
            tempNode->next = injectionNode; 

        }
    }

    /*
        displayList: displays the linked list
    */
    void displayList(){

        ListNode *displayNode; //node we use to display list

        if(head != NULL){ //if the head is not empty or list is made
            displayNode = head;

            while(displayNode != NULL){ //now we go through the list until we reach tail/end
                cout << displayNode->monName << endl; //display the monster name
                displayNode = displayNode->next; //move up
            }
        }
    }  
};

#endif

//logic on insert and destructor // TA: Huh?