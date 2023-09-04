#include <sys/stat.h>
#include <fcntl.h>
#include <elf.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void pr_data(unsigned char *e_ident);
void pr_version(unsigned char *e_ident);
void pr_abi(unsigned char *e_ident);
void check_elf(unsigned char *e_ident);
void pr_magic(unsigned char *e_ident);
void pr_class(unsigned char *e_ident);
void pr_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);
void pr_osabi(unsigned char *e_ident);
void pr_type(unsigned int e_type, unsigned char *e_ident);

/**
 * check_elf - it Checks if a file is an ELF file.
 * @e_ident: the pointer to an array containing the ELF magic numbers.
 *
 * Description: if the file is not an ELF file - exit code 98.
 */
void check_elf(unsigned char *e_ident)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (e_ident[i] != 127 &&
		    e_ident[i] != 'E' &&
		    e_ident[i] != 'L' &&
		    e_ident[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * pr_magic - it Prints the magic numbers of an ELF header.
 * @e_ident: the pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void pr_magic(unsigned char *e_ident)
{
	int i;

	printf(" Magic: ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * pr_class - it Prints the class of an ELF header.
 * @e_ident: the pointer to an array containing the ELF class.
 */
void pr_class(unsigned char *e_ident)
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

/**
 * pr_data - it Prints the data of an ELF header.
 * @e_ident: the pointer to an array containing the ELF class.
 */
void pr_data(unsigned char *e_ident)
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

/**
 * pr_version - it Prints the version of an ELF header.
 * @e_ident: the pointer to an array containing the ELF version.
 */
void pr_version(unsigned char *e_ident)
{
	 printf(" Version: %d",
			  e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * pr_osabi - it Prints the OS/ABI of an ELF header.
 * @e_ident: the pointer to an array containing the ELF version.
 */
void pr_osabi(unsigned char *e_ident)
{
	printf(" OS/ABI: ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * pr_abi - it Prints the ABI version of an ELF header.
 * @e_ident: the pointer to an array containing the ELF ABI version.
 */
void pr_abi(unsigned char *e_ident)
{
	printf(" ABI Version: %d\n",
		e_ident[EI_ABIVERSION]);
}

/**
 * pr_type - it Prints the type of an ELF header.
 * @e_type: the ELF type.
 * @e_ident: the pointer to an array containing the ELF class.
 */
void pr_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

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

/**
 * pr_entry - it Prints the entry point of an ELF header.
 * @e_entry: the address of the ELF entry point.
 * @e_ident: the pointer to an array containing the ELF class.
 */
void pr_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" Entry point address: ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - it Closes an ELF file.
 * @elf: the file descriptor of the ELF file.
 *
 * Description: if the file cannot be closed - exit code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - it Displays the information contained in the
 * ELF header at the start of an ELF file.
 * @argc: the number of arguments supplied to the program.
 * @argv: the array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: if the file is not an ELF File or
 * the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *head;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	head = malloc(sizeof(Elf64_Ehdr));
	if (head == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, head, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(head);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(head->e_ident);
	printf("ELF head:\n");
	pr_magic(head->e_ident);
	pr_class(head->e_ident);
	pr_data(head->e_ident);
	pr_version(head->e_ident);
	pr_osabi(head->e_ident);
	pr_abi(head->e_ident);
	pr_type(head->e_type, head->e_ident);
	pr_entry(head->e_entry, head->e_ident);

	free(head);
	close_elf(o);
	return (0);
}

