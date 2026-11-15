#include "picture.hpp"
#include <iostream>
#include <utility>

Picture::Picture()
	:head{nullptr}, tail{nullptr} // creation of head and tail data members
	// will work for the nested list of pictures 
{
}

// copies the shape into the end of the list 
void Picture::add(const Shape& shape)
{
    Shape* copy = shape.clone();  // copy so that the original shape isn't changed / deleted      
    ListNode* node = new ListNode{copy, nullptr}; // new node creation  
	if (head == nullptr) {  // exception checking for if the entire list is empty                 
        head = node;
    } else {                                       
        tail->next = node;
    }
    tail = node;                                  
}


// similar to how we print out letters in string for hw 5 
// iterate through the List of nodes and then print each one out 
void Picture::print_all(std::ostream& out) const
{
    for (ListNode* p = head; p != nullptr; p = p->next) {
        p->shape->print(out);
		p->shape->draw(out);
    }
}

// temp added circle draw so now just loop through and call that shapes draw function 
void Picture::draw_all(std::ostream& out) const
{
    for (ListNode* p = head; p != nullptr; p = p->next) {
        p->shape->draw(out);
    }
}

// all the functions are doing the same thing just looping through every shape and getting the area using the shapes area function 
double Picture::total_area() const
{
    double total = 0.0;
    for (ListNode* p = head; p != nullptr; p = p->next) {
        total += p->shape->area();
    }
    return total;
}


Picture::~Picture()
{
}
