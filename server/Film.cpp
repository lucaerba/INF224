#include "Film.h"
#include <iostream>

Film::Film() : Video(), chapterDurations(nullptr), numChapters(0) {}

Film::Film(std::string name, std::string filePath, int duration, int* chapterDurations, int numChapters)
    : Video(std::move(name), std::move(filePath), duration), chapterDurations(nullptr), numChapters(0) {
    setChapterDurations(chapterDurations, numChapters);
}
// Copy constructor
Film::Film(const Film& other) : Video(other), chapterDurations(nullptr), numChapters(0) {
    setChapterDurations(other.chapterDurations, other.numChapters);
}
Film::~Film() {
    delete[] chapterDurations;
}

void Film::setChapterDurations(int* chapterDurations, int numChapters) {
    // Clear existing data
    delete[] this->chapterDurations;

    // Allocate memory for the new array
    this->chapterDurations = new int[numChapters];

    // Copy the data
    for (int i = 0; i < numChapters; ++i) {
        this->chapterDurations[i] = chapterDurations[i];
    }

    this->numChapters = numChapters;
}

const int* Film::getChapterDurations() const {
    return chapterDurations;
}

int Film::getNumChapters() const {
    return numChapters;
}

void Film::display(std::ostream& os) const {
    Video::display(os);
    os << "Number of Chapters: " << numChapters << "\n"
       << "Chapter Durations: ";
    
    for (int i = 0; i < numChapters; ++i) {
        os << chapterDurations[i] << " ";
    }
    os << "seconds\n";
}
