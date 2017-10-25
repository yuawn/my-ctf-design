#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


struct note{
    int size;
    char *content;
}

char name[8];

struct note *n[2];

int read_int(){
    char buf[16];
    if( __read_chk(0,buf,15,15) <= 0 ){
        puts("read error");
        exit(1);
    }
    return (unsigned int)atoi(buf);
} 	


void add_note(){
    char buf[8];
    for( int i = 0 ; i < 2 ; ++i ){
        if( !n[i] ){
            n[i] = (struct note*)malloc( sizeof( struct note ) );
            printf("Size of note:");
            read( 0 , buf , 8 );
            n[i].size = atoi( buf );
            printf("Content of note:");
            n[i].content = malloc( n[i].size )
            read( 0 , n[i].content , n[i].size );
            puts("Done!");
            return;
        }
    }
    puts("Only two page!");
    return ;
}

void edit_note(){
    unsigned i = read_int();
    if( i > 1 ) {
        puts("Nop!");
        exit(0);
    }
    printf("New content of note:");
    read( 0 , n[i].content , n[i].size );
    
    puts("Done!");
    return ;
}

int main(){
    setvbuf(stdin,0,2,0);
	setvbuf(stdout,0,2,0);
    setvbuf(stderr,0,2,0);
    
    puts( "What your name?" );
    read( 0 , name , 8 );

    switch( read_int() ){
        case 1:
            add_note();
            break;
        case 2:
            edit_note();
            break;
        case 3:
            printf("Bye!\n");
            _exit(0);
            break;
        default:
            puts("Invalid choice!");
            break;
    }  

    return 0;
}