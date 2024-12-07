
#pragma once

#include <iostream>

class Warlock
{
private:
    std::string name;
    std::string title;

public:
    Warlock(std::string const &name, std::string const &title);
    ~Warlock();

    void    setTitle(std::string const &title);
    std::string getName() const;
    std::string getTitle() const;

    void introduce() const;
};
