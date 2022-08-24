/*************************************************************************
   This is the header file for a class called Song. It holds the 
   information about a single song, the name, release date, and artist. 
   It uses a class called Date for the storage of the release date. 
   The member functions are just accessors and input/output functions.

	   Patricia Lindner	    Spring 2022		Ohio University
*************************************************************************/

#include <iostream>
#include <string>
#include "date.h"
#ifndef SONG_H
#define SONG_H

class Song{
    public:
		Song();
		std::string get_name()const;
		Date get_release()const;
        std::string get_artist()const;

		bool operator == (const Song& other)const;
		bool operator != (const Song& other)const;

		void input(std::istream& ins);
		void output(std::ostream& outs)const;

    private:
		std::string name;
		Date release;
        std::string artist;
};

std::istream& operator >> (std::istream& ins, Song& s);
std::ostream& operator << (std::ostream& outs, const Song& s);

#endif