#include <stdio.h>
#include <unistd.h>

int main(){
    printf("sleeping for 3 second\n");
    // sleep(3);        sleep for 3 seconds
    sleep(0.30);         //sleep for 30 microseconds
    return 0;
}

// sleep - wait for a current thread for a specified time