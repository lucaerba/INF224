/**
 * @file Video.h
 * @brief This file contains the Video class.
 */

#ifndef VIDEO_H
#define VIDEO_H

#include "Multimedia.h"

/**
 * @class Video
 * @brief This class represents a video.
 * 
 * It inherits from the Multimedia class and adds a duration attribute.
 */
class Video : public Multimedia {
private:
    int duration; ///< The duration of the video in seconds.

public:
    /**
     * @brief Default constructor.
     * 
     * Initializes the duration to 0.
     */
    Video() : duration(0) {}

    /**
     * @brief Parameterized constructor.
     * 
     * @param name The name of the video.
     * @param filePath The file path of the video.
     * @param duration The duration of the video.
     */
    Video(std::string name, std::string filePath, int duration)
        : Multimedia(std::move(name), std::move(filePath)), duration(duration) {}

    /**
     * @brief Copy constructor.
     * 
     * @param other The other video to copy from.
     */
    Video(const Video& other) : Multimedia(other), duration(other.duration) {}

    /**
     * @brief Get the duration of the video.
     * 
     * @return int The duration of the video.
     */
    int getDuration() const { return duration; }

    /**
     * @brief Set the duration of the video.
     * 
     * @param duration The new duration of the video.
     */
    void setDuration(int duration) { this->duration = duration; }

    /**
     * @brief Display the video information.
     * 
     * @param os The output stream to display the information to.
     */
    void display(std::ostream& os) const override {
        Multimedia::display(os);
        os << "Duration: " << duration << " seconds\n";
    }

    /**
     * @brief Play the video.
     */
    void play() const override {
        std::string command = "mpv " + getFilePath() + " &";
        system(command.c_str());
    }

    /**
     * @brief Serialize the video information.
     * 
     * @param os The output stream to serialize the information to.
     */
    void serialize(std::ostream& os) const override{
        Multimedia::serialize(os);
        os << duration;
    }

    /**
     * @brief Deserialize the video information.
     * 
     * @param is The input stream to deserialize the information from.
     */
    void deserialize(std::istream& is) override{
        Multimedia::deserialize(is);
        is >> duration;
    }
};
#endif // VIDEO_H