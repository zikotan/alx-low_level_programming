#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// Function declarations
void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_type(unsigned int e_type);

void close_elf(int elf);

// Function to check if it's an ELF file
void check_elf(unsigned char *e_ident)
{
    int index;

    // Check the ELF magic numbers
    for (index = 0; index < 4; index++)
    {
        if (e_ident[index] != 127 &&
            e_ident[index] != 'E' &&
            e_ident[index] != 'L' &&
            e_ident[index] != 'F')
        {
            dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
            exit(98);
        }
    }
}

// Function to print ELF magic numbers
void print_magic(unsigned char *e_ident)
{
    int index;

    printf(" Magic: ");

    // Print each byte of the magic numbers
    for (index = 0; index < EI_NIDENT; index++)
    {
        printf("%02x", e_ident[index]);

        if (index == EI_NIDENT - 1)
            printf("\n");
        else
            printf(" ");
    }
}

// Function to print ELF class
void print_class(unsigned char *e_ident)
{
    printf(" Class: ");

    switch (e_ident[EI_CLASS])
    {
    case ELFCLASSNONE:
        printf("none\n");
        break;
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_CLASS]);
    }
}

// Function to print ELF data encoding
void print_data(unsigned char *e_ident)
{
    printf(" Data: ");

    switch (e_ident[EI_DATA])
    {
    case ELFDATANONE:
        printf("none\n");
        break;
    case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_CLASS]);
    }
}

// Function to print ELF type
void print_type(unsigned int e_type)
{
    printf(" Type: ");

    switch (e_type)
    {
    case ET_NONE:
        printf("NONE (None)\n");
        break;
    case ET_REL:
        printf("REL (Relocatable file)\n");
        break;
    case ET_EXEC:
        printf("EXEC (Executable file)\n");
        break;
    case ET_DYN:
        printf("DYN (Shared object file)\n");
        break;
    case ET_CORE:
        printf("CORE (Core file)\n");
        break;
    default:
        printf("<unknown: %x>\n", e_type);
    }
}

// Function to close the ELF file
void close_elf(int elf)
{
    if (close(elf) == -1)
    {
        dprintf(STDERR_FILENO,
                "Error: Can't close fd %d\n", elf);
        exit(98);
    }
}

int main(int __attribute__((__unused__)) argc, char *argv[])
{
    Elf64_Ehdr *header;
    int o, r;

    // Open the ELF file
    o = open(argv[1], O_RDONLY);
    if (o == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
        exit(98);
    }
    header = malloc(sizeof(Elf64_Ehdr));
    if (header == NULL)
    {
        close_elf(o);
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
        exit(98);
    }
    r = read(o, header, sizeof(Elf64_Ehdr));
    if (r == -1)
    {
        free(header);
        close_elf(o);
        dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
        exit(98);
    }

    // Print ELF header information
    check_elf(header->e_ident);
    printf("ELF Header:\n");
    print_magic(header->e_ident);
    print_class(header->e_ident);
    print_data(header->e_ident);
    print_type(header->e_type);

    // Clean up and close the ELF file
    free(header);
    close_elf(o);
    return (0);
}

