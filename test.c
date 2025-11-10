#include <stdio.h>
#include <string.h>
#include "criptografia.h"

void test_cesar() {
    char texto1[100] = "Hello World";
    char texto2[100] = "Khoor Zruog";
    
    printf("=== TESTE CIFRA DE CÉSAR ===\n");
    printf("Texto original: %s\n", texto1);
    cifra_cesar_encrypt(texto1, 3);
    printf("Criptografado (chave=3): %s\n", texto1);
    
    cifra_cesar_decrypt(texto2, 3);
    printf("Descriptografado: %s\n\n", texto2);
}

void test_xor() {
    char texto[100] = "Hello";
    char hex[200];
    unsigned char resultado[100];
    int len;
    
    printf("=== TESTE XOR ===\n");
    printf("Texto original: %s\n", texto);
    xor_encrypt_decrypt(texto, 'K');
    string_to_hex((unsigned char *)texto, strlen(texto), hex);
    printf("Criptografado (hex): %s\n", hex);
    
    hex_to_string(hex, resultado, &len);
    xor_encrypt_decrypt((char *)resultado, 'K');
    printf("Descriptografado: %s\n\n", resultado);
}

void test_base64() {
    unsigned char texto[] = "Hello World";
    char encoded[200];
    unsigned char decoded[100];
    
    printf("=== TESTE BASE64 ===\n");
    printf("Texto original: %s\n", texto);
    base64_encode(texto, strlen((char *)texto), encoded);
    printf("Codificado: %s\n", encoded);
    
    base64_decode(encoded, decoded);
    printf("Decodificado: %s\n\n", decoded);
}

int main() {
    printf("╔═══════════════════════════════════════════════╗\n");
    printf("║       TESTES DO SISTEMA DE CRIPTOGRAFIA      ║\n");
    printf("╚═══════════════════════════════════════════════╝\n\n");
    
    test_cesar();
    test_xor();
    test_base64();
    
    printf("Todos os testes concluídos com sucesso!\n");
    return 0;
}
