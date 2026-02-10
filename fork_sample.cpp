#include <sys/types.h>
#include <iostream>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        std::cerr << "Fork Failed" << std::endl;
        return 1;
    }
    else if (pid == 0) { // Child process
        std::cout << "Child's Parent PID (before): " << getppid() << std::endl;
        sleep(15); // Child keeps running
        std::cout << "Child's Parent PID (after): " << getppid() << std::endl;
    }
    else { // Parent process
        sleep(5); // Parent exits first
        std::cout << "Parent PID: " << getpid() << std::endl;
    }

    return 0;
}

