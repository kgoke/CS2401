/**
 * @file dlist.h
 * @author Keegan Goecke
 * @brief Class file for dlist
 * @version 0.1
 * @date 2022-03-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef DLIST_H
#define DLIST_H
#include "dnode.h"
#include "node_iterator.h"

template <class T>
class dlist{
    public:
    // constructor
    dlist();

    // BIG THREE
    ~dlist();
    dlist(const dlist<T> &other);
    void operator = (const dlist<T> &other);

    // List functions
    void rear_insert(T item);
    void front_insert(T item);
    void front_remove();
    void rear_remove();
    void show();
    int size();
    void reverse_show();

    // iterator functions
    typedef dnode_iterator<T> iterator;
    
    void remove(iterator it);
    void insert_before(iterator it, T item);
    void insert_after(iterator it, T item);
    iterator begin(){return iterator(head);}
    iterator end(){return iterator(NULL);}
    iterator r_begin(){return iterator(tail);}
    iterator r_end(){return iterator(NULL);}

    private:
        dnode<T> *head;  // head for list
        dnode<T> *tail;  // tail for list
};

#include "dlist.template"   // connects dlist.template
#endif

