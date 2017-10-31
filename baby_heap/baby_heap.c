#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


struct profile{
    int is_valid , size;
    char *password;
    char username[16];
};


struct profile n[10];

int read_int(){
    char buf[16];
    if( __read_chk(0,buf,15,15) <= 0 ){
        puts("read error");
        exit(1);
    }
    return (unsigned int)atoi(buf);
} 	


void add_user(){
    char buf[0x100];
    int len;
    for( int i = 0 ; i < 10 ; ++i ){
        if( !n[i].is_valid ){
            printf( "Username: " );
            //read( 0 , n[i].username , 16 );
            len = __read_chk( 0 , n[i].username , 16 , 16 );
            if( n[i].username[len - 1] == '\n' ) n[i].username[len - 1] = '\x00';
            n[i].size = len;
            printf( "Password: " );
            //read( 0 , buf , 0x100 - 1 );
            len = __read_chk( 0 , buf , 0x100 - 1 , 0x100 );
            buf[len - 1] = '\x00';
            n[i].password = strdup( buf );
            if( !n[i].password ){
                puts("Alloc error!");
                exit(0);
            }
            n[i].is_valid = 1;
            puts( "done!" );
            return;
        }
    }
    puts("Only two page!");
    return ;
}

void edit_user(){
    printf("Index:");
    unsigned i = read_int();
    if( i > 9 ) {
        puts("Nop!");
        exit(0);
    }

    if( n[i].is_valid ){
        printf( "New username:" );
        //read( 0 , n[i].username , n[i].size );
        int len = __read_chk( 0 , n[i].username , n[i].size , n[i].size );
        if( n[i].username[len - 1] == '\n' ) n[i].username[len - 1] = '\x00';
        n[i].size = strlen( n[i].username );
        printf( "New password:" );
        //read( 0 , n[i].password , strlen( n[i].password ) );
        len = __read_chk( 0 , n[i].password , strlen( n[i].password ) , strlen( n[i].password ) );
        n[i].password[ len ] = '\x00';
        puts( "done!" );
        return;
    }
    
    puts("No such user!");
    return ;
}


void show(){
    for( int i = 0 ; i < 10 ; ++i ){
        if( n[i].is_valid ){
            printf( "User %d: username: %s password: %s\n" , i ,  n[i].username , n[i].password );
        }
    }
    return ;
}

void delete_user(){
    printf("Index:");
    unsigned i = read_int();
    if( i > 9 ) {
        puts("Nop!");
        exit(0);
    }
    if( n[i].is_valid ){
        memset( n[i].username , 0 , 0x10 );
        free( n[i].password );
        n[i].is_valid = 0;
        puts("done!");
        return;
    }
    puts("No such user!");
    return;
}


void menu(){
    puts("----------------");
    puts("1. create an user ");
    puts("2. edit an user ");
    puts("3. show user list ");
    puts("4. remove an user ");
    puts("5. exit");
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
                add_user();
                break;
            case 2:
                edit_user();
                break;
            case 3:
                show();
                break;
            case 4:
                delete_user();
                break;
            case 5:
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