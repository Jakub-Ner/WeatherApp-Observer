#ifndef WEATHERAPP_CS_H
#define WEATHERAPP_CS_H

#include "../locations/Location.h"
#include "../User.h"
#include <vector>
#include <mutex>
#include <thread>

class CS {
    std::vector<User *> m_user_list;
    std::vector<Location *> m_location_list;
    std::vector<std::string> m_location_list_for_others;
    std::mutex m_synchronize_list;
public:
    CS();

    ~CS();

    void run();

    User *const log_in(const std::string &username);

    User *const add_user_and_give_him_location_list(std::string &username);

    bool add_user_to_location(User *user, std::string &wanted_location);

    bool remove_user_from_location(User *user, std::string &unsub_location);

};

#endif //WEATHERAPP_CS_H
