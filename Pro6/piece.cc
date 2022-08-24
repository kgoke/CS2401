/**
 * @file piece.cc
 * @author Keegan Goecke
 * @brief Implementation file for piece.h
 * @version 0.1
 * @date 2022-04-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "piece.h"
#include <iostream>

piece::piece(){
    empty = true;
    white = false;
    black = false;
}

void piece::set_w(){
    white = true;
    black = false;
    empty = false;
}

void piece::set_b(){
    black = true;
    white = false;
    empty = false;
}

void piece::set_e(){
    empty = true;
    white = false;
    black = false;
}

bool piece::is_w()const{
    if(white){
        return true;
    }
    return false;
}

bool piece::is_b()const{
    if(black){
        return true;
    }
    return false;
}

bool piece::is_e()const{
    if(empty){
        return true;
    }
    return false;
}

void piece::flip(){
    if(white){
        set_b();
    }else{
        set_w();
    }
}