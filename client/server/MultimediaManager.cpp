// MultimediaManager.cpp
#include "MultimediaManager.h"
#include <vector>
#include <algorithm>

MultimediaManager::MultimediaManager() {
    // Initialize any required setup for the manager
}

MultimediaManager::~MultimediaManager() {
    // Clean up resources, if needed
}
std::shared_ptr<Photo> MultimediaManager::createPhoto(const std::string& name, const std::string& filePath, double latitude, double longitude) {
    auto photo = std::make_shared<Photo>(name, filePath, latitude, longitude);
    multimediaTable[name] = photo;
    return photo;
}

std::shared_ptr<Video> MultimediaManager::createVideo(const std::string& name, const std::string& filePath, int duration) {
    auto video = std::make_shared<Video>(name, filePath, duration);
    multimediaTable[name] = video;
    return video;
}

std::shared_ptr<Film> MultimediaManager::createFilm(const std::string& name, const std::string& filePath, int duration, int* chapterDurations, int numChapters) {
    auto film = std::make_shared<Film>(name, filePath, duration, chapterDurations, numChapters);
    multimediaTable[name] = film;
    return film;
}

std::shared_ptr<Group> MultimediaManager::createGroup(const std::string& name) {
    auto group = std::make_shared<Group>(name);
    groupTable[name] = group;
    return group;
}

void MultimediaManager::displayObject(const std::string& objectName, std::ostream& os ) const {
    auto it = multimediaTable.find(objectName);
    if (it != multimediaTable.end()) {
        it->second->display(os);
    } else {
        std::cout << "Object not found: " << objectName << std::endl;
    }
}

void MultimediaManager::displayGroup(const std::string& groupName, std::ostream& os) const {
    auto it = groupTable.find(groupName);
    if (it != groupTable.end()) {
        it->second->display(os);
    } else {
        std::cout << "Group not found: " << groupName << std::endl;
    }
}

void MultimediaManager::playObject(const std::string& objectName) const {
    auto it = multimediaTable.find(objectName);
    if (it != multimediaTable.end()) {
        it->second->play();
    } else {
        std::cout << "Object not found: " << objectName << std::endl;
    }
}

void MultimediaManager::deleteObject(const std::string& objectName) {
    auto it = multimediaTable.find(objectName);
    if (it != multimediaTable.end()) {
        // Remove from all groups
        for (auto& group : groupTable) {
            group.second->remove(it->second);
        }
        multimediaTable.erase(it);
    } else {
        std::cout << "Object not found: " << objectName << std::endl;
    }
}

void MultimediaManager::deleteGroup(const std::string& groupName) {
    auto it = groupTable.find(groupName);
    if (it != groupTable.end()) {
        groupTable.erase(it);
    } else {
        std::cout << "Group not found: " << groupName << std::endl;
    }
}

// Method to find the 5 most similar media or groups by name    
void MultimediaManager::searchMedias(const std::string& queryName, std::ostream& os){
    // Create a vector to store pairs of object names and their similarity scores
    std::vector<std::pair<std::string, double>> similarities;
    
    std::cout << "Search: "  << std::endl;
    // Calculate similarity for each multimedia object
    for (const auto& entry : multimediaTable) {
        const std::string& name = entry.first;
        double similarityScore = calculateSimilarity(queryName, name);

        // Store the pair of name and similarity score
        similarities.push_back(std::make_pair(name, similarityScore));

   }

    std::sort(similarities.begin(), similarities.end(), [](const std::pair<std::string, double>& a, const std::pair<std::string, double>& b) {
        return a.second > b.second;
    });

    // Display the top 5 similar objects
    for (size_t i = 0; i < std::min<size_t>(5, similarities.size()); ++i) {
        os << similarities[i].first << " ,";
    }
}
void MultimediaManager::searchGroups(const std::string& queryName, std::ostream& os){
    // Create a vector to store pairs of object names and their similarity scores
    std::vector<std::pair<std::string, double>> similarities;

    // Calculate similarity for each multimedia object or group
    for (const auto& entry : groupTable) {
        const std::string& name = entry.first;
        double similarityScore = calculateSimilarity(queryName, name);

        // Store the pair of name and similarity score
        similarities.push_back(std::make_pair(name, similarityScore));
    }

    // Sort the vector based on similarity scores (descending order)
    std::sort(similarities.begin(), similarities.end(), [](const std::pair<std::string, double>& a, const std::pair<std::string, double>& b) {
        return a.second > b.second;
    });

    for (size_t i = 0; i < std::min<size_t>(5, similarities.size()); ++i) {
        os << similarities[i].first <<  " ,";
    }
}
// Helper method to calculate similarity (simple example: number of matching characters)
double MultimediaManager::calculateSimilarity(const std::string& query, const std::string& target){
    size_t minLen = std::min(query.length(), target.length());
    size_t commonPrefix = 0;

    for (size_t i = 0; i < minLen; ++i) {
        if (query[i] == target[i]) {
            commonPrefix++;
        } else {
            break;
        }
    }

    // Return a similarity score (normalized to the length of the longer name)
    return static_cast<double>(commonPrefix) / std::max(query.length(), target.length());
}

// Method to get the exact multimedia object by name
std::shared_ptr<Multimedia> MultimediaManager::getMedia(const std::string& objectName){
    auto it = multimediaTable.find(objectName);

    if (it != multimediaTable.end()) {
        // Object found, return it
        return it->second;
    } else {
        // Object not found
        return nullptr;
    }
}

// Method to get the exact group by name
std::shared_ptr<Group> MultimediaManager::getGroup(const std::string& groupName){
    auto it = groupTable.find(groupName);

    if (it != groupTable.end()) {
        // Group found, return it
        return it->second;
    } else {
        // Group not found
        return nullptr;
    }
}
