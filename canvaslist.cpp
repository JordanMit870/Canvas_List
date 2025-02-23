#include "canvaslist.h"

#include <iostream>

using namespace std;


// Do I need these?? I don't think so- I thibk I just added these-
// ShapeNode::ShapeNode(){
//     value = nullptr; // Shape*
//     next = nullptr; //ShapeNode*
// }

// ShapeNode::~ShapeNode(){
//     delete[] next; //idk-
//     // delete[] next;
// }

//////////Core tasks//////////
CanvasList::CanvasList(){
    this -> list_size = 0;
    this -> list_front = nullptr; //check?
}

ShapeNode*  CanvasList::front() const{
    return list_front;
    // if(list_front.value == nullptr){
    //     return 1;
    // }
    // else{
    //     return list_front;
    // }
    
}

bool CanvasList::empty() const{
    //check if it is a ShapeNode being called?
    if( list_size == 0 && list_front == nullptr ){  //
        //issue with how list_front is intalized?
        return true;
        // list_size = 0;

    }

    return false;

}

int CanvasList::size() const{
    return list_size;
}

void CanvasList::push_front(Shape* newShape){
    ShapeNode* shapeAdded = new ShapeNode;
    shapeAdded->value = newShape;
    if(list_front == nullptr){ //if empty
        // shapeAdded-> = newShape;
        // this->list_front->next = nullptr;
        shapeAdded -> next = nullptr;
    }
    else{
        shapeAdded -> next = list_front;
        //ShapeNode* temp = new ShapeNode;
        // temp->value = newShape;
        // temp->next = list_front; //adds the rest of the old list
        // this->list_front = temp; //saves over new data
    }
    list_front = shapeAdded;
    list_size++;
}

void CanvasList::clear(){ 

    while(!empty())  {
        Shape* temp = pop_front();
        delete temp;
        // Shape* oldValue = list_front->value;
        // ShapeNode* oldNode = list_front;
        // list_front = list_front->next;
        // delete oldValue;
        // delete oldNode;       
    }
    list_size = 0;
    list_front = nullptr;

    //   ShapeNode* curr = list_front;
    //   if(list_front != nullptr){ //only runs if not empty
    //     while(curr != nullptr){ //deletes everything after the front
    //             // ShapeNode* next  = curr->next; //causes memory leak-
    //             // delete curr->value;
    //             // curr = next; //moves to next ptr

    //             ShapeNode* next  = curr; //causes double free- nvm, I think it's good now
    //             curr = curr->next;
    //             delete next;
    //         }
    //         // list_front = nullptr; //to shot that it is now empty
    //         list_size = 0;
    //     }
  
}

CanvasList:: ~CanvasList(){ 
    clear();
    //delete list_front;
}
//////////Core tasks//////////

//////////Iterating tasks//////////

CanvasList::CanvasList(const CanvasList& oldCanvas){ 
    list_front = nullptr;
    list_size = 0;
   
    if(oldCanvas.list_front != nullptr){
        ShapeNode* oldCurr = oldCanvas.list_front; // so I can iterate and not change the og node
        list_front = new ShapeNode;
        list_front->value = oldCanvas.list_front->value->copy();
        list_front-> next = nullptr;
        list_size++;
        ShapeNode* curr = list_front;
        
        while(oldCurr->next != nullptr){ //copies everything over
            ShapeNode* temp = new ShapeNode; //saves data from oldCanvas and makes space
            temp-> value = oldCurr->next->value->copy();
            temp -> next = nullptr;

            curr->next = temp; 
            curr = curr->next;
            list_size++;
            oldCurr = oldCurr->next;
        }
    
    }
    
}

void CanvasList::push_back(Shape* newShape){
    ShapeNode* shapeAdded = new ShapeNode;
    shapeAdded->value = newShape;
    shapeAdded->next = nullptr;
    if(list_front == nullptr){
        list_front = shapeAdded;
        }
    else{
        ShapeNode* curr = list_front;// so I can keep track of head ptr
        while(curr->next != nullptr){ //loops to the end of the list
        curr = curr->next;
            }
        curr-> next = shapeAdded;
    }
    
    list_size++;

}

void CanvasList::draw() const{
    if(list_front == nullptr){ //if empty
        //do nothing IG
    }
    else{
        ShapeNode* curr = list_front;
        while(curr != nullptr){
            cout << curr->value->as_string() << endl;
            curr = curr->next;
        }

    }
}

void CanvasList::print_addresses() const{
    //Node Address: 0x562ac60e82a0	Shape Address: 0x562ac60e8280
     if(list_front == nullptr){ //if empty
        //do nothing IG
    }
    else{
        ShapeNode* curr = list_front;
        while(curr != nullptr){
            cout << "Node Address: "<< curr << "	Shape Address: " << curr->value << endl;
            curr = curr->next;
        }

    }
}

Shape* CanvasList::shape_at(int loc) const{
    if(list_front != nullptr){ //if empty
        if(list_size <= loc || loc < 0){ // if out of bounds
            return nullptr;
        }
        else{
        ShapeNode* curr = list_front;
        for(int i = 0; i < loc; i++){
            curr = curr->next;
        }
        return curr->value;
        }
    }
    
    return nullptr;
}

