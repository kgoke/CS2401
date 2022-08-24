/**
 * @file product.h
 * @author Keegan Goecke
 * @brief Class file for product.h
 * @version 0.1
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <fstream>

class Product{
    public:
        // constructor
        Product(){return};  // returns nothing to exit constructor

        // other functions
        virtual void input(std::istream& ins){return;}  // virtual function for input
        virtual void output(std::ostream& outs){return;}    // virtual function for output
        virtual double cost(){return 0.0;}  // virtual funciton for cost


    private:
};
// overloads >> operator
std::istream& operator >> (std::istream& ins, Product& s){
    s.input(ins);   // s input set to ins
    return ins; // returns ins
}
//overloads << operator
std::ostream& operator << (std::ostream& outs, Product& s){
    s.output(outs); // s output set to outs
    return outs;    // returns outs
}
#endif