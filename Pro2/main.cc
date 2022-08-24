/*************************************************************************
    Project 2		CS2401		Spring 2022

    This is the main for your second project, a project which works with 
    the concepts of a sequence class, an internal iterator, and a dynamic 
    array.

    In order to make this main work you will need to write two classes,
    one called Song and one called Playlist. Going through the code
    below you should be able to figure out what member functions are
    needed for each. Also, since Playlist is holding dynamic memory, you 
    will need to write the Big 3 for this class.

        Patricia Lindner    Spring 2022       Ohio University EECS
*************************************************************************/
    

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Song.h"
#include "Playlist.h"
using namespace std;

int menu();
int menu2();

int main(){

    Song song;
    Playlist mySongs;

    string songname, username, filename, sorting;
    int choice, choice2;
    bool cutout;

    ifstream fin;
    ofstream fout;

	cout<<"Welcome to Your Playlist Management System.\n\n";
	cout<<"Begin by entering your username: ";
	getline(cin,username);

	filename = username + ".txt";
	fin.open(filename.c_str());

    if(!fin.fail()){
	    mySongs.load(fin);
    }
	fin.close();

	choice = 0;
	choice2 = 0;
	cutout = false;
    Playlist original(mySongs);

	while(choice != 9){
	    choice = menu();
	    switch(choice){
            case 1:
                cin >> song;
                mySongs.start();
                mySongs.insert(song);
                break;
            case 2:
                mySongs.show_all(cout);
                break;
            case 3: 
                mySongs.start();
                choice2 = 0;
                while(mySongs.is_item() && choice2 <= 5){
                    cout << mySongs.current();
                    choice2 = menu2();
                    if(choice2 == 1){
                        mySongs.remove_current();
                    }
                    else if(choice2 == 2){
                        if(!cutout){
                            cin >> song;
                        }
                        if(mySongs.is_song(song)){
                            cout << "That song is already in your playlist.\n";
                        }
                        else{
                            mySongs.insert(song);
                            cutout = false;
                        }
                    }
                    else if(choice2 == 3){
                        if(!cutout){
                            cin >> song;
                        }
                        if(mySongs.is_song(song)){
                            cout << "That song is already in your playlist.\n";
                        }
                        else{
                            mySongs.attach(song);
                            cutout = false;
                        }
                    }
                    else if(choice2 == 4){
                        song = mySongs.current();
                        mySongs.remove_current();
                        cutout = true;
                    }
                    else if(choice2 == 5){
                        mySongs.advance();
                    }
                    else{
                        cout << "Returning to main menu.\n";
                    }
                }
                break;
            case 4:
                cout << "Do you want to sort by release date or artist: ";
                cin >> sorting;
                if(sorting == "artist"){
                    mySongs.artist_sort();
                }
                else if(sorting == "release date"){
                    mySongs.releaseDate_sort();
                }
                else{
                    cout << "Invalid choice, returning to menu" << endl;
                }
                break;
            case 5:
                cout << "Enter the name of the song: ";
                while(cin.peek() == '\n' || cin.peek() == '\r'){
                    cin.ignore();
                }
                getline(cin, songname);
                song = mySongs.find_song(songname);
                if(song != Song()) cout << song << endl;
                break;
            case 6:	
                original.show_all(cout);
                break;
            default:
                break;
		} // bottom of the switch
	} // bottom of the while

	fout.open(filename.c_str());
    if(!fout.fail()){
        mySongs.save(fout);
    }
	else{
	    cout << "Unable to save data.\n";
    }
	fout.close();

	cout << "Check out your playlist again soon.\n";
    return 0;
}
	
int menu(){
	int ans;

	cout << "Choose from the options below:\n";
	cout << "1 - Add a song to the beginning of the list.\n";
	cout << "2 - See all your songs.\n";
	cout << "3 - Walk through the list, one song at a time.\n";
	cout << "4 - Sort your songs by release date or artist.\n";
	cout << "5 - See the release date and artist for a song.\n";
	cout << "6 - See the list you started with in today's session.\n";
	cout << "9 - Leave the program.\n";

	cin >> ans;
    return ans;
}

int menu2(){
	int ans;

	cout << "What would like to do with this song?\n";
	cout << "1 - Remove it from the list.\n";
	cout << "2 - Insert a new or cut-out song before this song.\n";
	cout << "3 - Put a new or cut-out song after this song.\n";
	cout << "4 - Cut this song from the list to be inserted elsewhere.\n";
	cout << "    If you want the song earlier in the list you will need to start a new walk-through.\n";
	cout << "5 - Advance to the next song.\n";
	cout << "6 - Return to main menu.\n";

	cin >> ans;
    return ans;
}