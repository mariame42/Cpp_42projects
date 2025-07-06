#include <iostream> 
#include <cctype>

int main(int ac, char **av) {
    if (ac == 1)
    {
        std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        return 0;
    }
    int j = 1;
    while (av[j])
    {
        std::string firstarg = av[j];
        int i = 0;
        while (firstarg[i])
        {
            std::cout<<(char)toupper(firstarg[i]);
            i++;
        }
        j++;
    }
    return 0;
}