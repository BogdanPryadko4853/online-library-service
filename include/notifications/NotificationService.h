//#ifndef NOTIFICATIONSERVICE_H
//#define NOTIFICATIONSERVICE_H
//
//#include "NotificationSender.h"
//#include <memory>
//
//class NotificationService {
//protected:
//    std::shared_ptr<NotificationSender> sender;
//
//public:
//    explicit NotificationService(std::shared_ptr<NotificationSender> sender)
//            : sender(sender) {}
//
//    virtual ~NotificationService() = default;
//    virtual void notify(const std::string& message) = 0;
//};
//
//#endif