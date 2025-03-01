//#ifndef NOTIFICATIONOBSERVER_H
//#define NOTIFICATIONOBSERVER_H
//
//#include "../../include/observer/Observer.h"
//#include "../../include/notifications/NotificationService.h"
//
//class NotificationObserver : public Observer {
//private:
//    std::shared_ptr<NotificationService> service;
//
//public:
//    explicit NotificationObserver(std::shared_ptr<NotificationService> service)
//            : service(service) {}
//
//    void update(const std::string &message) override {
//        service->notify(message);
//    }
//};
//
//#endif