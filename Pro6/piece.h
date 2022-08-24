/**
 * @file piece.h
 * @author Keegan Goecke
 * @brief Class file for piece.h
 * @version 0.1
 * @date 2022-04-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef PIECE_H
#define PIECE_H
#include "colors.h"
#include <iostream>

class piece{
    public:
    // constructor
    piece();
    // getters and setters
    void set_w();
    void set_b();
    void set_e();
    bool is_w()const;
    bool is_b()const;
    bool is_e()const;
    // other functions
    void flip();

    private:
    bool white;
    bool black;
    bool empty;
};

#endif