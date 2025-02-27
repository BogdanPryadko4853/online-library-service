#ifndef EMAILSENDER_H
#define EMAILSENDER_H

#include "../../include/notifications/NotificationSender.h"
#include <iostream>

class EmailSender : public NotificationSender {
public:
    void send(const std::string& message) override {
        std::cout << "[EMAIL] Sending email: " << message << std::endl;
        // Реальная логика отправки через SMTP
    }
};

#endif