#ifndef UNFORTUNATEEVENTS_H
#define UNFORTUNATEEVENTS_H

/**
 * UnfortunateEvents class, including a method to sing a long song.
 *
 * This class is intentionally left terrible as an activity.
 *
 * @author Wade Huber
 */
class UnfortunateEvents {
public:
    /** Count down bottles of beer. */
    static void bottlesOfBeer();

private:
    /** Helper method for bottlesOfBeer. */
    static void countThemDown(int n);
};

#endif
