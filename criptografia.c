#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "criptografia.h"

// Cifra de César - Criptografia
void cifra_cesar_encrypt(char *texto, int chave) {
    int i;
    chave = chave % 26; // Normaliza a chave
    
    for (i = 0; texto[i] != '\0'; i++) {
        if (isalpha(texto[i])) {
            char base = isupper(texto[i]) ? 'A' : 'a';
            texto[i] = (texto[i] - base + chave) % 26 + base;
        }
    }
}

// Cifra de César - Descriptografia
void cifra_cesar_decrypt(char *texto, int chave) {
    int i;
    chave = chave % 26; // Normaliza a chave
    
    for (i = 0; texto[i] != '\0'; i++) {
        if (isalpha(texto[i])) {
            char base = isupper(texto[i]) ? 'A' : 'a';
            texto[i] = (texto[i] - base - chave + 26) % 26 + base;
        }
    }
}

// XOR - Criptografia e Descriptografia (mesma operação)
void xor_encrypt_decrypt(char *texto, char chave) {
    int i;
    for (i = 0; texto[i] != '\0'; i++) {
        texto[i] = texto[i] ^ chave;
    }
}

// Converte string para hexadecimal
void string_to_hex(unsigned char *input, int len, char *output) {
    int i;
    for (i = 0; i < len; i++) {
        sprintf(output + (i * 2), "%02x", input[i]);
    }
    output[len * 2] = '\0';
}

// Converte hexadecimal para string
void hex_to_string(char *hex, unsigned char *output, int *len) {
    int i;
    *len = strlen(hex) / 2;
    
    for (i = 0; i < *len; i++) {
        sscanf(hex + 2 * i, "%2hhx", &output[i]);
    }
    output[*len] = '\0';
}

// Tabela Base64
static const char base64_chars[] = 
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// Base64 - Codificação
void base64_encode(unsigned char *input, int len, char *output) {
    int i, j;
    unsigned char char_array_3[3];
    unsigned char char_array_4[4];
    int out_pos = 0;
    
    i = 0;
    j = 0;
    
    while (len--) {
        char_array_3[i++] = *(input++);
        if (i == 3) {
            char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
            char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
            char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
            char_array_4[3] = char_array_3[2] & 0x3f;
            
            for (i = 0; i < 4; i++)
                output[out_pos++] = base64_chars[char_array_4[i]];
            i = 0;
        }
    }
    
    if (i) {
        for (j = i; j < 3; j++)
            char_array_3[j] = '\0';
        
        char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
        char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
        char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
        
        for (j = 0; j < i + 1; j++)
            output[out_pos++] = base64_chars[char_array_4[j]];
        
        while (i++ < 3)
            output[out_pos++] = '=';
    }
    
    output[out_pos] = '\0';
}

// Função auxiliar para decodificar Base64
static int base64_char_value(char c) {
    if (c >= 'A' && c <= 'Z') return c - 'A';
    if (c >= 'a' && c <= 'z') return c - 'a' + 26;
    if (c >= '0' && c <= '9') return c - '0' + 52;
    if (c == '+') return 62;
    if (c == '/') return 63;
    return -1;
}

// Base64 - Decodificação
int base64_decode(char *input, unsigned char *output) {
    int len = strlen(input);
    int i = 0, j = 0, k = 0;
    unsigned char char_array_4[4], char_array_3[3];
    int out_len = 0;
    
    while (len-- && input[i] != '=') {
        if (base64_char_value(input[i]) == -1) {
            i++;
            continue;
        }
        
        char_array_4[j++] = input[i++];
        
        if (j == 4) {
            for (j = 0; j < 4; j++)
                char_array_4[j] = base64_char_value(char_array_4[j]);
            
            char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
            char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
            char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];
            
            for (j = 0; j < 3; j++)
                output[out_len++] = char_array_3[j];
            j = 0;
        }
    }
    
    if (j) {
        for (k = j; k < 4; k++)
            char_array_4[k] = 0;
        
        for (k = 0; k < 4; k++)
            char_array_4[k] = base64_char_value(char_array_4[k]);
        
        char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
        char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
        
        for (k = 0; k < j - 1; k++)
            output[out_len++] = char_array_3[k];
    }
    
    output[out_len] = '\0';
    return out_len;
}
