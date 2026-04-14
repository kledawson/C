#include <stdio.h>

void switchChar(unsigned char *x, unsigned char *y) {
    unsigned char temp = *x;
    *x = *y;
    *y = temp;
}

unsigned char getByte(unsigned char *S) {
    int i = 0;int j = 0;

    i = (i + 1);
    i = i % 256;

    j = (j + S[i]);
    j = j % 256;

    switchChar(&S[i], &S[j]);

    return S[(S[i] + S[j]) % 256];
}

// from page 51 psuedocode
void initalizeRC4Array(unsigned char *key, int length, unsigned char *S) {
    int j = 0;

    for (int i = 0; i < 256; i++) {
        S[i] = i;

    }

    for (int i = 0; i < 256; i++) {
        j = (j + S[i] + key[i % length]) % 256;
        switchChar(&S[i], &S[j]);
    }
}


int main() {
    unsigned char k[] = {0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F, 0x77};
    unsigned char S[256];

    printf("Key (0x__): ");
    for (int i = 0; i < sizeof(k); i++) {
        printf("%02x ", k[i]);
    }

    printf("\n");

    initalizeRC4Array(k, sizeof(k), S);

    // Print S and indices after initialization
    printf("\nAfter initialization we get:\n");
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            printf("%02x ", S[i * 16 + j]);
        }
        printf("\n");
    }
    printf("i: %d\n", getByte(S));
    printf("j: %d\n", getByte(S));

    for (int i = 0; i < 100; i++) {
        getByte(S);
    }

    printf("\n");
    printf("Keystream after the first 100 bytes are");
    printf("\n");
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            printf("%02x ", S[i * 16 + j]);
        }
        printf("\n");
    }
    printf("i: %d\n", getByte(S));
    printf("j: %d\n", getByte(S));

    for (int i = 0; i < 1000; i++) {
        getByte(S);
    }

    printf("\n");
    printf("Keystream after the first 1000 bytes are");
    printf("\n");
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            printf("%02x ", S[i * 16 + j]);
        }
        printf("\n");
    }
    printf("i: %d\n", getByte(S));
    printf("j: %d\n", getByte(S));

    return 0;
}