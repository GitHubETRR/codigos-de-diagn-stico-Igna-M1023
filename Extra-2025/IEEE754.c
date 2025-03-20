#include <stdio.h>

union FloatBytes {
    float value;       
    unsigned char vector[4]; 
};

int main() {
    union FloatBytes fb;
    fb.value = 15.0f;  
    printf("Float: %f\nFP: 0x", fb.value);
    for (int i = 3; i >= 0; i--) {
        printf("%02X", fb.vector[i]);
    }
    return 0;
}


union flag{
    struct flags{
        unsigned int bit0:1;
        unsigned int bit1:1;
    }var;
    
}