/**
 * @file Film.h
 * @brief This file contains the Film class.
 */

#ifndef FILM_H
#define FILM_H

#include "Video.h"

/**
 * @class Film
 * @brief This class represents a film.
 * 
 * It inherits from the Video class and adds a number of chapters and their durations.
 */
class Film : public Video {
private:
    int numChapters; ///< Number of chapters

public:
    /**
     * @brief Default constructor.
     * 
     * Initializes the number of chapters to 0.
     */
    Film();

    /**
     * @brief Parameterized constructor.
     * 
     * @param name The name of the film.
     * @param filePath The file path of the film.
     * @param duration The duration of the film.
     * @param chapterDurations The durations of the chapters.
     * @param numChapters The number of chapters.
     */
    Film(std::string name, std::string filePath, int duration, int* chapterDurations, int numChapters);

    /**
     * @brief Copy constructor.
     * 
     * @param other The other film to copy from.
     */
    Film(const Film& other);

    /**
     * @brief Destructor.
     */
    ~Film();

    /**
     * @brief Set the chapter durations.
     * 
     * @param chapterDurations The new chapter durations.
     * @param numChapters The new number of chapters.
     */
    void setChapterDurations(int* chapterDurations, int numChapters);

    /**
     * @brief Get the chapter durations.
     * 
     * @return const int* The chapter durations.
     */
    const int* getChapterDurations() const;

    /**
     * @brief Get the number of chapters.
     * 
     * @return int The number of chapters.
     */
    int getNumChapters() const;

    /**
     * @brief Display the film information.
     * 
     * @param os The output stream to display the information to.
     */
    void display(std::ostream& os) const override;
};

#endif // FILM_H