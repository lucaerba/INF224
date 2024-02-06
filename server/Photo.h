#ifndef PHOTO_H
#define PHOTO_H

#include "Multimedia.h"

class Photo : public Multimedia {
private:
    double latitude;
    double longitude;

public:
    Photo() : latitude(0.0), longitude(0.0) {}
    Photo(std::string name, std::string filePath, double latitude, double longitude)
        : Multimedia(std::move(name), std::move(filePath)), latitude(latitude), longitude(longitude) {}
    // Copy constructor
    Photo(const Photo& other) : Multimedia(other), latitude(other.latitude), longitude(other.longitude) {}

    double getLatitude() const { return latitude; }
    void setLatitude(double latitude) { this->latitude = latitude; }

    double getLongitude() const { return longitude; }
    void setLongitude(double longitude) { this->longitude = longitude; }

    void display(std::ostream& os) const override {
        Multimedia::display(os);
        os << "Latitude: " << latitude << "\n"
           << "Longitude: " << longitude << "\n";
    }

    void play() const override {
        std::string command = "imagej " + getFilePath() + " &";
        system(command.c_str());
    }

    void serialize(std::ostream& os) const {
        Multimedia::serialize(os);
        os << latitude << " " << longitude << " ";
    }

    void deserialize(std::istream& is) {
        Multimedia::deserialize(is);
        is >> latitude >> longitude;
    }
};

#endif // PHOTO_H
