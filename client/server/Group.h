/**
 * @file Group.h
 * @brief This file contains the Group class.
 */

#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <memory>
#include <iostream>
#include "Multimedia.h"

/**
 * @class Group
 * @brief This class represents a group of multimedia objects.
 * 
 * It contains a name and a list of shared pointers to multimedia objects.
 */
class Group {
private:
    std::string name; ///< The name of the group.
    std::list<std::shared_ptr<Multimedia>> objects; ///< The list of multimedia objects in the group.

public:
    /**
     * @brief Parameterized constructor.
     * 
     * @param name The name of the group.
     */
    Group(const std::string& name) : name(name) {}

    /**
     * @brief Add an object to the group.
     * 
     * @param object The object to add.
     */
    void push_back(std::shared_ptr<Multimedia> object) {
        objects.push_back(object);
    }

    /**
     * @brief Remove a specific object from the group.
     * 
     * @param object The object to remove.
     */
    void remove(std::shared_ptr<Multimedia> object) {
        objects.remove(object);
    }

    /**
     * @brief Display the attributes of all objects in the group.
     * 
     * @param os The output stream to display the information to.
     */
    void display(std::ostream& os) const {
        std::cout << "Group: " << name << "\n";
        for (const auto& object : objects) {
            object->display(os);
            std::cout << "\n";
        }
    }
};

#endif // GROUP_H