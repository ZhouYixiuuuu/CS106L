#include <set>
#include <string>

class User {
public:
    // TODO: write special member functions, including default constructor!
    User();
    ~User();
    User(const User & user);
    User& operator = (const User & user);
    User(User && user);
    User& operator = (User && user);

    User(std::string name);

    // getter functions
    std::string getName() const;
    std::set<User> getFriends() const;

    // setter functions
    void setName(std::string name);
    friend User && operator + (User & A, User & B);
    // TODO: add the < operator overload here!
    bool operator < (const User & A) const;
    
private:
    std::string name;
    std::set<User> friends;
};
