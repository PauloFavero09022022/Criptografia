#ifndef CRIPTOGRAFIA_H
#define CRIPTOGRAFIA_H

// Cifra de César
void cifra_cesar_encrypt(char *texto, int chave);
void cifra_cesar_decrypt(char *texto, int chave);

// XOR em hexadecimal
void xor_encrypt_decrypt(char *texto, char chave);
void string_to_hex(unsigned char *input, int len, char *output);
void hex_to_string(char *hex, unsigned char *output, int *len);

// Base64
void base64_encode(unsigned char *input, int len, char *output);
int base64_decode(char *input, unsigned char *output);

#endif
