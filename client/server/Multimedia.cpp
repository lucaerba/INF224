// Multimedia.cpp

#include "Multimedia.h"

Multimedia::Multimedia() : name(""), filePath("") {}

Multimedia::Multimedia(std::string name, std::string filePath)
    : name(std::move(name)), filePath(std::move(filePath)) {}

Multimedia::Multimedia(const Multimedia& other) : name(other.name), filePath(other.filePath) {}

Multimedia::~Multimedia() {
    std::cout << "Destroying Multimedia: " << name << "\n";
    // Cleanup, if needed
}

std::string Multimedia::getName() const {
    return name;
}

void Multimedia::setName(std::string name) {
    this->name = std::move(name);
}

std::string Multimedia::getFilePath() const {
    return filePath;
}

void Multimedia::setFilePath(std::string filePath) {
    this->filePath = std::move(filePath);
}

void Multimedia::display(std::ostream& os) const {
    os << "Name: " << name << "\n"
       << "File Path: " << filePath << "\n";
}

void Multimedia::serialize(std::ostream& os) const {
    os << name << " " << filePath << " ";
}

void Multimedia::deserialize(std::istream& is) {
    is >> name >> filePath;
}

std::ostream& operator<<(std::ostream& os, const Multimedia& obj) {
    obj.serialize(os);
    return os;
}

std::istream& operator>>(std::istream& is, Multimedia& obj) {
    obj.deserialize(is);
    return is;
}
