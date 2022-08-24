/**
 * @file shirt.h
 * @author Keegan Goecke
 * @brief Class file for shirt.h
 * @version 0.1
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SHIRT_H
#define SHIRT_H
#include "product.h"
#include <iostream>
#include <string>
using namespace std;

class Shirt:public Product{
    public:
        // constructor
        Shirt();

        // getters and setters
        string get_size(){return size;}
        string get_color(){return color;}
        string get_design(){return design;}
        string get_material(){return material;}
        void set_size(string inp);
        void set_color(string inp);
        void set_design(string inp);
        void set_material(string inp);

        // other functions
        void input(istream& ins);
        void output(ostream& outs);
        double cost();

    private:
        string size;
        string color;
        string design;
        string material;

};

//constructor
Shirt::Shirt(){
    size = "L";
    color = "WHITE";
    design = "NONE";
    material = "COTTON";
}

// getters and setter
void Shirt::set_size(string inp){
    size = inp; // sets size to inp
}

void Shirt::set_color(string inp){
    color = inp;    // sets color to inp
}

void Shirt::set_design(string inp){
    design = inp;   // sets design to inp
}

void Shirt::set_material(string inp){
    material = inp; // sets material to inp
}

// other functions
void Shirt::input(istream& ins){
    if(&ins == &cin){   // checks if input type is cin
        int sz = 0;
        int col = 0;
        int mat = 0;
        string holder;
        while(sz == 0){
            cout << "SIZES:\n1.XS\n2.S\n3.M\n4.L\n5.XL" << endl;    // ouputs sizes
            cout << "Enter a size(1-5): ";  // prompts user to enter size
            while(cin.peek() == '\n' || cin.peek()=='\r'){cin.ignore();}    // ignores any end line characters
            cin >> sz;  // gets size from user
            if(sz > 0 && sz < 6){
                if(sz == 1){    // checks if sz is 1
                    holder = "XS";  // sets holder to xs
                    set_size(holder);   // sets size to holder
                }else if(sz == 2){  // checks if sz is 2
                    holder = "S";   // sets holder to s
                    set_size(holder);   // sets size to holder
                }else if(sz == 3){  // checks if sz is 3
                    holder = "M";   // sets holder to m
                    set_size(holder);   // sets size to holder
                }else if(sz == 4){  // checks if sz is 4
                    holder = "L";   // sets holder to l
                    set_size(holder);   // sets size to holder
                }else{
                    holder = "XL";  // sets holder to xl
                    set_size(holder);   // sets size to holder
                }
            }else{
                sz = 0; // continues loop
                cout << "ERROR: invalid size, Try again." << endl;  // error message
            }
        }

        while(col == 0){
            cout << "COLORS:\n1.WHITE\n2.BLACK\n3.GREY\n4.RED\n5.BLUE" << endl;    // outpust list of colors
            cout << "Enter a color (1-5):"; // prompts user to enter color
            cin >> col; // gets color from user
            if(col > 0 && col < 6){ // checks if col is valid
                if(col == 1){   // checks if col is 1
                    holder = "WHITE";   // sets holder to white
                    set_color(holder);  // sets color to holder
                }else if(col == 2){ // checks if col is 2
                    holder = "BLACK";   // sets holder to black
                    set_color(holder);  // sets color to holder
                }else if(col == 3){ // checks if col is 3
                    holder = "GREY";    // sets holder to grey
                    set_color(holder);  // sets color to holder
                }else if(col == 4){ // checks if col is 4
                    holder = "RED"; // sets holder to red
                    set_color(holder);  // sets color to holder
                }else{
                    holder = "BLUE";    // sets holder to blue
                    set_color(holder);  // sets color to holder
                }
            }else{
                col = 0;    // continues loop
                cout << "ERROR: invalid color, Try again." << endl; // error message
            }
        }

        while(mat == 0){
            cout << "MATERIALS:\n1.COTTON\n2.SILK\n3.WOOL" << endl; // outputslist of materials
            cout << "Enter a materaial(1-3):";  // promputs user input
            cin >> mat; // gets material
            if(mat > 0 && mat < 4){ // checks if mat is valid
                if(mat == 1){   // checks if mat is 1
                    holder = "COTTON";  // sets holder to cotton
                    set_material(holder);   // sets materail to holder
                }else if(mat == 2){ // checks if mat is 2
                    holder = "SILK";    // sets holder to silk
                    set_material(holder);   // sets materail to holder
                }else{
                    holder = "WOOL";    // sets holder to wool
                    set_material(holder);   // sets materail to holder
                }
            }else{  
                mat = 0;    // continues loop
                cout << "ERROR: invalid material, Try again." << endl;  // error message
            }
        }

        holder = "NONE";    // sets holder to none
        while(holder == "NONE"){    // loops while holder = none
            cout << "Enter a custom design for your shirt below" << endl;   // prompts user inoput
            cout << "->";
            while(cin.peek() == '\n' || cin.peek() == '\r'){cin.ignore();}  // ignores begining white spaces
            getline(cin, holder);   // gets holder
            if(holder != "NONE"){   // check if holder != none
                set_design(holder); // sets design to holder
                holder = "END"; // sets holder to end
            }else{
                cout << "ERROR: invalid design, Try again." << endl;    // outputs error message
                holder = "NONE";    // continues loop
            }
        }
    }else{
        string place;
        while(ins.peek() == '\n' || ins.peek() == '\r'){    // checks for end line characters
            ins.ignore();   // ignores all end line characters
        }
        ins >> place;   // gets size from file
        size = place.substr(place.find(":") + 1);   // sets size to substr of place
        while(ins.peek() == '\n' || ins.peek() == '\r'){    // checks for end line characters
            ins.ignore();   // ignores all end line characters
        }
        ins >> place;   // gets color from file
        color = place.substr(place.find(":") + 1);  // sets color to substr of place
        while(ins.peek() == '\n' || ins.peek() == '\r'){    // checks for end line characters
            ins.ignore();   // ignores all end line characters
        }
        ins >> place;   // gets material from file
        material = place.substr(place.find(":") + 1);   // sets material to substr of place
        while(ins.peek() == '\n' || ins.peek() == '\r'){    // checks for end line characters
            ins.ignore();   // ignores all end line characters
        }
        getline(ins, place);    // gets design from user
        design = place.substr(place.find(":") + 1); // sets design to substr of place
    }

}

void Shirt::output(ostream& outs){
    // outputs shirt information
    outs << "-SHIRT-" << endl;
    outs << "SIZE:" << get_size() << endl;
    outs << "COLOR:" << get_color() << endl;
    outs << "MATERIAL:" << get_material() << endl;
    outs << "DESIGN:" << get_design() << endl;
}

double Shirt::cost(){
    double price = 20.00;  // base price for shirt;
    if(get_material() == "SILK"){   // check if material is silk
        price += 5.25;  // updates price
    }else if(get_material() == "WOOL"){ // checks if material is wool
        price += 4.35;  // updates price
    }  
    return price;   // returns price
}   
#endif