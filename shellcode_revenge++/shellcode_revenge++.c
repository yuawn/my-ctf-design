#include<stdio.h>
#include<stdlib.h>

int len;
char name[100];

void check( len ){
    if( name[len - 1] == '\n' ) name[len - 1] = '\x00';
    for( int i = 0 ; i < len - 1 ; i++ ){
        if( ( name[i] < '/' || name[i] > '9' ) && ( name[i] < 'a' || name[i] > 'z' ) && ( name[i] < 'A' || name[i] > 'Z' ) &&  ( name[i] < ';' || name[i] > '>' ) && name[i] != '^' && name[i] != '_' && name[i] != '\\' ) {
            puts( "Your name contains unprintable characters!, are you hacker? GO AWAY!!!!!" );
            exit(0);
        }
    }
}

int main(){
    setvbuf(stdout,0,2,0);
    puts( "Name always contain printable characters, isn't it?" );
    puts( "What's your name, ONLY contains [ 'a'~'z' 'A'~'Z' '0'~'9' ':' '>' '=' '<' '^' '/' '\\' '_'  ]:");

    len = __read_chk( 0 , name , 97 , 100 );
    if( len <= 0 ){
        puts("read error");
        _exit(1);
    }

    check( len );

    printf( "Hello %s! Leave some messege for me!" , name );
    char buf[0x10];
    read( 0 , buf , 0x20 );

    printf( "You said: %s" , buf );

    return 0;
}