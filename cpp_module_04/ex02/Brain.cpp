#include "Brain.hpp"
#include <sstream>

static std::string create_idea(std::string type, int idea_num)
{
    std::stringstream ss;
    ss << idea_num;
    return(type + " " + ss.str());
}

Brain::Brain()
{
    int i = 0;
    while(i < 100)
    {
        _ideas[i] = create_idea("generic animal", i + 1);
        i++;  // Add this line!
    }
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(std::string type)
{
    int i = 0;
    while(i < 100)
    {
        _ideas[i] = create_idea(type, i + 1);
        i++;  // Add this line!
    }
    std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return _ideas[index];
    return "Invalid index";
}