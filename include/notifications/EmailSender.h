//#ifndef EMAILSENDER_H
//#define EMAILSENDER_H
//
//#include <string>
//#include <include/curl/curl.h>
//
//class EmailSender {
//public:
//    EmailSender(const std::string& smtpServer, const std::string& smtpUser, const std::string& smtpPassword)
//            : smtpServer(smtpServer), smtpUser(smtpUser), smtpPassword(smtpPassword) {}
//
//    bool sendEmail(const std::string& to, const std::string& subject, const std::string& body);
//
//private:
//    std::string smtpServer;
//    std::string smtpUser;
//    std::string smtpPassword;
//
//    static size_t payloadSource(void* ptr, size_t size, size_t nmemb, void* userp);
//};
//
//#endif