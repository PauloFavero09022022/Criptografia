🔐 Projeto de Criptografia em C
Este projeto foi desenvolvido como parte do Curso de Tecnologia em Análise e Desenvolvimento de Sistemas do Instituto Federal do Rio Grande do Sul (IFRS), com orientação do professor Cassandro Davi Emmer. O objetivo é estudar e demonstrar operações básicas de criptografia utilizando a linguagem C.

📌 Descrição
Implementa três técnicas fundamentais de criptografia:

Cifra de César (codificação e decodificação)

XOR com entrada/saída em hexadecimal

Base64 (codificação e decodificação)

📁 Arquivos principais
Cript.c — implementação completa com menu interativo.

Cript.exe — binário gerado (não incluído por padrão).

README.md — este documento.

🧰 Requisitos
Compilador C compatível com C11 (testado com GCC/MinGW no Windows).

Ambiente Windows (testado no PowerShell).

⚙️ Implementação técnica
Linguagem: C (padrão C11)

Principais funções:

caesar_encrypt, caesar_decrypt — cifra de César com preservação de maiúsculas/minúsculas.

bytes_to_hex, hex_to_bytes — conversão entre bytes e hexadecimal.

xor_bytes — aplica XOR entre buffer e chave (com repetição da chave).

base64_encode, base64_decode — codificação Base64 minimalista (RFC 4648).

read_line — leitura segura de linha com remoção de \\n.

Bibliotecas padrão: <stdio.h>, <stdlib.h>, <string.h>, <ctype.h>

Sem dependências externas — tudo implementado em Cript.c.

🧪 Como o trabalho foi feito
Análise do código-fonte para melhorias em prompts, validação e buffers.

Testes manuais no Windows com MinGW/GCC e PowerShell:

Compilação com: -Wall -Wextra -std=c11 -O2

Execução interativa e simulação de entradas.

Melhorias aplicadas:

Prompts mais descritivos (ex.: "Deslocamento (número):") para evitar confusão.

🤖 Assistência com IA
Utilizei uma IA de linguagem para:

Revisar lógica e clareza dos prompts.

Sugerir melhorias de UX e instruções.

Exemplo de IA utilizada: Gemini PRO.

As decisões de design e o código final foram aplicados manualmente pelos autores.

👥 Autores e Contato
Paulo I.B Favero

Weligton Andrade

📧 Email: PauloFavero5347@gmail.com/ 

📅 Data: 10/11/2025
