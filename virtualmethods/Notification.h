#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <iostream>
#include <string>
using namespace std;

class Notification
{
private:
    string recipient;

public:
    Notification(string recipient)
    {
        this->recipient = recipient;
    }

    string getRecipient() const
    {
        return recipient;
    }

    virtual void describe() const
    {
        cout << "Notification for " << recipient << endl;
    }

    virtual void send() const = 0;

    virtual ~Notification() = default;
};

#endif
