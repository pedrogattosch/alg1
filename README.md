PT:
# Trabalho de algoritmos e estrutura de dados 1

Este projeto, desenvolvido em linguagem C, simula o fluxo de validação de certificados de extensão universitária. É utilizado estruturas de dados como pilhas e filas, tanto em suas versões estáticas quanto dinâmicas, para representar o processo completo.

## Objetivo

1. Alunos geram certificados com nome e carga horária.
2. Os certificados são empilhados na mesa do departamento.
3. O departamento os transfere para a fila de processos da coordenação.
4. O coordenador processa os certificados e registra as horas no sistema.
5. Os alunos podem validar 60 horas por disciplina extensionista.

## Estrutura

```
projeto/
├── main.c                # Função principal do programa.
├── PE.c / PE.h           # Pilha estática.
├── PD.c / PD.h           # Pilha dinâmica.
├── FD.c / FD.h           # Fila dinâmica.
├── FE.c / FE.h           # Fila estática.
├── certificado.h         # Definição da estrutura do certificado.
```

## Compilação

Você pode compilar o projeto com diferentes combinações de estruturas, alterando os #include no main.c. Exemplo com pilha estática e fila estática:

```bash
gcc main.c PE.c FE.c -o projeto
```

Para outras combinações, substitua PE.c e/ou FE.c por PD.c e/ou FD.c.

## Execução

```bash
./projeto
```

O programa aceitará comandos interativos via terminal, como:

```bash
> certificado pedro miguel 60
> departamento 2
> coordenador 1
> valida pedro miguel
> sistema
> F
```

## Comandos suportados

- certificado [nome] [CH]: Empilha certificado com carga horária.
- departamento [k]: Move até k certificados da pilha para a fila.
- coordenador [k]: Processa até k certificados da fila.
- valida [nome]: Valida 60 horas para o aluno, se possível.
- sistema: Exibe todos os alunos e horas registradas.
- F: Encerra a execução.

EN:
# Algorithms and data structures 1 project

This project, developed in C language, simulates the validation flow of university extension certificates. Data structures such as stacks and queues, both in their static and dynamic versions, are used to represent the complete process.

## Objective

1. Students generate certificates with name and workload hours.  
2. Certificates are stacked on the department’s desk.  
3. The department transfers them to the coordination process queue.  
4. The coordinator processes the certificates and records the hours in the system.  
5. Students can validate up to 60 hours per extension course.

## Structure

```
projeto/
├── main.c                # Main program function.
├── PE.c / PE.h           # Static stack.
├── PD.c / PD.h           # Dynamic stack.
├── FD.c / FD.h           # Dynamic queue.
├── FE.c / FE.h           # Static queue.
├── certificado.h         # Certificate structure definition.
```

## Compilation

You can compile the project with different combinations of data structures by changing the #include directives in main.c. Example using static stack and static queue:

```bash
gcc main.c PE.c FE.c -o project
```

For other combinations, replace PE.c and/or FE.c with PD.c and/or FD.c accordingly.

## Execution

```bash
./project
```

The program will accept interactive commands via terminal, such as:

```bash
> certificado pedro miguel 60
> departamento 2
> coordenador 1
> valida pedro miguel
> sistema
> F
```

## Supported commands

- certificado [name] [hours]: Pushes a certificate with workload hours.
- departamento [k]: Moves up to k certificates from the stack to the queue.
- coordenador [k]: Processes up to k certificates from the queue.
- valida [name]: Validates 60 hours for the student, if possible.
- sistema: Displays all students and recorded hours.
- F: Ends the execution.
