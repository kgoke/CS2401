/*************************************************************************
   This class is a container that holds objects of the class Song.
   It uses an internal iterator to give the application the ability to
   order the container as well as access to the elements in the container.
   Because it uses dynamic memory it needs to have the Big3.

	Patricia Lindner	Fall 2021		Ohio University EECS
*************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include "Song.h"
#ifndef PLAYLIST_H
#define PLAYLIST_H

class Playlist{
    public:
        Playlist();

        // The Big 3
        ~Playlist();
        Playlist(const Playlist& other);
        void operator = (const Playlist& other);

        // Functions for the internal iterator
        void start();
        void advance();
        bool is_item()const;
        Song current()const;

        // Other useful things the user may want to do
        void remove_current();
        void insert(const Song& s);
        void attach(const Song& s);
        
        void show_all(std::ostream& outs)const;
        void releaseDate_sort();
        void artist_sort();
        Song find_song(const std::string& name)const;
        bool is_song(const Song& s) const;

        void load(std::istream& ins);
        void save(std::ostream& outs)const;

    private:
        Song *data;
        int used;
        int capacity;
        int current_index;

        void resize(); // increases the capacity of the container by 5
};

#endif