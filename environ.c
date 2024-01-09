#include "shell.h"

typedef struct {
	char *name;
	char *value;
} env_var_t;

typedef struct {
	env_var_t **table;
	size_t size;
} hash_table_t;

hash_table_t *create_hash_table(size_t size)
{
	hash_table_t *hash_table = malloc(sizeof(hash_table_t));
	hash_table->table = calloc(size, sizeof(env_var_t *));
	hash_table->size = size;
	return hash_table;
}

char *get_from_hash_table(hash_table_t *hash_table, const char *name)
{
	size_t index = hash_function(name) % hash_table->size;
	env_var_t *env_var = hash_table->table[index];
	if (env_var && strcmp(env_var->name, name) == 0) {
		return env_var->value;
	}
	return NULL;
}

void insert_into_hash_table(hash_table_t *hash_table, const char *name, const char *value)
{
	size_t index = hash_function(name) % hash_table->size;
	env_var_t *env_var = malloc(sizeof(env_var_t));
	env_var->name = strdup(name);
	env_var->value = strdup(value);
	hash_table->table[index] = env_var;
}

int _myenv(info_t *info)
{
	print_hash_table(info->env);
	return 0;
}

int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return 1;
	}
	insert_into_hash_table(info->env, info->argv[1], info->argv[2]);
	return 0;
}

int _myunsetenv(info_t *info)
{
	if (info->argc == 1)
	{
		_eputs("Too few arguments.\n");
		return 1;
	}
	for (int i = 1; i <= info->argc; i++)
		remove_from_hash_table(info->env, info->argv[i]);

	return 0;
}

int populate_env_hash_table(info_t *info)
{
	hash_table_t *hash_table = create_hash_table(HASH_TABLE_SIZE);

	for (int i = 0; environ[i]; i++)
		insert_into_hash_table(hash_table, get_name(environ[i]), get_value(environ[i]));

	info->env = hash_table;
	return 0;
}