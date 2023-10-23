#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define JSON_MAX_DEPTH          10
#define JSON_MAX_KEY_LENGTH     32

typedef struct {
  char *buffer;
  uint32_t size;
  uint32_t index;
  uint32_t depth;
} json_generator_t;

bool json_init(json_generator_t *generator, char *buffer, size_t size);
bool json_open_object(json_generator_t *generator);
bool json_close_object(json_generator_t *generator);
bool json_open_array(json_generator_t *generator);
bool json_close_array(json_generator_t *generator);
bool json_add_string(json_generator_t *generator, const char *key, const char *value);
bool json_add_integer(json_generator_t *generator, const char *key, int value);
bool json_add_boolean(json_generator_t *generator, const char *key, bool value);
bool json_add_null(json_generator_t *generator, const char *key);
bool json_end(json_generator_t *generator);
