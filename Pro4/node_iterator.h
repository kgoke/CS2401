/**
 * @file node_iterator.h
 * @author Keegan Goecke
 * @brief Class file for node_iterator
 * @version 0.1
 * @date 2022-03-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef NODE_ITERATOR_H
#define NODE_ITERATOR_H
#include "dnode.h"
#include <iostream>

template<class T> class dlist;

template<class T>
class dnode_iterator{
    public:
        friend class dlist<T>;  // adds dlist<T> as a friend to node_iteraotr class

        dnode_iterator(dnode<T>* c = NULL){current = c;}

        bool operator!=(dnode_iterator other)const;  // not equal to op
        bool operator==(dnode_iterator other)const;  // equal to op
        T operator*()const;
        dnode_iterator operator++(); //prefix - ++it
        dnode_iterator operator++(int); //postfix - it++
        dnode_iterator operator--(); // prefix- --t
        dnode_iterator operator--(int);  // postfix - it--

    private:
        dnode<T> *current;   // current node
};

#include "node_iterator.template"   // connects node_iterator.template

#endif