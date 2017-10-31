#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>




char *n[10];

int read_int(){
    char buf[16];
    if( __read_chk(0,buf,15,15) <= 0 ){
        puts("read error");
        exit(1);
    }
    return (unsigned int)atoi(buf);
} 	


void add(){
    for( int i = 0 ; i < 10 ; ++i ){
        if( !n[i] ){
            puts( "0. small chunk 1. large chunk (0/1):" );
            unsigned cho = read_int();
            if( cho > 1 ) {
                puts("Nop!");
                exit(0);
            }

            if( !cho ){
                n[i] = (char*)malloc( 0x20 );
                if( !n[i] ){
                    puts( "Alloc error!" );
                    exit(0);
                }
                printf( "Leave something in the chunk:" );
                read( 0 , n[i] , 0x20 );
                puts("done!");
                return;
            }
            else{
                n[i] = (char*)malloc( 0x500 );
                if( !n[i] ){
                    puts( "Alloc error!" );
                    exit(0);
                }
                printf( "Leave something in the chunk:" );
                read( 0 , n[i] , 0x500 );
                puts("done!");
                return;
            }
            
        }
    }
    puts("Full!");
    return ;
}

void edit(){
    printf("Index:");
    unsigned i = read_int();
    if( i > 9 ) {
        puts("Nop!");
        exit(0);
    }

    char buf[0x600];
    memset( buf , 0 , 0x600 );
    if( n[i] ){
        printf( "New data:" );
        read( 0 , buf , strlen( n[i] ) );
        char *tmp = realloc( n[i] , strlen( buf ) );
        if( !tmp ){
            puts("Alloc error!");
            return;
        }
        strcpy( n[i] , buf , strlen( buf ) );
        puts( "done!" );
        return;
    }
    
    puts("No such chunk!");
    return ;
}


void show(){
    printf("Index:");
    unsigned i = read_int();
    if( i > 9 ) {
        puts("Nop!");
        exit(0);
    }


    if( n[i] ) printf( "%s\n" , n[i] );
    else puts("No such chunk!");

    return ;
}


void menu(){
    puts("----------------");
    puts("1. add a chunk ");
    puts("2. edit a chunk ");
    puts("3. show a chunk ");
    puts("4. exit");
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
                add();
                break;
            case 2:
                edit();
                break;
            case 3:
                show();
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