/**
 * @file Song.cc
 * @author Keegan Goecke
 * @brief Implementation file for the Song.h class
 * @version 0.1
 * @date 2022-02-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
#include "Song.h"

using namespace std;

Song::Song(){}

string Song::get_name()const{
    return name;    // returns name
}

Date Song::get_release()const{
    return release; // returns release
}

string Song::get_artist()const{
    return artist;  // returns artist
}

bool Song::operator == (const Song& other)const{
    string nm1, nm2, ar1, ar2;  // strings to hold names and artist

    nm1 = name; // sets nm1 to name
    nm2 = other.name;   // sets nm2 to other.name
    ar1 = artist;   // sets ar1 to artist
    ar2 = other.artist; // sets ar2 to other.artist

    for(int i = 0; i < nm1.length(); i++){  // loops through nm1
        nm1[i] = tolower(nm1[i]);   // sets each character to lowercase
    }
    for(int i = 0; i < nm1.length(); i++){  // loops through nm2
        nm2[i] = tolower(nm2[i]);   // sets each character to lowercase
    }
    for(int i = 0; i < ar1.length(); i++){  // loops through ar1
        ar1[i] = tolower(ar1[i]);   // sets each character to lowercase
    }
    for(int i = 0; i < ar2.length(); i++){  // loops through ar2
        ar2[i] = tolower(ar2[i]);   // sets each character to lowercase
    }
    if(ar1 == ar2 && nm1 == nm2){   // checks if the name and artist are the same
        return true;    // returns true
    }
    return false;   // returns false
}

bool Song::operator != (const Song& other)const{
    string nm1, nm2, ar1, ar2;  // strings to hold names and artist

    nm1 = name; // sets nm1 to name
    nm2 = other.name;   // sets nm2 to other.name
    ar1 = artist;   // sets ar1 to artist
    ar2 = other.artist; // sets ar2 to other.artist

    for(int i = 0; i < nm1.length(); i++){  // loops through nm1
        nm1[i] = tolower(nm1[i]);   // sets each character to lowercase
    }
    for(int i = 0; i < nm1.length(); i++){  // loops through nm2
        nm2[i] = tolower(nm2[i]);   // sets each character to lowercase
    }
    for(int i = 0; i < ar1.length(); i++){  // loops through ar1
        ar1[i] = tolower(ar1[i]);   // sets each character to lowercase
    }
    for(int i = 0; i < ar2.length(); i++){  // loops through ar2
        ar2[i] = tolower(ar2[i]);   // sets each character to lowercase
    }
    if(ar1 != ar2 || nm1 != nm2){   // checks if either of the string are not equal to the other
        return true;    // returns true
    }
    return false;   // returns false
}

void Song::input(istream& ins){
    if(&ins == &cin){   // check for what type of input
        cout << "Enter song name: ";    // promtps user to enter song name
        while(ins.peek() == '\n' || ins.peek() == '\r'){    // checks for end line characters
            ins.ignore();   // ignores all end line characters
        }
        getline(ins, name); // gets the name

        cout << "Enter song artist: "; // promtps user to enter song artist
        while(ins.peek() == '\n' || ins.peek() == '\r'){    // checks for end line characters
            ins.ignore();   // ignores all end line characters
        }
        getline(ins, artist);

        cout << "Enter song release: "; // prompts user to enter song release date
        while(ins.peek() == '\n' || ins.peek() == '\r'){    // checks for end line characters
            ins.ignore();   // ignores all end line characters
        }
        ins >> release;
    }else{
        while(ins.peek() == '\n' || ins.peek() == '\r'){    // checks for end line characters
            ins.ignore();   // ignores all end line characters
        }
        getline(ins, name); // gets the name

        while(ins.peek() == '\n' || ins.peek() == '\r'){    // checks for end line characters
            ins.ignore();   // ignores all end line characters
        }
        getline(ins, artist);   // gets the artist

        while(ins.peek() == '\n' || ins.peek() == '\r'){    // checks for end line characters
            ins.ignore();   // ignores all end line characters
        }
        ins >> release; // gets release date
    }
}

void Song::output(ostream& outs)const{
    outs << name << endl;   // outputs the name
    outs << artist << endl; // outputs the artist
    outs << release << endl; // outputs the release
}

istream& operator >> (istream& ins, Song& s){
    s.input(ins);
    return ins;
}

ostream& operator << (ostream& outs, const Song& s){
    s.output(outs);
    return outs;
}

