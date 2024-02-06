//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "MultimediaManager.h"

using namespace std;

int main(int argc, const char* argv[])
{
    MultimediaManager manager;

    // Create some multimedia objects
    auto photo1 = manager.createPhoto("cartafronte", "./media/fronte.jpg", 40.7128, -74.006);
    auto video1 = manager.createVideo("tama", "./media/tamagotchi.mp4", 120);
    int chapterDurations[] = {10, 15, 20};
    auto film1 = manager.createFilm("tamafilm", "./media/tamagotchi.mp4", 60, chapterDurations, 3);

    // Create a group and add multimedia objects to it
    auto group1 = manager.createGroup("Group1");
    group1->push_back(photo1);
    group1->push_back(video1);
    group1->push_back(film1);

    // Display multimedia objects and group
    
    manager.displayObject("cartafronte", cout);
    manager.displayObject("tama", cout);
    manager.displayObject("tamafilm", cout);
    manager.displayGroup("Group1", cout);

    // Play a multimedia object
    manager.playObject("cartafronte");

    // Delete a multimedia object and display the group again
    manager.deleteObject("cartafronte");
    manager.displayGroup("Group1", cout);

    // Delete the group and display multimedia objects again
    manager.deleteGroup("Group1");
    manager.displayObject("tama", cout);

    return 0;
}