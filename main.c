#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "criptografia.h"

#define MAX_BUFFER 1024

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void menu_cesar() {
    char texto[MAX_BUFFER];
    int chave, opcao;
    
    printf("\n=== CIFRA DE CÉSAR ===\n");
    printf("1. Criptografar\n");
    printf("2. Descriptografar\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    limpar_buffer();
    
    printf("Digite o texto: ");
    fgets(texto, MAX_BUFFER, stdin);
    texto[strcspn(texto, "\n")] = 0; // Remove newline
    
    printf("Digite a chave (número): ");
    scanf("%d", &chave);
    limpar_buffer();
    
    if (opcao == 1) {
        cifra_cesar_encrypt(texto, chave);
        printf("\nTexto criptografado: %s\n", texto);
    } else if (opcao == 2) {
        cifra_cesar_decrypt(texto, chave);
        printf("\nTexto descriptografado: %s\n", texto);
    } else {
        printf("\nOpção inválida!\n");
    }
}

void menu_xor() {
    char texto[MAX_BUFFER];
    char hex[MAX_BUFFER * 2];
    unsigned char resultado[MAX_BUFFER];
    char chave;
    int opcao, len;
    
    printf("\n=== XOR EM HEXADECIMAL ===\n");
    printf("1. Criptografar texto para hexadecimal\n");
    printf("2. Descriptografar hexadecimal para texto\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    limpar_buffer();
    
    printf("Digite a chave (um caractere): ");
    scanf("%c", &chave);
    limpar_buffer();
    
    if (opcao == 1) {
        printf("Digite o texto: ");
        fgets(texto, MAX_BUFFER, stdin);
        texto[strcspn(texto, "\n")] = 0; // Remove newline
        
        xor_encrypt_decrypt(texto, chave);
        string_to_hex((unsigned char *)texto, strlen(texto), hex);
        
        printf("\nTexto criptografado (hexadecimal): %s\n", hex);
    } else if (opcao == 2) {
        printf("Digite o texto hexadecimal: ");
        fgets(hex, MAX_BUFFER * 2, stdin);
        hex[strcspn(hex, "\n")] = 0; // Remove newline
        
        hex_to_string(hex, resultado, &len);
        xor_encrypt_decrypt((char *)resultado, chave);
        
        printf("\nTexto descriptografado: %s\n", resultado);
    } else {
        printf("\nOpção inválida!\n");
    }
}

void menu_base64() {
    char texto[MAX_BUFFER];
    unsigned char resultado[MAX_BUFFER];
    char encoded[MAX_BUFFER * 2];
    int opcao;
    
    printf("\n=== BASE64 ===\n");
    printf("1. Codificar\n");
    printf("2. Decodificar\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    limpar_buffer();
    
    if (opcao == 1) {
        printf("Digite o texto: ");
        fgets(texto, MAX_BUFFER, stdin);
        texto[strcspn(texto, "\n")] = 0; // Remove newline
        
        base64_encode((unsigned char *)texto, strlen(texto), encoded);
        printf("\nTexto codificado (Base64): %s\n", encoded);
    } else if (opcao == 2) {
        printf("Digite o texto em Base64: ");
        fgets(encoded, MAX_BUFFER * 2, stdin);
        encoded[strcspn(encoded, "\n")] = 0; // Remove newline
        
        base64_decode(encoded, resultado);
        printf("\nTexto decodificado: %s\n", resultado);
    } else {
        printf("\nOpção inválida!\n");
    }
}

int main() {
    int opcao;
    
    printf("╔═══════════════════════════════════════════════════════════════╗\n");
    printf("║         SISTEMA DE CRIPTOGRAFIA BÁSICA - IFRS                ║\n");
    printf("║    Desenvolvido no curso de Análise e Desenvolvimento        ║\n");
    printf("║              Professor: Cassandro Davi Emmer                 ║\n");
    printf("╚═══════════════════════════════════════════════════════════════╝\n");
    
    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Cifra de César\n");
        printf("2. XOR em Hexadecimal\n");
        printf("3. Base64\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limpar_buffer();
        
        switch(opcao) {
            case 1:
                menu_cesar();
                break;
            case 2:
                menu_xor();
                break;
            case 3:
                menu_base64();
                break;
            case 0:
                printf("\nEncerrando o programa. Até logo!\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
    
    return 0;
}
