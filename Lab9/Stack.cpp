#include "Stack.h"

Stack::Stack(){

}

Stack::~Stack(){

}

void Stack::push(int value){
    insertAtBack(value);
}

int Stack::pop(){
    int item = first->val;
    removeFromBack();
    return item;
}

int& Stack::top(){
    return last->val;
}