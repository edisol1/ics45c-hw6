#include "picture.hpp"
#include <iostream>
#include <utility>

Picture::Picture()
	:head{nullptr}, tail{nullptr} // creation of head and tail data members
	// will work for the nested list of pictures 
	// empty picture with no shapes 
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

// copy constructor takes the picture and then goes through the picture and adds it to this picture
Picture::Picture(const Picture& other)
    : head{nullptr}, tail{nullptr}
{
    for (ListNode* p = other.head; p != nullptr; p = p->next) {
        add(*p->shape);
    }
}

// for the dying pictures that will be destructed taking over and moving the memory 
Picture::Picture(Picture&& other)
    : head{other.head}, tail{other.tail}
{
    other.head = nullptr;
    other.tail = nullptr;
}

// trade lists with other
void Picture::swap(Picture& other)
{
    std::swap(head, other.head);
    std::swap(tail, other.tail);
}

// copy assignment 
// makes a full copy of the picture and the trades the lists 
Picture& Picture::operator=(const Picture& other)
{
    Picture copy{other};
    swap(copy);
    return *this;
}

// doesnt need a copy since the originally picture memory will be freed shortly usually  
Picture& Picture::operator=(Picture&& other)
{
    swap(other);
    return *this;
}


// since picture is a collection of shapes ( linked list of them ) 
// destructor needs to go through each node and delete each one 
Picture::~Picture()
{
    ListNode* p = head;
    while (p != nullptr) {
        ListNode* next = p->next;
        delete p->shape;
        delete p;
        p = next;
    }
}
