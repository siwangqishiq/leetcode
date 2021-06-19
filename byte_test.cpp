#include <stdio.h>

union sn{
    short sd;
    char data[sizeof(sd)];
};

int main(){
    printf("short size = %d \n" , sizeof(short));
    union sn dump;
    dump.sd = 0x0102;

    char b1 = dump.data[0];
    char b2 = dump.data[1];

    printf("b1 = %d , b2 = %d \n" , b1 , b2);

    if(b1 == 1 && b2 == 2){
        printf("small edian \n");
    }else if(b1 == 2 && b2 == 1){
        printf("big edian \n");
    }else{
        printf("unknow \n");
    }
    return 0;
}