#ifndef DOG_H
#define DOG_H

/**
 * struct dog - a basic info of dog
 * @name: the First member
 * @age: the Second member
 * @owner: the Third member
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/**
 * dog_t - typedef for struct dog
 */
typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif
