// MultimediaManager.h
#ifndef MULTIMEDIA_MANAGER_H
#define MULTIMEDIA_MANAGER_H

#include <iostream>
#include <map>
#include <memory>
#include <string>
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"

class MultimediaManager {
private:
    std::map<std::string, std::shared_ptr<Multimedia>> multimediaTable;
    std::map<std::string, std::shared_ptr<Group>> groupTable;

    double calculateSimilarity(const std::string& query, const std::string& target);
public:
    MultimediaManager();
    ~MultimediaManager();

    // Methods to create and add multimedia objects to the tables
    std::shared_ptr<Photo> createPhoto(const std::string& name, const std::string& filePath, double latitude, double longitude);
    std::shared_ptr<Video> createVideo(const std::string& name, const std::string& filePath, int duration);
    std::shared_ptr<Film> createFilm(const std::string& name, const std::string& filePath, int duration, int* chapterDurations, int numChapters);
    std::shared_ptr<Group> createGroup(const std::string& name);

    // Methods to search and display multimedia objects or groups
    void displayObject(const std::string& objectName, std::ostream& os) const;
    void displayGroup(const std::string& groupName, std::ostream& os) const;

    // Method to play a multimedia object
    void playObject(const std::string& objectName) const;

    // Method to delete a multimedia object or group
    void deleteObject(const std::string& objectName);
    void deleteGroup(const std::string& groupName);
    void searchMedias(const std::string& queryName, std::ostream& os);
    void searchGroups(const std::string& queryName, std::ostream& os);
    // Method to get the exact group by name
    std::shared_ptr<Group> getGroup(const std::string& groupName);
    std::shared_ptr<Multimedia> getMedia(const std::string& objectName);
};

#endif // MULTIMEDIA_MANAGER_H
