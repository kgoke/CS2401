/**
 * @file dnode.h
 * @author Keegan Goecke
 * @brief Class file for dnode
 * @version 0.1
 * @date 2022-03-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef DNODE_H
#define DNODE_H
#include <iostream>
using namespace std;

template<class T>
class dnode{
    public:
        dnode(T data, dnode *n = NULL, dnode *p = NULL){data_field = data; nxtptr = n; prevptr = p;}
        // setters
        void set_data(T data){data_field = data;}
        void set_next(dnode *n){nxtptr = n;}
        void set_previous(dnode *p){prevptr = p;}

        // list functions
        dnode* next(){return nxtptr;}
        dnode* previous(){return prevptr;}
        T data()const{return data_field;}



    private:
    dnode *nxtptr;   // next pointer for node
    dnode *prevptr;  // previous pointer for node
    T data_field;   // data of node
};
#endif