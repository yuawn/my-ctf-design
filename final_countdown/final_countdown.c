#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void read_input( char *p , unsigned int len ){
    int size = __read_chk( 0 , p , len , len );
    if( size <= 0 ){
        puts( "read error!" );
        exit(0);
    }
    p[size - 1] = p[size - 1] == '\n' ? '\x00' : p[size - 1];
}

char echo[0x18];

int main(){
    setvbuf(stdin ,0,_IONBF,0);
	setvbuf(stdout,0,_IONBF,0);
	setvbuf(stderr,0,_IONBF,0);

    for( int i = 3 ; i > -1 ; --i ){
        printf( "tick tock .. What do tou want to say:" );
        read_input( echo , 0x18 );
        printf(echo);
        puts("");
        close(i);
    }

    return 0;
}