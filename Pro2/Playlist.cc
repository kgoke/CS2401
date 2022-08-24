/**
 * @file Playlist.cc
 * @author Keegan Goecke
 * @brief Implem file for Playlist.h class
 * @version 0.1
 * @date 2022-02-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include "Playlist.h"

using namespace std;

// constuctors
Playlist::Playlist(){}

// The Big 3
Playlist::~Playlist(){
    delete []data;  // deallocates the data
}

Playlist::Playlist(const Playlist& other){
    used = other.used;  // sets used to other used
    capacity = other.capacity;  // sets capacity to other capacity
    current_index = other.current_index;    // sets current_index to other current_index
    data = new Song[other.capacity];    // creates array with size of other.capacity
    copy(other.data, other.data + used, data);  // copys information to data
}

void Playlist::operator = (const Playlist& other){
    Song* tmp = data;   // new tmp
    if(capacity < other.capacity){  // checks if capacity is less than other capacity
        tmp = new Song[other.capacity]; // new array with size of other.capacity
        delete [] data; // deallocates data
        data = tmp; // sets data to tmp
        capacity = other.capacity;  // sets capacity to other capacity
        used = other.used;  // sets used to other used
        current_index = other.current_index;    // sets current_index to other current_index
        copy(other.data, other.data + used, data);  // copys info to data
    }
}

// Functions for the internal iterator
void Playlist::start(){
    current_index = 0; // sets current index to 0 which is the beginning
}

void Playlist::advance(){
    current_index++;    // updates current index by 1
}

bool Playlist::is_item()const{
    bool tf = false;    // initializes tf to false
    if(current_index < used){ // checks if current index is less than used
        tf = true;  // sets tf to true
    }
    return tf;  // returns tfs
}

Song Playlist::current()const{
    return data[current_index]; // returns the current index of the song
}

// Other useful things the user may want to do
void Playlist::remove_current(){
    for(int i = current_index; i <= used; i++){ // loops from current index to used
        data[i] = data[i+1];    // shifts current over 1
    }
    used--; // decreases used by 1 which deletes removes the current
}

void Playlist::insert(const Song& s){
    if(used >= capacity){   // checks if capacity has been reached
        resize();   // resizes the array
    }  
    if(!is_item()){ // checks if is_item is false
        current_index = 0;  // sets current index to = if is_item is false
    }
    for(int i = used; i > current_index; i--){  // loops from used until current index
        data[i] = data[i-1];    // shifts data over 1
    }
    data[current_index] = s;    // sets data at current index to the new song input
    used++; // updates the used counter for the new song
}

void Playlist::attach(const Song& s){
    if(used >= capacity){   // checks if capacity has been reached
        resize();   // resized the array
    }
    if(!is_item()){ // checks if is_item is false
        current_index = used;   // sets currrent index to used
        data[current_index] = s;    // sets data at current index to the new song
        used++; // updates the used counter
    }else{
        for(int i = used; i >= current_index; i--){ // loops from used to current index
            data[i] = data[i - 1];  // shifts data over 1
        }
        data[current_index] = s;    // sets data at current index + 1 to new song
        current_index++;    // updates the current index counter
        used++; // updates the used counter
    }

}

void Playlist::show_all(ostream& outs)const{
    for(int i = 0; i <= used; i++){ // loops from start to used
        outs << endl;   // outputs line break
        outs << data[i].get_name() << endl; // outputs song name
        outs << data[i].get_artist() << endl;   // outputs song artist
        outs << data[i].get_release() << endl;  // outputs song release data
    }
}

void Playlist::releaseDate_sort(){}

void Playlist::artist_sort(){}

Song Playlist::find_song(const string& name)const{
    for(int i = 0; i <= used; i++){ // loops from begging to used
        if(name == data[i].get_name()){   // checks if name == name at i
            return data[i]; // return name at i
        }
    }
    Song tmp;   // creates tmp song for output
    cout << endl << "ERROR: song not found." << endl;   // error message if song is not found
    return tmp; // returns a blank song
}

bool Playlist::is_song(const Song& s) const{
    bool tf = false;    // tf set to false
    for(int i = 0; i <= used; i++){ // loops from start to used
        if(s.get_name() == data[i].get_name()){ // checks if that song name exist
            tf = true;  // sets tf to true
        }
    }
    return tf;  // returns tf
}

void Playlist::load(istream& ins){
    while(!ins.eof()){  // loops unitl end of file
        while(ins.peek() == '\n' || ins.peek() == '\r'){    // checks for end line characters
            ins.ignore();   // ignores end line characters
        }
        used++; // adds one to used
        ins >> data[used];  // takes input from file at used
    }
}

void Playlist::save(ostream& outs)const{
    for(int i = 0; i <= used; i++){ // loops from start until used;
        outs << data[i].get_name() << endl; // outputs the name
        outs << data[i].get_artist() << endl;   // outputs the artist
        outs << data[i].get_release() << endl;  // outputs the release date
    }
}

void Playlist::resize(){
    Song* tmp;  // temp pointer song
    tmp = new Song[capacity + 5]; // temp array with a size of capacity + 5
    for(int i = 0; i <= used; i++){
        tmp[i] = data[i];   // sets tmp at i == data at i
    }
    delete []data;  // deallocates data
    data = tmp; // sets data equal to temp
    capacity += 5; // adds five to the capacity counter
}


