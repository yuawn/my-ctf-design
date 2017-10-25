#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


struct note{
    int size;
    char *content;
};

char *name , *messege;

struct note *n[3];

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
    for( int i = 0 ; i < 3 ; ++i ){
        if( !n[i] ){
            n[i] = (struct note*)malloc( sizeof( struct note ) );
            printf("Size of note:");
            read( 0 , buf , 8 );
            len = atoi( buf );
            n[i]->size = len;
            printf("Content of note:");
            n[i]->content = (char*)malloc( len );
            if( !n[i]->content ){
                puts("Alloc error!");
                exit(0);
            }
            read( 0 , n[i]->content , len );
            puts("Done!");
            return;
        }
    }
    puts("Only two page!");
    return ;
}

void edit_note(){
    printf("Index:");
    unsigned i = read_int();
    if( i > 2 ) {
        puts("Nop!");
        exit(0);
    }
    if( !n[i] ){
        puts("No such note!");
        exit(0);
    }
    //printf("New size of note:");
    //int len = read_int();
    printf("New content of note:");
    //n[i]->size = len;
    read( 0 , n[i]->content , n[i]->size );
    
    puts("Done!");
    return ;
}

void show_note(){
    printf("Index:");
    unsigned i = read_int();
    if( i > 2 ) {
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

void add_name(){
    if( name ) {
        puts( "I already know your name!" );
        return;
    }
    name = (char *)malloc( 0x10 );
    puts("What's your name?");
    read( 0 , name , 0x20 );
    puts("Done!");
    return;
}

void leave_messege(){
    if( messege ) {
        puts( "I already heard your messege!" );
        return;
    }
    messege = (char *)malloc( 0x100 );
    puts("Messege:");
    read( 0 , messege , 0x100 );
    puts("Done!");
    return;
}


void menu(){
    puts("----------------");
    puts("1. add a note");
    puts("2. edit a note");
    puts("3. show a note");
    puts("4. What's your name?");
    puts("5. Leave messege for me");
    puts("6. exit");
    puts("----------------");
    puts("Your choice:");
}

int main(){
    setvbuf(stdin,0,2,0);
	setvbuf(stdout,0,2,0);
    setvbuf(stderr,0,2,0);
    
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
                add_name();
                break;
            case 5:
                leave_messege();
                break;
            case 6:
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