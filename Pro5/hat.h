/**
 * @file pant.h
 * @author Keegan Goecke
 * @brief Class file for pant.h
 * @version 0.1
 * @date 2022-04-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef HAT_H
#define HAT_H
#include "product.h"
#include <iostream>
#include <string>
using namespace std;

class Hat:public Product{
    public:
        //constuctor
        Hat();

        // getters and setters
        string get_style(){return style;}
        string get_color(){return color;}
        string get_brim(){return brim;}
        void set_style(string inp);
        void set_brim(string inp);
        void set_color(string inp);

        // other functions
        void input(istream& ins);
        void output(ostream& outs);
        double cost();

    private:
        string style;
        string brim;
        string color;
};

// constructor
Hat::Hat(){
    style = "FITTED";
    brim = "CURVED";
    color = "WHITE";
}

// getters and setter
void Hat::set_style(string inp){
    style = inp;    // sets tyle to inp
}

void Hat::set_brim(string inp){
    brim = inp; // sets brim to inp
}

void Hat::set_color(string inp){
    color = inp;    // sets color to inp
}

// other functions
void Hat::input(istream& ins){
    if(&ins == &cin){   // checks if ins is cin
        int s = 0;
        int b = 0;
        int c = 0;
        string holder;
        while(s == 0){  // loops while s = 0
            cout << "STYLES:\n 1.FITTED\n2.SNAPBACK\n3.ADJUSTABLE" << endl; // list of syles
            cout << "Enter a style(1-3): "; // prompts user inpout
            cin >> s;   // gets input
            if(s > 0 && s < 4){
                if(s == 1){
                    holder = "FITTED";  // sets holder to fitted
                    set_style(holder);  // sets style to holder
                }else if(s == 2){
                    holder = "SNAPBACK";    // sets holder to snapback
                    set_style(holder);  // sets style to holder
                }else{
                    holder = "ADJUSTABLE";  // sets adjustable to holder
                    set_style(holder);  // sets style to holder
                }
            }else{
                s = 0;  // continues loop
                cout << "ERROR: invalid style, Try again"<< endl;   // error message
            }
        }
        while(b == 0){  // loops while b is 0
            cout << "BRIMS:\n1.CURVED\n2.STRAIGHT" << endl; // list of brims
            cout << "Enter a brim(1-2): ";  // prompts user input
            cin >> b;   // gets b
            if(b > 0 && b < 3){
                if(b == 1){
                    holder = "CURVED";  // sets holder to curvd
                    set_brim(holder);   // sets brim to holder
                }else{
                    holder = "STRAIGHT";    // sets holder to straight
                    set_brim(holder);   // sets brim to holder
                }
            }else{
                b = 0;  // continues loop
                cout << "ERROR: invalid brim, Try again." << endl;  // error message
            }
        }
        while(c == 0){  // loops while c is 0
            cout << "COLORS:\n1.WHITE\n2.BLACK\n3.GREAY\n4.RED\n5.BLUE" << endl;    // list of colors
            cout << "Enter a color (1-5):"; // prompts user input
            cin >> c;   // get input from user
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
    }else{
        string place;
        while(ins.peek() == '\n' || ins.peek() == '\r'){    // checks for end line characters
            ins.ignore();   // ignores all end line characters
        }
        ins >> place;   // gets style
        style = place.substr(place.find(":") + 1);  // sets style to substr of place
        while(ins.peek() == '\n' || ins.peek() == '\r'){    // checks for end line characters
            ins.ignore();   // ignores all end line characters
        }
        ins >> place;   // gets brim
        brim = place.substr(place.find(":") + 1);   // sets brim to substr of place
        while(ins.peek() == '\n' || ins.peek() == '\r'){    // checks for end line characters
            ins.ignore();   // ignores all end line characters
        }
        ins >> place;   // gets color
        color = place.substr(place.find(":") + 1);  // sets color to substr of place
    }

}

void Hat::output(ostream& outs){
    // outputs hat info
    outs << "-HAT-" << endl;
    outs << "STYLE:" << get_style() << endl;
    outs << "BRIM:" << get_brim() << endl;
    outs << "COLOR:" << get_color() << endl;
}

double Hat::cost(){
    double price = 15.00;   // base cost
    if(get_style() == "SNAPBACK"){  // check if style is snapback
        price += 2.25;  // updates price
    }else if(get_style() == "FITTED"){  // checks if style is fitted
        price += 3.25;  // updates price
    }else{
        price += 1.25;  // updates price
    }

    if(get_brim() == "STRAIGHT"){   // checks if brim is striahht
        price += 3.40;  // updates price
    }
    return price;   // returns price
}

#endif