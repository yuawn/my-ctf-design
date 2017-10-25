#include <stdio.h>
#include <unistd.h>


int main(){
    
    char joke[16];
    read( 0 , joke  , 200 );
    close(0);
    close(1);
    close(2);

    return 0;
}