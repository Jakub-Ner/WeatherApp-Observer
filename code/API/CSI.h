#ifndef WEATHERAPP_CSI_H
#define WEATHERAPP_CSI_H

#include "../locations/Location.h"
#include "../User.h"
#include <vector>

class CSI {
    std::vector<User*> m_user_list;
    std::vector<Location *> m_location_list;
    std::vector<std::string> m_location_list_for_others;
public:
    CSI();

    ~CSI();
    bool add_user_to_location(User* user, std::string& wanted_location);
    User *const log_in(const std::string &username);

    User *const add_user(std::string username);

    const std::vector<std::string>& get_location_list();

    bool remove_user_from_location(User *user, std::string basicString);

private:
};
#endif //WEATHERAPP_CSI_H
