# Criptografia

Projeto em C desenvolvido no curso de Análise e Desenvolvimento de Sistemas do IFRS, com orientação do professor Cassandro Davi Emmer. Implementa criptografia básica: Cifra de César, XOR em hexadecimal e Base64. Ideal para estudo, testes e demonstração de técnicas simples.

## 📚 Funcionalidades

Este sistema implementa três técnicas de criptografia básica:

### 1. Cifra de César
- Criptografia e descriptografia de texto usando deslocamento alfabético
- Suporta chaves de qualquer valor inteiro
- Preserva maiúsculas e minúsculas
- Exemplo: "Hello" com chave 3 → "Khoor"

### 2. XOR em Hexadecimal
- Criptografia XOR com representação em hexadecimal
- Converte texto para hexadecimal após criptografia
- Converte hexadecimal para texto na descriptografia
- Exemplo: "Hello" com chave 'K' → "032e272724"

### 3. Base64
- Codificação e decodificação padrão Base64
- Compatível com outras implementações Base64
- Exemplo: "Hello World" → "SGVsbG8gV29ybGQ="

## 🚀 Como Compilar

### Pré-requisitos
- GCC (GNU Compiler Collection)
- Make

### Compilação
```bash
make
```

Para limpar arquivos compilados:
```bash
make clean
```

Para compilar e executar:
```bash
make run
```

## 💻 Como Usar

### Execução Interativa
```bash
./criptografia
```

O programa apresenta um menu interativo com as seguintes opções:
1. Cifra de César
2. XOR em Hexadecimal
3. Base64
0. Sair

### Testes Automatizados
Para executar os testes automatizados:
```bash
gcc test.c criptografia.c -o test_crypto
./test_crypto
```

## 📁 Estrutura do Projeto

```
.
├── README.md           # Documentação do projeto
├── criptografia.h      # Declarações das funções
├── criptografia.c      # Implementação das funções
├── main.c              # Interface interativa com menu
├── test.c              # Testes automatizados
├── Makefile            # Script de compilação
└── .gitignore          # Arquivos ignorados pelo Git
```

## 🔍 Exemplos de Uso

### Cifra de César
```
Texto original: Hello World
Chave: 3
Resultado: Khoor Zruog
```

### XOR
```
Texto original: Criptografia
Chave: A
Resultado (hex): 02332831352e263320272820
```

### Base64
```
Texto original: IFRS - Analise e Desenvolvimento
Resultado: SUZSUyAtIEFuYWxpc2UgZSBEZXNlbnZvbHZpbWVudG8=
```

## 👨‍🏫 Informações Acadêmicas

**Instituição:** Instituto Federal do Rio Grande do Sul (IFRS)  
**Curso:** Análise e Desenvolvimento de Sistemas  
**Professor Orientador:** Cassandro Davi Emmer  

## 📝 Licença

Este projeto foi desenvolvido para fins educacionais.
