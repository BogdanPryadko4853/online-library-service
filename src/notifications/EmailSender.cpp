//#include "../../include/notifications/EmailSender.h"
//#include <iostream>
//#include <sstream>
//
//bool EmailSender::sendEmail(const std::string& to, const std::string& subject, const std::string& body) {
//    CURL* curl;
//    CURLcode res = CURLE_OK;
//
//    curl = curl_easy_init();
//    if (curl) {
//        struct curl_slist* recipients = nullptr;
//        std::stringstream payloadText;
//        payloadText << "To: " << to << "\r\n"
//                    << "From: " << smtpUser << "\r\n"
//                    << "Subject: " << subject << "\r\n"
//                    << "\r\n"
//                    << body << "\r\n";
//
//        std::string payload = payloadText.str();
//
//        curl_easy_setopt(curl, CURLOPT_URL, smtpServer.c_str());
//        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, smtpUser.c_str());
//
//        recipients = curl_slist_append(recipients, to.c_str());
//        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
//
//        curl_easy_setopt(curl, CURLOPT_READFUNCTION, payloadSource);
//        curl_easy_setopt(curl, CURLOPT_READDATA, &payload);
//        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
//
//        curl_easy_setopt(curl, CURLOPT_USERNAME, smtpUser.c_str());
//        curl_easy_setopt(curl, CURLOPT_PASSWORD, smtpPassword.c_str());
//
//        curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);
//
//        res = curl_easy_perform(curl);
//
//        if (res != CURLE_OK) {
//            std::cerr << "Failed to send email: " << curl_easy_strerror(res) << std::endl;
//        }
//
//        curl_slist_free_all(recipients);
//        curl_easy_cleanup(curl);
//    }
//
//    return res == CURLE_OK;
//}
//
//size_t EmailSender::payloadSource(void* ptr, size_t size, size_t nmemb, void* userp) {
//    std::string* payload = static_cast<std::string*>(userp);
//    size_t bufferSize = size * nmemb;
//
//    if (payload->empty()) {
//        return 0;
//    }
//
//    memcpy(ptr, payload->c_str(), payload->size());
//    payload->clear();
//
//    return payload->size();
//}