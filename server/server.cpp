//
//  server.cpp
//  TP C++
//  Eric Lecolinet - Telecom ParisTech - 2016.
//

#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"
#include "MultimediaManager.h"

const int PORT = 3331;

int main(int argc, char *argv[])
{
	MultimediaManager manager;
	auto p1 = manager.createPhoto("firma", "./media/firma.png", 0.0, 0.0);
	auto p2 = manager.createPhoto("immagine", "./media/Immagine.png", 0.0, 0.0);
	auto p3 = manager.createPhoto("me", "./media/me_strafigo.png", 0.0, 0.0);
	auto v1 = manager.createVideo("follow", "./media/followmypompa.mp4", 72);
	auto f1 = manager.createFilm("tamagotchi", "./media/tamagotchi.mp4", 298, new int[3]{60, 120, 200}, 3);
	// Inside the lambda function in TCPServer constructor
	auto *server =
		new TCPServer([&](std::string const &request, std::string &response)
					  {
			std::stringstream ss(request);
			std::string command;
			ss >> command;

			if (command == "SEARCHMEDIA") {
				// Extract the object name from the command and perform display
				std::string objectName;
				ss >> objectName;
				std::ostringstream displayStream;
				manager.searchMedias(objectName, displayStream);
				manager.searchMedias(objectName, std::cout);
				// Set response based on the display result
				response = "SEARCH_RESULT: " + displayStream.str();

			} else if(command == "SEARCHGROUP"){
				std::string groupName;
				ss >> groupName;
				std::ostringstream displayStream;
				manager.searchGroups(groupName, displayStream);
				// Print the search result to the display stream
				manager.searchGroups(groupName, displayStream);
				response = "SEARCH_RESULT: " + displayStream.str();

			} else if (command == "CREATEPHOTO") {
				// Extract the object name from the command and perform display
				std::string objectName;
				std::string filePath;
				double latitude;
				double longitude;
				ss >> objectName >> filePath >> latitude >> longitude;
				std::ostringstream displayStream;
				auto photo = manager.createPhoto(objectName, filePath, latitude, longitude);
				photo->serialize(displayStream);
				// Set response based on the display result
				response = "CREATE_RESULT: " + displayStream.str();

			} else if (command == "CREATEVIDEO") {
				// Extract the object name from the command and perform display
				std::string objectName;
				std::string filePath;
				int duration;
				ss >> objectName >> filePath >> duration;
				std::ostringstream displayStream;
				auto video = manager.createVideo(objectName, filePath, duration);
				video->serialize(displayStream);
				// Set response based on the display result
				response = "CREATE_RESULT: " + displayStream.str();

			} else if (command == "CREATEFILM") {
				// Extract the object name from the command and perform display
				std::string objectName;
				std::string filePath;
				int duration;
				int numChapters;
				ss >> objectName >> filePath >> duration >> numChapters;
				int *chapterDurations = new int[numChapters];
				for (int i = 0; i < numChapters; i++) {
					ss >> chapterDurations[i];
				}
				std::ostringstream displayStream;
				auto film = manager.createFilm(objectName, filePath, duration, chapterDurations, numChapters);
				film->serialize(displayStream);
				// Set response based on the display result
				response = "CREATE_RESULT: " + displayStream.str();

			} else if (command == "CREATEGROUP") {
				// Extract the object name from the command and perform display
				std::string objectName;
				ss >> objectName;
				std::ostringstream displayStream;
				auto group = manager.createGroup(objectName);
				//group->serialize(displayStream);	
				// Set response based on the display result
				response = "CREATE_RESULT: " + displayStream.str();

			} else if (command == "DISPLAY") {
				// Extract the object name from the command and perform display
				std::string objectName;
				ss >> objectName;
				std::ostringstream displayStream;
				auto media = manager.getMedia(objectName);
				media->display(std::cout);
				media->serialize(displayStream);
				// Set response based on the display result
				response = "DISPLAY_RESULT: " + displayStream.str();

			} else if (command == "PLAY") {
				// Extract the object name from the command and perform play
				std::string objectName;
				ss >> objectName;
				// Perform play logic here
				manager.playObject(objectName);
				// Set response based on the play result
				response = "PLAY_RESULT: " + objectName;

			} else {
				// Invalid command
				response = "ERROR: Invalid command";
			}

			return true; });

	// lance la boucle infinie du serveur
	std::cout << "Starting Server on port " << PORT << std::endl;

	int status = server->run(PORT);

	// en cas d'erreur
	if (status < 0)
	{
		std::cerr << "Could not start Server on port " << PORT << std::endl;
		return 1;
	}

	return 0;
}
