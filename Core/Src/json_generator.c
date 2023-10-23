#include "json_generator.h"
#include <stdio.h>
#include <string.h>

bool json_init (json_generator_t *generator, char *buffer, size_t size)
{
    if (generator == NULL || buffer == NULL || size == 0) 
    {
        return false;
    }

    generator->buffer = buffer;
    generator->size = size;
    generator->index = 0;
    generator->depth = 0;

    memset(buffer, 0, size);

    return true;
}

bool json_open_object (json_generator_t *generator)
{
    if (generator == NULL || generator->depth >= JSON_MAX_DEPTH) 
    {
        return false;
    }

    if (generator->index < generator->size) 
    {
        generator->buffer[generator->index++] = '{';
        generator->depth++;

        return true;
    }
    else
    {
        return false;
    }
}

bool json_close_object (json_generator_t *generator)
{
    if (generator == NULL || generator->depth == 0) 
    {
        return false;
    }

    if (generator->buffer[generator->index-1] == ',')
    {
        generator->index--;
    }

    if (generator->index < generator->size)
    {
        snprintf(generator->buffer + generator->index, generator->size - generator->index, "},");
        generator->index += 2;
        generator->depth--;

        return true;
    }
    else
    {
        return false;
    }
}

bool json_open_array (json_generator_t *generator)
{
    if (generator == NULL || generator->depth >= JSON_MAX_DEPTH) 
    {
        return false;
    }

    if (generator->index < generator->size) 
    {
        generator->buffer[generator->index++] = '[';
        generator->depth++;

        return true;
    }
    else
    {
        return false;
    }
}

bool json_close_array (json_generator_t *generator)
{
    if (generator == NULL || generator->depth == 0) 
    {
        return false;
    }

    if (generator->buffer[generator->index-1] == ',')
    {
        generator->index--;
    }

    if (generator->index < generator->size) 
    {
        snprintf(generator->buffer + generator->index, generator->size - generator->index, "],");
        generator->index += 2;
        generator->depth--;

        return true;
    }
    else
    {
        return false;
    }
}

bool json_add_string (json_generator_t *generator, const char *key, const char *value)
{
    if (generator == NULL || key == NULL || value == NULL || generator->depth == 0) 
    {
        return false;
    }

    size_t key_length = strnlen(key, JSON_MAX_KEY_LENGTH);
    size_t value_length = strnlen(value, generator->size - generator->index);

    if ((generator->index + key_length + value_length + 6) < generator->size) 
    {
        snprintf(generator->buffer + generator->index, generator->size - generator->index, "\"%s\":\"%s\",", key, value);
        generator->index += key_length + value_length + 6;

        return true;
    }
    else
    {
        return false;
    }
}

bool json_add_integer (json_generator_t *generator, const char *key, int value)
{
    if (generator == NULL || key == NULL || generator->depth == 0) 
    {
        return false;
    }

    size_t key_length = strnlen(key, JSON_MAX_KEY_LENGTH);
    size_t value_length = snprintf(NULL, 0, "%d", value);

    if ((generator->index + key_length + value_length + 4) < generator->size) 
    {
        snprintf(generator->buffer + generator->index, generator->size - generator->index, "\"%s\":%d,", key, value);
        generator->index += key_length + value_length + 4;

        return true;
    }
    else
    {
        return false;
    }
}

bool json_add_boolean (json_generator_t *generator, const char *key, bool value)
{
    if (generator == NULL || key == NULL || generator->depth == 0) 
    {
        return false;
    }

    size_t key_length = strnlen(key, JSON_MAX_KEY_LENGTH);
    const char *bool_value = value ? "true" : "false";
    size_t value_length = strnlen(bool_value, 6);

    if ((generator->index + key_length + value_length + 4) < generator->size) 
    {
        snprintf(generator->buffer + generator->index, generator->size - generator->index, "\"%s\":%s,", key, bool_value);
        generator->index += key_length + value_length + 4;

        return true;
    }
    else
    {
        return false;
    }
}

bool json_add_null (json_generator_t *generator, const char *key)
{
    if (generator == NULL || key == NULL || generator->depth == 0)
    {
        return false;
    }

    size_t key_length = strnlen(key, JSON_MAX_KEY_LENGTH);

    if ((generator->index + key_length + 8) < generator->size) 
    {
        snprintf(generator->buffer + generator->index, generator->size - generator->index, "\"%s\":null,", key);
        generator->index += key_length + 8;

        return true;
    }
    else
    {
        return false;
    }
}

bool json_end (json_generator_t *generator)
{
    if (generator == NULL || generator->depth != 0)
    {
        return false;
    }

    if (generator->buffer[generator->index-1] == ',')
    {
        generator->index--;
    }

    if (generator->index < generator->size)
    {
        generator->buffer[generator->index] = '\0';
        return true;
    }

    return false;
}
