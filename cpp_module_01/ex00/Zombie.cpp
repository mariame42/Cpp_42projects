// Zombie* zombieHorde( int N, std::string name );
// It must allocate N Zombie objects in a single allocation. Then, it must initialize the
// zombies, giving each of them the name passed as a parameter. The function returns a
// pointer to the first zombie.
// Implement your own tests to ensure that your zombieHorde() function works as expected. Try calling announce() for each of the zombies.
// Do not forget to use delete to deallocate all the zombies and check for memory
// leaks.

#include "Zombie.hpp"

Zombie::Zombie() {
    this->name = "unnamed";
}

Zombie::Zombie(std::string name) {
    this->name = name;
}

Zombie::~Zombie() {
    std::cout<< this->name << " is destroyed" << std::endl;
}

void Zombie::announce(void) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
    this->name = name;
}

Zombie* zombieHorde(int N, std::string name )
{
    Zombie *zombiehorde = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        zombiehorde[i].setName(name);
    }
    return (zombiehorde);
}

int main()
{
    Zombie *zombiehorde = zombieHorde(5, "zombie");
    for (int i = 0; i < 5; i++)
    {
        zombiehorde[i].announce();
    }
    delete[] zombiehorde;
}
