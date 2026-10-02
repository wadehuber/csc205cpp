#ifndef EMAILNOTIFICATION_H
#define EMAILNOTIFICATION_H

#include "Notification.h"

class EmailNotification : public Notification
{
private:
    string subject;

public:
    EmailNotification(string recipient, string subject)
        : Notification(recipient)
    {
        this->subject = subject;
    }

    void send() const override
    {
        cout << "Sending email to " << getRecipient() << endl;
        cout << "Subject: " << subject << endl;
    }
};

#endif