int CanvasList::find(int x, int y) const{
    //int x, int y
    if(list_front == nullptr){
        return -1;
    }
    else{
        int loc = 0;
        ShapeNode* curr = list_front;
        while(curr != nullptr){
            if(curr->value->getX() == x && curr->value->getY() == y){
                return loc;
            }
            curr = curr->next;
            loc++;
        }
        return -1;
    }
    
}

//////////Iterating tasks//////////

//////////Modifying tasks//////////

CanvasList &CanvasList::operator=(const CanvasList& oldCanvas){ 
    //Taken from copy- ;P
    if(this == &oldCanvas){
        return *this;
    }
    clear();
    list_front = nullptr;
    list_size = 0; 

    if(oldCanvas.list_front != nullptr){
        ShapeNode* oldCurr = oldCanvas.list_front; // so I can iterate and not change the og node
        list_front = new ShapeNode;
        list_front->value = oldCanvas.list_front->value->copy();
        list_front-> next = nullptr;
        list_size++;
        ShapeNode* curr = list_front;
        
        while(oldCurr->next != nullptr){ //copies everything over
            ShapeNode* temp = new ShapeNode; //saves data from oldCanvas and makes space
            temp-> value = oldCurr->next->value->copy();
            temp -> next = nullptr;

            curr->next = temp; 
            curr = curr->next;
            list_size++;
            oldCurr = oldCurr->next;
        }
    
    }

    return *this;
}

Shape* CanvasList::pop_front(){ 
    if (list_front == nullptr) { // if empty
        return nullptr;
    }
    
    // if(list_front != nullptr){ //more than 1
        Shape* s = list_front->value;
        ShapeNode* temp = list_front;
        list_front = list_front->next;
        // delete temp->value;
        delete temp;
        
        list_size--;
        return s;
    // }
   
    // else{ //if only 1 shape
    //     Shape* s = list_front->value;
    //     delete list_front->value;
    //     delete list_front; //deletes shape
    //     list_front = nullptr; //resets data
    //     list_size--;
    //     return s;
    // }
    

}

Shape* CanvasList::pop_back(){ //having memory issues...
    if (list_front == nullptr) { // if empty
        return nullptr;
    }

    if(list_front->next == nullptr){ //if one shape only
        Shape* s = list_front->value;
        ShapeNode* temp = list_front;
        // delete temp->value;
        delete temp; //deletes shape
        list_front = nullptr; //resets data
        list_size--;
        return s;
    }

    ShapeNode* curr = list_front;
    while(curr->next->next != nullptr){ //if more than 1
        curr = curr->next;
    }
    Shape* s = curr->next->value; 
    // delete curr->next->value; 
    delete curr->next; 
    curr->next = nullptr;
    list_size--;
    return s;
 
}

void CanvasList::remove_at(int loc){
    if(list_front == nullptr){ //if not empty
        return;
     }
    if(list_size <= loc || loc < 0){ // if out of bounds
        return;
    }
    if(loc == 0){ //if first value
      Shape* f = pop_front();
      delete f;
    }
    else if(loc == list_size-1){ //if last value
        Shape* b = pop_back();
        delete b;
    }
    else{ //in the middle
        ShapeNode* curr = list_front;
        for(int i = 0; i < loc-1; i++){ //stops one before
         curr = curr->next;
            }
        ShapeNode* temp = curr->next;
        curr->next = curr->next->next; //skips to next node
        delete temp->value;
        delete temp;
        list_size--;
    }
    
}

//////////Modifying tasks//////////


void CanvasList::insert_after(int loc, Shape* newShape){
    //in week 7 lecture video
    if(list_size <= loc || loc < 0){ // if out of bounds
        //also covers if empty
        // delete newShape;
        return;
    }

    ShapeNode* temp = new ShapeNode; //holding new shape
    temp->value = newShape;
    temp->next = nullptr;

    // if(list_front == nullptr){ // if empty?
    //     push_front(newShape); //also increases list_size
    //     return;
    // }
    if(list_front->next == nullptr){ //only 1
        list_front->next = temp;
        list_size++;
        return; //I could have done push_back, but eh-
     }
    if(loc == 0){ //insert after first
        ShapeNode* after = list_front->next; //saves the rest of the nodes
        list_front->next = temp; //adds new node
        temp->next = after; //adds the rest of the list
        list_size++;
        return;
     }
     if(loc == list_size-1){ //insert at the end
     push_back(newShape); //also increases list_size
     delete temp;
     return;
     }
    //insert anywhere else
    ShapeNode* curr = list_front;
   
    for(int i = 0; i < loc; i++){ //go to the position since we're inserting after
        curr = curr->next;
    }

    ShapeNode* after = curr->next; //saves the rest of the nodes
    curr->next = temp; //adds new node
    temp->next = after; //adds the rest of the list
    list_size++;
    return;
    
}

void CanvasList::remove_every_other(){ //currently not working...
    //use remove at. remove odd nums

    if(list_front == nullptr){//if empty
        return;
    }
    if(list_front->next == nullptr){//if 1 only
        return;
    }
    ShapeNode* curr = list_front;
    while(curr != nullptr && curr->next !=nullptr){ //only get odd nums
        // cout << "//////////////"<<list_size << "//////////////" << endl;
        ShapeNode* temp = curr->next;
        curr->next = curr->next->next;
        delete temp->value;
        delete temp;
        list_size--;   
        curr = curr-> next;
    }
}
//////////CanvasList//////////
