#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


struct note{
    int size;
    char *content;
};

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
    int len;
    for( int i = 0 ; i < 2 ; ++i ){
        if( !n[i] ){
            n[i] = (struct note*)malloc( sizeof( struct note ) );
            printf("Size of note:");
            read( 0 , buf , 8 );
            len = atoi( buf );
            n[i]->size = len;
            printf("Content of note:");
            n[i]->content = (char*)malloc( len );
            read( 0 , n[i]->content , len );
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
    if( !n[i] ){
        puts("No such note!");
        exit(0);
    }
    printf("New size of note:");
    int len = read_int();
    printf("New content of note:");
    n[i]->size = len;
    read( 0 , n[i]->content , len );
    
    puts("Done!");
    return ;
}

void show_note(){
    unsigned i = read_int();
    if( i > 1 ) {
        puts("Nop!");
        exit(0);
    }
    if( !n[i] ){
        puts("No such note!");
        exit(0);
    }
    printf("note[%d]: %s\n" , i , n[i]->content);
    return ;
}

void menu(){
    puts("----------------");
    puts("1. add a note");
    puts("2. edit a note");
    puts("3. show a note");
    puts("4. exit");
    puts("----------------");
    puts("Your choice:");
}

int main(){
    setvbuf(stdin,0,2,0);
	setvbuf(stdout,0,2,0);
    setvbuf(stderr,0,2,0);
    
    puts( "What your name?" );
    read( 0 , name , 8 );

    while(1){
        menu();
        switch( read_int() ){
            case 1:
                add_note();
                break;
            case 2:
                edit_note();
                break;
            case 3:
                show_note();
                break;
            case 4:
                printf("Bye!\n");
                _exit(0);
                break;
            default:
                puts("Invalid choice!");
                break;
        }  
    }

    return 0;
}