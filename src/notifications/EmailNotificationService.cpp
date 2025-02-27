#ifndef EMAILNOTIFICATIONSERVICE_H
#define EMAILNOTIFICATIONSERVICE_H

#include "../../include/notifications/NotificationService.h"
#include "../../include/notifications/EmailSender.h"

class EmailNotificationService : public NotificationService {
public:
    EmailNotificationService()
            : NotificationService(std::make_shared<EmailSender>()) {}

    void notify(const std::string& message) override {
        sender->send(message);
    }
};

#endif