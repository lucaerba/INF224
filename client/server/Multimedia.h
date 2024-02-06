/**
 * @file Multimedia.h
 * @brief This file contains the Multimedia class.
 */

#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <iostream>

/**
 * @class Multimedia
 * @brief This class represents a multimedia object.
 * 
 * It contains a name and a file path, and provides methods for displaying and playing the object.
 */
class Multimedia {
private:
    std::string name; ///< The name of the multimedia object.
    std::string filePath; ///< The file path of the multimedia object.

public:
    /**
     * @brief Default constructor.
     */
    Multimedia();

    /**
     * @brief Parameterized constructor.
     * 
     * @param name The name of the multimedia object.
     * @param filePath The file path of the multimedia object.
     */
    Multimedia(std::string name, std::string filePath);

    /**
     * @brief Copy constructor.
     * 
     * @param other The other multimedia object to copy from.
     */
    Multimedia(const Multimedia& other);

    /**
     * @brief Destructor.
     */
    virtual ~Multimedia();

    /**
     * @brief Get the name of the multimedia object.
     * 
     * @return std::string The name of the multimedia object.
     */
    std::string getName() const;

    /**
     * @brief Set the name of the multimedia object.
     * 
     * @param name The new name of the multimedia object.
     */
    void setName(std::string name);

    /**
     * @brief Get the file path of the multimedia object.
     * 
     * @return std::string The file path of the multimedia object.
     */
    std::string getFilePath() const;

    /**
     * @brief Set the file path of the multimedia object.
     * 
     * @param filePath The new file path of the multimedia object.
     */
    void setFilePath(std::string filePath);

    /**
     * @brief Display the multimedia object.
     * 
     * @param os The output stream to display the information to.
     */
    virtual void display(std::ostream& os) const;

    /**
     * @brief Play the multimedia object.
     * 
     * This is a pure virtual function that must be implemented by derived classes.
     */
    virtual void play() const = 0;

    /**
     * @brief Serialize the multimedia object.
     * 
     * @param os The output stream to serialize the information to.
     */
    virtual void serialize(std::ostream& os) const;

    /**
     * @brief Deserialize the multimedia object.
     * 
     * @param is The input stream to deserialize the information from.
     */
    virtual void deserialize(std::istream& is);

    /**
     * @brief Output stream operator overload.
     * 
     * @param os The output stream.
     * @param obj The multimedia object to output.
     * @return std::ostream& The output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Multimedia& obj);

    /**
     * @brief Input stream operator overload.
     * 
     * @param is The input stream.
     * @param obj The multimedia object to input.
     * @return std::istream& The input stream.
     */
    friend std::istream& operator>>(std::istream& is, Multimedia& obj);
};

#endif // MULTIMEDIA_H