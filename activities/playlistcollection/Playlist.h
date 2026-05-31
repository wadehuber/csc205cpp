#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Song.h"

// Java: "public interface Playlist extends Iterable<Song>".
// An interface becomes a C++ class made only of pure virtual functions.
//
// Java's "extends Iterable<Song>" means a Playlist can be used in a
// for-each loop. In C++ you would provide begin()/end() in the concrete
// class that implements this interface (see classexamples/module06 for the
// pattern). This activity has no concrete implementation yet, so only the
// interface is defined here.
class Playlist {
public:
    virtual ~Playlist() = default;

    virtual void addSong(Song s) = 0;
    virtual bool isEmpty() = 0;
    virtual int songCount() = 0;
};

#endif
