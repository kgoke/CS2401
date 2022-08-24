/**
 * @file Planner.h
 * @author Keegan Goecke
 * @brief Class file for Planner.h
 * @version 0.1
 * @date 2022-02-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
#include "date_time.h"
#include "assignment.h"
#include "node.h"
#ifndef PLANNER_H
#define PLANNER_H

class Planner{
    public:
        Planner();
        
        // THE BIG 3
        ~Planner();
        Planner(const Planner& other);
        Planner& operator = (const Planner& other);

        // PROJECT FUNCTIONS

        // 1. add a new assignment to the list(insterted in order)
        void add(Assignment a);

        // 2. view the entire list of assignment, in order thay are stored
        void display(std::ostream& outs)const;

        // 3. remove an assignment that has been completed. This will use the find and
        // remove functions, both of which take a string which is a name of an assignemnt
        Assignment find(std::string name);

        void remove(std::string name);

        // 4. Learn the number of assignments that are waiting to be completed
        int waiting()const;
        
        // 5. See the amount of tie you have to complete the assignment that is due soonest.
        // (this assignment should be at the front of the list.)
        unsigned due_next()const;
        
        // 6. See the average amount of time that assignments have been sitting in the list
        // since they were entered
        unsigned average_wait()const;
        
        // 7. Identify the assignment that has been in the list the longest
        unsigned oldest()const;

        // 8. identify the assignment that was added to the list most recently
        unsigned newest()const;

        // 9. See all assignments that must be completed by a date entered by user.
        void find_all(DateTime due_by);

        // 10. Load planner function
        void load(std::istream& ins);

        // 11. Save planner functions
        void save(std::ostream& outs)const;

    private:
    node* head;

};

std::string conv_low(std::string input);

#endif