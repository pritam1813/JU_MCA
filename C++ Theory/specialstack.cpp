#include <iostream>
#include "ownstack.h"
using namespace std;

class SpecialStack : public CStack{
    public:
        SpecialStack(int data){
            if(top->data <= data){
                push(data);
            } else {
                tower_of_hanoi(data);
            }
        }
        void tower_of_hanoi(int data){
            Node *temp = top;
            while(temp != nullptr){
                
                temp = temp->next;
            }
        }
};