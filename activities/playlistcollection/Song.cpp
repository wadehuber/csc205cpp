#include "Song.h"

Song::Song(std::string title, std::string artist, int duration) {
    this->title = title;
    this->artist = artist;
    this->duration = duration;
}

std::string Song::getTitle() const {
    return title;
}

std::string Song::getArtist() const {
    return artist;
}

int Song::getDuration() const {
    return duration;
}

std::string Song::toString() const {
    return title + " by " + artist + ", duration=" + std::to_string(duration) + "sec";
}
