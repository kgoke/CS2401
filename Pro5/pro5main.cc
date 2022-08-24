/**
 * @file pro5main.cc
 * @author Keegan Goecke
 * @brief Main file cs2401 project 5
 * @version 0.1
 * @date 2022-04-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include "product.h"
#include "shirt.h"
#include "hat.h"
#include "chain.h"
#include "pant.h"
#include "glasses.h"
using namespace std;
void menu();
void menu2();

int main(){
    list<Product*> items;   // creates STL list of Product* called items

    // fstreams
    ifstream fin;
    ofstream fout;

    fin.open("orders.txt"); // opens backup file
    if(!fin.fail()){    // checks if backup file opens
        string temp;    // string to get product type
        while(!fin.eof()){
            fin >> temp;    // gets type
            if(temp == "-SHIRT-"){ // check is shirt is the product
                Product* tmp = new Shirt;   // creates new shirt
                tmp -> input(fin);  // reads info from file
                items.push_back(tmp);   // pushed shirt to list
            }else if(temp == "-HAT-"){  // checks if hat is the product
                Product* tmp = new Hat; // creates new hat
                tmp -> input(fin);  // reads info from file
                items.push_back(tmp);   // pushes hat to the list
            }else if(temp == "-GLASSES-"){  // checks if product is glasses
                Product* tmp = new Glasses; // creates new glasses
                tmp -> input(fin);  // reads info from file
                items.push_back(tmp);   // pushed glasses to list
            }else if(temp == "-PANTS-"){    // checks if product is pants
                Product* tmp = new Pant;    // creates new pants
                tmp -> input(fin);  // reads info from file
                items.push_back(tmp);   // pushes pants to list
            }else if(temp == "-CHAIN-"){    // checks if product is chain
                Product* tmp = new Chain;   // creates new chain
                tmp -> input(fin);  // reads info from file
                items.push_back(tmp);   // pushed chain to list
            }
        }
        items.pop_back();
        fin.close();    // closes backup file
    }


    int option = 0;
    cout << "WELCOME TO KGOKE's SHOP!" << endl << endl;
    while(option != 3){ // loops unit option is 4
        menu(); // displays menu
        cin >> option;  // gets option fro user
        if(option < 0 || option > 4){   // checks if option is valid
            cout << "ERROR: invalid option, Try again" << endl; // error message
        }else{  // if option is valid continues
            if(option == 1){
                int choice = 0;
                while(choice != 6){ // loops until choice is 6
                    menu2();    // displays menu
                    cin >> choice;  // gets choice from user
                    if(choice == 1){    // checks if choice is 1
                        Product* tmp;   // creates new product tmp
                        tmp = new Shirt;    // tmp is a new shirt
                        tmp -> input(cin);  // gets shirt info from user
                        items.push_back(tmp);   // adds shirt to list
                        choice = 6; // ends the loop
                    }else if(choice == 2){  // checks if choice is 2
                        Product* tmp;   // creates new product tmp
                        tmp = new Hat;  // tmp is a new hat
                        tmp -> input(cin);  // gets hat info from user
                        items.push_back(tmp);   // adds hat to list
                        choice = 6; // ends loop
                    }else if(choice == 3){  // check if choice is 3
                        Product* tmp;   // creates product tmp
                        tmp = new Pant; // tmp is a new pant
                        tmp -> input(cin);  // gets pant info from user
                        items.push_back(tmp);   // adds pant to list
                        choice = 6; // ends list    
                    }else if(choice == 4){  // checks if choice is 4
                        Product* tmp;   // creates product tmp
                        tmp = new Glasses;  // tmp is new glasses
                        tmp -> input(cin);  // gets glasses info from user
                        items.push_back(tmp);   // adds glasses to list
                        choice = 6; // ends loop    
                    }else if(choice == 5){  // checks if choice is 5
                        Product* tmp;   // creates product tmp
                        tmp = new Chain;    // tmp is a new chain
                        tmp -> input(cin);  // gets chain info from user
                        items.push_back(tmp);   // adds chain to list
                        choice = 6; // ends loop
                    }
                }

            
            }else if(option == 2){  // checks if option is 3
                cout << endl << "-----YOUR ORDERS-----" << endl;
                list<Product*>::iterator it;    // creates iterator it
                double total = 0.0; // creates total for cart
                for(it = items.begin(); it != items.end(); ++it){   // loops through list
                    (*it) -> output(cout);  // outputs products in list
                    total += (*it) -> cost();   // adds product cost to total 
                    cout << endl;   // end line character
                }   
                cout << endl << "Your total: $" << total << endl;   // outputs order total
            }else if(option == 3){
                cout << endl << "THANK YOU FOR SHOPPING" << endl;
                fout.open("orders.txt");    // opens backup file
                list<Product*>::iterator it2;   // creates iterator it2
                for(it2 = items.begin(); it2 != items.end();++it2){ // loops through list
                    (*it2) -> output(fout); // outputs product to backup file
                    fout << endl;   // end line character
                }
                fout.close();   // closes output file
            }
        }
    }

    return 0;
}

void menu(){
    // displays menu asking user what they would like to do
    cout << "WHAT WOULD YOU LIKE TO DO?" << endl;
    cout << "1. ADD A PRODUCT" << endl;
    cout << "2. VIEW YOUR ORDERS" << endl;
    cout << "3. EXIT" << endl;
    cout << "Enter an option: ";    // prompts user input
}
void menu2(){
    // displays menu of products
    cout << "WHAT WOULD YOU LIKE TO ADD?" << endl;
    cout << "1. SHIRT" << endl;
    cout << "2. HAT" << endl;
    cout << "3. PANTS" << endl;
    cout << "4. GLASSES" << endl;
    cout << "5. CHAIN" << endl;
    cout << "6. EXIT" << endl;
    cout << "Enter an option: ";    // prompts user input
}
