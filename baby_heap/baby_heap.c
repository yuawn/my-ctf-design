#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


struct profile{
    int is_valid;
    char *password;
    char account[16];
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
            printf( "Account: " );
            read( 0 , n[i].account , 20 );
            read( 0 , buf , 0x100 );
            n[i].password = strdup( buf );
            puts( "done!" );
            return;
        }
    }
    puts("Only two page!");
    return ;
}

void change_password(){
    printf("Index:");
    
    puts("Done!");
    return ;
}

void show(){
    printf("Index:");
    return ;
}

void delete_user(){

}


void menu(){
    puts("----------------");
    puts("1. create an user ");
    puts("2. change password ");
    puts("3. show user list ");
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
                add_user();
                break;
            case 2:
                change_password();
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