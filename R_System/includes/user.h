#ifndef USER_H_
#define USER_H_

#include <string>

class User {
 
 public: 
  // Constructor!
  User(int perm, std::string name, std::string genre1, std::string genre2) :
    perm(perm), name(name), genre1(genre1), genre2(genre2) {}

  int get_perm() { return perm; }
  std::string get_name() { return name; }
  std::string get_first_genre() { return genre1; }
  std::string get_second_genre() { return genre2; }

 private:
  int perm;
  std::string name;
  std::string genre1;
  std::string genre2;
};

#endif // USER_H_