/**
 * @file glasses.h
 * @author Keegan Goecke
 * @brief Class fiel for glasses.h
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef GLASSES_H
#define GLASSES_H
#include "product.h"
#include <iostream>
#include <string>
using namespace std;

class Glasses:public Product{
    public:
        // constructor
        Glasses();

        // getters and setters
        string get_color(){return color;}
        string get_type(){return type;}
        string get_l_color(){return l_color;}
        void set_color(string inp);
        void set_type(string inp);
        void set_l_color(string inp);

        // other functions
        void input(istream& ins);
        void output(ostream& outs);
        double cost();

    private:
        string color;
        string type;
        string l_color;
};

//constructor
Glasses::Glasses(){
    color = "WHITE";
    type = "CIRCLE";
    l_color = "CLEAR";
}

// getters and setters
void Glasses::set_color(string inp){
    color = inp;    // sets color to inp
}

void Glasses::set_type(string inp){
    type = inp; // sets type to inp
}

void Glasses::set_l_color(string inp){
    l_color = inp;  // sets l_color to inp
}

// other functions
void Glasses::input(istream& ins){
    if(&ins == &cin){   // checks if ins is cin
        int c = 0;
        int t = 0;
        int l = 0;
        string holder;
        while(c == 0){  // loops while c is 0
            cout << "BODY COLORS:\n1.WHITE\n2.BLACK\n3.GREAY\n4.RED\n5.BLUE" << endl;   // list of colors
            cout << "Enter a color (1-5):"; // prompts user input
            cin >> c;   // gets color from user
            if(c > 0 && c < 6){ // checks if color is valid
                if(c == 1){
                    holder = "WHITE";   // sets holder to white
                    set_color(holder);  // sets color to holder
                }else if(c == 2){   
                    holder = "BLACK";   // sets holder to black
                    set_color(holder);  // sets color to holder
                }else if(c == 3){
                    holder = "GREY";    // sets holder to grey
                    set_color(holder);  // sets color to holder
                }else if(c == 4){
                    holder = "RED"; // sets holder to red
                    set_color(holder);  // sets color to holder
                }else{
                    holder = "BLUE";    // sets holder to blue
                    set_color(holder);  // sets color to holder
                }
            }else{
                c = 0;  // continues loop   
                cout << "ERROR: invalid color, Try again." << endl; // error message
            }
        }
        while(t == 0){  // loops while t is 0
            cout << "TYPES:\n1.CIRCLE\n2.SQUARE\n3.OVAL" << endl;   // list of types
            cout << "Enter a type(1-3): ";  // prompts user input
            cin >> t;   // gets input from user
            if(t == 1){ 
                holder = "CIRCLE";  // sets holder to circle
                set_type(holder);   // sets type to holder
            }else if(t == 2){
                holder = "SQUARE";  // sets holder to square 
                set_type(holder);   // sets type to holder
            }else if(t == 3){
                holder = "OVAL";    // sets holder to oval
                set_type(holder);   // sets type to holder
            }else{
                t = 0;  // continues loop
                cout << "ERROR: invalid type, Try again." << endl;  // error message
            }
        }
        while(l == 0){  // loops while l is 0
            cout << "LENSE COLORS:\n1.CLEAR\n2.BLACK\n3.GREAY\n4.RED\n5.BLUE" << endl;  // list of lense colors
            cout << "Enter a color (1-5):"; // prompts user input
            cin >> l;   // gets input from user
            if(l > 0 && l < 6){
                if(l == 1){
                    holder = "ClEAR";   // sets holder to clear
                    set_l_color(holder);  // sets l_color to holder
                }else if(l == 2){
                    holder = "BLACK";   // sets holder to black
                    set_l_color(holder);    // sets l_color to holder
                }else if(l == 3){
                    holder = "GREY";    // sets holder to grey
                    set_l_color(holder);    // sets l_color to holder
                }else if(l == 4){
                    holder = "RED"; // sets holder to red
                    set_l_color(holder);    // sets l_color to holder
                }else{
                    holder = "BLUE";    // sets holder ot blue
                    set_l_color(holder);    // sets l_color to holder 
                }
            }else{
                l = 0;  // continues loop
                cout << "ERROR: invalid color, Try again." << endl; // error message
            }
        }
    }else{
        string place;
        while(ins.peek() == '\n' || ins.peek() == '\r'){    // checks for end line characters
            ins.ignore();   // ignores all end line characters
        }
        ins >> place;   // gets color
        color = place.substr(place.find(":") + 1);  // sets color to substr of place
        while(ins.peek() == '\n' || ins.peek() == '\r'){    // checks for end line characters
            ins.ignore();   // ignores all end line characters
        }
        ins >> place;   // gets type
        type = place.substr(place.find(":") + 1);   // sets type to substr of place
        while(ins.peek() == '\n' || ins.peek() == '\r'){    // checks for end line characters
            ins.ignore();   // ignores all end line characters
        }
        ins >> place;   // gets l_color
        l_color = place.substr(place.find(":") + 1);    // sets l_color to substr of place
    }
}

void Glasses::output(ostream& outs){
    // outputs glasses info
    outs << "-GLASSES-" << endl;
    outs << "COLOR:" << get_color() << endl;
    outs << "TYPE:" << get_type() << endl;
    outs << "LEN_COLOR:" << get_l_color() << endl;
}

double Glasses::cost(){
    double price = 15.99;   // base price
    if(get_l_color() != "CLEAR"){   // checks if l_color is not clear
        price += 9.99;  // updates price
    }

    return price;   // returns price
}

#endif