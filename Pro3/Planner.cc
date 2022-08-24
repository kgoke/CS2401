/**
 * @file Planner.cc
 * @author Keegan Goekce
 * @brief implementation file for Planner.h
 * @version 0.1
 * @date 2022-02-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
#include "Planner.h"
#include "node.h"
#include "assignment.h"

using namespace std;

// constuctors
Planner::Planner(){
    head = NULL;
}

// THE BIG 3
Planner::~Planner(){
    node* rmptr;
    while(head != NULL){
        rmptr = head;
        head = head -> link();
        delete rmptr;
    }
}

Planner::Planner(const Planner& other)
{
    if(other.head == NULL){
        head = NULL;    
    }
    else{
        node* src, *dest;
        head = new node(other.head -> data());
        src = other.head -> link();
        dest = head;
        while(src != NULL){
            dest -> set_link(new node(src -> data()));
            src = src -> link();
            dest = dest -> link();
        }
    }
}
Planner& Planner::operator = (const Planner& other){
    if(this == &other){
        return *this;
    }
    // deconstructor code to remove old list
    node* rmptr;
    while(head != NULL){
        rmptr = head;
        head = head -> link();
        delete rmptr;
    }
    // copy constructor code
    if(other.head == NULL){
        head = NULL;
    }
    else{
        node* src, *dest;
        head = new node(other.head -> data());
        src = other.head -> link();
        dest = head;
        while(src != NULL){
            dest -> set_link(new node(src -> data()));
            src = src -> link();
            dest = dest -> link();
        }
    }
    return *this;
}

// Project functions

// 1. add a new assignment to the list(insterted in order)
void Planner::add(Assignment input){
    if(head == NULL){   // checks if list is empty
        head = new node(input); // sets head to input
    }
    else if(head -> data().minutes_til_due() > input.minutes_til_due()){    // checks if head is greater than input
        head = new node(input, head);   // head to input pointing at old head
    }
    else{
        node* prev = head;  // sets prev to head
        node* cur = head -> link(); // sets cur to head link()
        
        while(cur != NULL){ // loops through list
            if(cur -> data().minutes_til_due() > input.minutes_til_due()){  // checks if cur > input
                prev -> set_link(new node(input));  // sets prev link to input
                prev -> link()->set_link(cur);  // sets prev link-link to cur
                return; // returns
            }
            prev = prev -> link();  // moves prev over one node
            cur = cur -> link();    // moves cur over one node
        }
        prev -> set_link(new node(input));  // adds input to end of list
    }
}

// 2. view the entire list of assignment, in order thay are stored
void Planner::display(ostream& cout)const{
    node* cursor = head;    // sets cursor to head
    while (cursor != NULL){ // loosp through list
		cout << cursor -> data();   // outputs cursor data
		cursor = cursor -> link();  // moves cursor over on node
    }
	cout << endl;   // outputs line break

}

// 3. remove an assignment that has been completed. This will use the find and
// remove functions, both of which take a string which is a name of an assignemnt
Assignment Planner::find(string name){
    node* cursor = head;    // sets cursor to head
    Assignment check, def;  // makes two default assignments
    string compare = "";    // empty string for compare

    while(cursor != NULL){  // loops through list
        compare = cursor -> data().get_name();  // sets compare ot cursor name
        if(conv_low(name) == conv_low(compare)) {   // checks if names are equal
            check = cursor -> data();   // if the same sets check to curosr data
        }
        cursor = cursor -> link();  // moves cursor over one node
    }
    if(check == def){   // sees if check is still a default assignment
        cout << endl << "ERROR: assignment not found." << endl; // outputs error message
    }
    return check;   // returns check
}

void Planner::remove(string name){
    node* prev = head;  // sets prev to head
    node* cur = head -> link(); // sets cur to head link()
    string check;   // string for check 
    check = conv_low(head -> data().get_name());    // sets check to lowercase of heads name
    if(check == conv_low(name)){    // sees if check == input name
        head = cur; // sets head ot curent
        delete prev;    // deletes previous
    }

    while(cur != NULL){ // loops while cur isnt null
        check = conv_low(cur -> data().get_name()); // sets check to lowercase of curs name
        if(check == conv_low(name)){    // checks if names are equal
            prev -> set_link(cur -> link());    // sets previous link to current link
            delete cur; // deletes current
        }
        else{
            prev = cur; // moves previous over one node
            cur = cur -> link();    // moves cur over one node
        }
    }
}

// 4. Learn the number of assignments that are waiting to be completed
int Planner::waiting()const{
    node* cursor = head;    // sets cursor to head
    int num = 0;    // sets num to zero
    if(head == NULL){   // checks if list is emtpy
        return num; // returns 0
    }
    while(cursor != NULL){  // loops through list
        cursor = cursor -> link();  // moves cursor over one node
        num++;  // updates num
    }
    return num; // returns num
}
        
// 5. See the amount of time you have to complete the assignment that is due soonest.
// (this assignment should be at the front of the list.)
unsigned Planner::due_next()const{
    unsigned soonest = 0;   // sets soonest to zero
    Assignment check;   // creates assignment check
    if(head == NULL){   // checks if list is empty
        cout << endl << "ERROR: empty list." << endl;   // outputs error message
        return soonest; // returns zero
    }
    soonest = head -> data().minutes_til_due(); // gets the time till do of head
    return soonest; // returns soonest
}   
        
// 6. See the average amount of time that assignments have been sitting in the list
// since they were entered
unsigned Planner::average_wait()const{
    unsigned average = 0;   // sets average to zero
    int count = 0;  // sets count to zero
    if(head == NULL){   // check if list is empty
        cout << endl << "ERROR: Empty list." << endl;   // outputs error message
        return average; // returns zero
    }
    node* cursor = head;    // sets cursor to head
    while(cursor != NULL){  // loops through the list
        average = average + cursor -> data().minutes_waiting(); // adds minutes waiting to cursor
        count++;    // adds one to counts
        cursor = cursor -> link();  // moves cursor over one node
    }
    average = average / count;  // divided total mins by count
    return average; // returns average
}
        
// 7. Identify the assignment that has been in the list the longest
unsigned Planner::oldest()const{
    unsigned oldest = 0;    // sets oldest to zero
    if(head == NULL){   // checks if list is empty
        cout << endl << "ERROR: Empty list." << endl;   // outputs error message
        return oldest;  // returns 0
    }
    node* cursor = head;    // sets cursor to head
    oldest = cursor -> data().minutes_waiting();    // sets oldest to cursor minute waiting
    while(cursor != NULL){  // loops through list
        if(oldest < cursor -> data().minutes_waiting()){    // checks if oldes is is less than cursor waiting time
            oldest = cursor -> data().minutes_waiting();    // updates oldest
        }
        cursor = cursor -> link();  // moves cursor over one node
    }
    return oldest;  // return oldest
}

// 8. identify the assignment that was added to the list most recently
unsigned Planner::newest()const{
    unsigned newest = 0;    // sets newest to 0
    if(head == NULL){   // checks if list is empty
        cout << endl << "ERROR: epmty list." << endl;   // outputs error message
        return newest;  // returns 0
    }
    node* cursor = head;    // sets cursor to head
    newest = cursor -> data().minutes_waiting();    // sets newest to cursor waiting time
    while(cursor != NULL){  // loops through the list
        if(newest > cursor -> data().minutes_waiting()){    // checks if newest is greater than curosr waiting time
            newest = cursor -> data().minutes_waiting();    // updates newest
        }
        cursor = cursor -> link();  // moves cursor over one node
    }
    return newest;  // returns newest

}

// 9. See all assignments that must be completed by a date entered by user.
void Planner::find_all(DateTime due_by){
    node* cursor = head;    // sets cursor to head
    Assignment tmp; // makes a tmp assignment
    while(cursor != NULL){  // loops until cursor is NULL
        tmp = cursor -> data(); // sets tmp to cursor data
        if(tmp.get_due() < due_by){ // checks if the get due is less than input
            cout << cursor -> data() << endl;   // outputs the assignments
        }
        cursor = cursor -> link();  // moves cursor over one node
    }
}

// 10. Load planner function
void Planner::load(istream& ins){
    while(!ins.eof()){
        Assignment tmp, check;  // creates two default assignments
        ins >> tmp; // reads assignment from file
        if(tmp.get_name() != check.get_name()){ // checks if the read assignment was a default
            this -> add(tmp);   // if not adds the assignment to the list
        }
    }
}

// 11. Save planner functions
void Planner::save(ostream& outs)const{
    node* cursor = head;    // sets cursor to head
    while (cursor != NULL){ // loops while curosr is not NULL
		outs << cursor -> data() << endl;   // outputs data at cursor
		cursor = cursor -> link();  // moves cursor to next node
    }
}

//OTHER FUNCTIONS

 string conv_low(string input){
    string output = ""; // empty string for output
    for(int i = 0; i < input.length(); i++){    // loops through the name
        output += tolower(input[i]);    // converts each char to lowercase and adds it to the output string
    }
    return output;  // returns the output
 }