/**
 * @file chain.h
 * @author Keegan Goecke
 * @brief Class fiel for chain.h
 * @version 0.1
 * @date 2022-04-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CHAIN_H
#define CHAIN_H
#include "product.h"
#include <iostream>
#include <string>
using namespace std;

class Chain:public Product{
    public:
        // constructor
        Chain();

        // getter and setters
        int get_length(){return length;}
        string get_material(){return material;}
        string get_pendent(){return pendent;}
        void set_length(int inp);
        void set_material(string inp);
        void set_pendent(string inp);

        // other functions
        void input(istream& ins);
        void output(ostream& outs);
        double cost();
    private:
        int length;
        string material;
        string pendent;
};

// constructor
Chain::Chain(){
    length = 20;
    material = "GOLD";
    pendent = "NONE";
}

// getters and setter
void Chain::set_length(int inp){
    length = inp;   // sets length to inp
}

void Chain::set_material(string inp){
    material = inp; // sets material to inp
}

void Chain::set_pendent(string inp){
    pendent = inp;  // sets pendent to inp
}

// other functions
void Chain::input(istream& ins){
    if(&ins == &cin)    // checks if ins is cin
    {
        int len = 0;
        int mat = 0;
        int pen = 0;
        string holder;
        while(len == 0){    // loops while len = 0
            cout << "Enter length of chain in inches (20-40in): ";  // prompts user input
            cin >> len; // gets input
            if(len < 20 || len > 40){   // checks if input is not valid
                len = 0;    // continues loop
                cout << "ERROR: invalid chain length, Try again." << endl;  // error message
            }else{
                set_length(len);    // sets lenth to len
            }
        }
        while(mat == 0){    // loops while mat is 0
            cout << "MATERIALS:\n1.SOLID-GOLD\n2.GOLD-PLATED\n3.SILVER" << endl;    // list of materials
            cout << "Enter a chain material (1-3): ";   // prompts user input
            cin >> mat; // gets input
            if(mat > 0 && mat < 4){
                if(mat == 1){
                    holder = "SOLID-GOLD";  // sets holder to solid-gold
                    set_material(holder);   // sets material to holder
                }else if(mat == 2){
                    holder = "GOLD-PLATED"; // sets holder to gold-plated
                    set_material(holder);   // sets material to holder
                }else{
                    holder = "SILVER";  // sets holder to silver
                    set_material(holder);   // sets material to holder
                }
            }else{
                mat = 0;    // continues loop
                cout << "ERROR: invalid chain material, Try again." << endl;    // error message
            }
        }
        while(pen == 0){    // loops while pen is 0
            cout << "PENDENTS:\n1.CROSS\n2.CUSTOM\n3.NONE" << endl; // list of pendents
            cout << "Enter a chain pendent(1-3): "; // prompts user input
            cin >> pen; // gets input
            if(pen > 0 && pen < 4){
                if(pen == 1){
                    holder = "CROSS";   // sets holder to cross
                    set_pendent(holder);    // sets pendent to cross
                }else if(pen == 2){
                    string cus; 
                    cout << "Enter custom pendent(Ex. Smiley Face): ";  //  prompts user input
                    while(cin.peek() == '\n' || cin.peek() == '\r'){cin.ignore();}  // ignores leading white spaces
                    getline(cin, cus);  // gets user input  
                    set_pendent(cus);   // sets pendent to cus
                }else{
                    holder = "NONE";    // sets holder to none
                    set_pendent(holder);    // sets pendent to holder
                }
            }
        }
    }
    else{
        string place;
        while(ins.peek() == '\n' || ins.peek() == '\r'){    // checks for end line characters
            ins.ignore();   // ignores all end line characters
        }
        ins >> length; // gets lenth from user
        while(ins.peek() == '\n' || ins.peek() == '\r'){    // checks for end line characters
            ins.ignore();   // ignores all end line characters
        }
        ins >> place;   // gets material fro file
        material = place.substr(place.find(":") + 1);   // sets material to substr of place

        while(ins.peek() == '\n' || ins.peek() == '\r'){    // checks for end line characters
            ins.ignore();   // ignores all end line characters
        }
        getline(ins, place);    // gets pendent from file
        pendent = place.substr(place.find(":") + 1);    // sets pendent to substr of place
    }
}

void Chain::output(ostream& outs){
    // outputs chain info
    outs << "-CHAIN-" << endl;
    outs << get_length() << endl;
    outs << "MATERIAL:" << get_material() << endl;
    outs << "PENDENT:" <<get_pendent() << endl;
}

double Chain::cost(){
    double price = 0.00;    // base cost

    if(get_length() < 20){  // checks if len is greater than 20
        price += 50.25; // updates price
    }else{
        price += 75.25; // updates price
    }

    if(get_material() == "SOLID-GOLD"){ // checks if material is solid-gold
        price += 999.99;    // updates price
    }else if(get_material() == "GOLD-PLATED"){  // checks if material is gold-plated
        price += 199.99;    // updates price
    }else{
        price += 49.99; // updates price
    }

    if(get_pendent() == "CROSS"){   // checks if pendent is cross
        price += 99.99; // updates price
    }else if(get_pendent() != "CROSS" && get_pendent() != "NONE"){ // checks if pendent is not cross or none
        price += 199.99;    // updates price
    }
    return price;   // returns price
}

#endif