/**
 * @file pant.h
 * @author Keegan Goecke
 * @brief Class file for pant.h
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef PANT_H
#define PANT_H
#include <iostream>
#include <string>
#include "product.h"
using namespace std;

class Pant:public Product{
    public:
        // constructor
        Pant();

        // getters and setters
        string get_color(){return color;}
        string get_style(){return style;}
        string get_size(){return size;}
        int get_pockets(){return pockets;}
        void set_color(string inp);
        void set_style(string inp);
        void set_size(string inp);
        void set_pockets(int inp);

        // other funcions
        void input(istream& ins);
        void output(ostream& outs);
        double cost();

    private:
        string color;
        string style;
        string size;
        int pockets;

};

// constructor
Pant::Pant(){
    color = "WHITE";
    style = "SHORTS";
    size = "L";
    pockets = 0;
}

// getters and setters
void Pant::set_color(string inp){
    color = inp;    // sets color to inp
}

void Pant::set_style(string inp){
    style = inp;    // sets style to inp
}

void Pant::set_size(string inp){
    size = inp; // sets size to inp
}

void Pant::set_pockets(int inp){
    pockets = inp;  // sets pockets to inp
}

// other functions
void Pant::input(istream& ins){
    if(&ins == &cin){   // checks if ins is cin
        int c = 0;
        int s = 0;
        int sz = 0;
        int p = 0;
        string holder;
        while(c == 0){  // loops while c = 0
            cout << "COLORS:\n1.WHITE\n2.BLACK\n3.GREAY\n4.RED\n5.BLUE" << endl;    // list of colors
            cout << "Enter a color (1-5):"; // prompts user input
            cin >> c;   // gets input
            if(c > 0 && c < 6){
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
        while(s == 0){
            cout << "STYLES:\n1.SWEATPANTS\n2.SHORTS" << endl;  // list of styles
            cout << "Enter a style(1-2): "; // prompts user input
            cin >> s;   // get input from user
            if(s > 0 && s < 3){
                if(s == 1){
                    holder = "SWEATPANTS";  // sets holder to sweatpants
                    set_style(holder);  // sets style to holder
                }else{
                    holder = "SHORTS";  // sets holder to shorts
                    set_style(holder);  // sets style to holder
                }
            }else{
                s = 0;  // continues loop
                cout << "ERROR: invalid style, Try again." << endl; // error message
            }
        }
        while(sz == 0){ // loops while sz is 0
            cout << "SIZES:\n1.S\n2.M\n3.L" << endl;    // list of sized
            cout << "Enter a size(1-3): ";   // prompts user input
            cin >> sz;  // gets inpout
            if(sz > 0 && sz < 4){
                if(sz == 1){
                    holder = "S";   // sets holder to s
                    set_size(holder);   // sets size to holder
                }else if(sz == 2){
                    holder = "M";   // sets holder to m
                    set_size(holder);   // sets size to holder
                }else{
                    holder = "L";   // sets holder to l
                    set_size(holder);   // sets size to holder
                }
            }else{
                sz = 0; // continues loopo
                cout << "ERROR: invalid size, Try again." << endl;  // error message
            }
        }
        while(p == 0){
            cout << "Number of pockets 2, 4, or 6" << endl; // number of pockets
            cout << "Enter a number of pockets: ";  // prompts user input
            cin >> p;   // gets pockets
            if(p == 2){ 
                set_pockets(p); // sets pockets to p
            }else if(p == 4){
                set_pockets(p); // sets pockets to p
            }else if(p == 6){
                set_pockets(p); // sets pockets to p
            }else{
                p = 0;  // continues loop
                cout << "ERROR: invalid number of pockets, Try again" << endl;  // error message
            }
        }
    }else{
        string place;
        while(ins.peek() == '\n' || ins.peek() == '\r'){    // checks for end line characters
            ins.ignore();   // ignores all end line characters
        }
        ins >> place;   // gets color from file
        color = place.substr(place.find(":") + 1);  // sets color to substr of place
        while(ins.peek() == '\n' || ins.peek() == '\r'){    // checks for end line characters
            ins.ignore();   // ignores all end line characters
        }
        ins >> place;    // gets style from file
        style = place.substr(place.find(":") + 1);  // sets tyle to substr of place
        while(ins.peek() == '\n' || ins.peek() == '\r'){    // checks for end line characters
            ins.ignore();   // ignores all end line characters
        }
        ins >> place;   // gets size from file
        size = place.substr(place.find(":") + 1);   // sets size to substr of place
        while(ins.peek() == '\n' || ins.peek() == '\r'){    // checks for end line characters
            ins.ignore();   // ignores all end line characters
        }
        ins >> pockets; // gets pockets from file
    }


}

void Pant::output(ostream& outs){
    // outputs pants info
    outs << "-PANTS-" << endl;
    outs << "COLOR:" << get_color() << endl;
    outs << "STYLE:" << get_style() << endl;
    outs << "SIZE:" << get_size() << endl;
    outs << get_pockets() << endl;
}

double Pant::cost(){
    double price = 0.0; // base price
    if(get_style() == "SWEATPANTS"){    // checks if style is sweatpants
        price += 24.99; // updates price
    }else{
        price += 15.99; // updates price
    }

    if(get_pockets() == 2){ // checks if pockets is 2
        price += 4.99;  // updates price
    }else if(get_pockets() == 4){   // checks if pockets is 4
        price += 9.99;  // updates price
    }else{
        price += 14.99; // updates price
    }
    return price;   // returns price
}

#endif