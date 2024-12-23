#include "circular_buffer.h"

circular_buffer_t *new_circular_buffer(size_t capacity) {
    if (capacity == 0) return NULL;
    circular_buffer_t *buffer = malloc(sizeof(circular_buffer_t));
    if (!buffer) return NULL;
    buffer->buffer = malloc(sizeof(buffer_value_t) * capacity);
    if (!buffer->buffer) {
        free(buffer);
        return NULL;
    }
    buffer->capacity = capacity;
    buffer->size = 0;
    buffer->read_pos = 0;
    buffer->write_pos = 0;
    return buffer;
}

void delete_buffer(circular_buffer_t *buffer) {
    if (buffer) {
        free(buffer->buffer);
        free(buffer);
    }
}

int16_t write(circular_buffer_t *buffer, buffer_value_t value) {
    if (buffer->size == buffer->capacity) {
        errno = ENOBUFS;
        return EXIT_FAILURE;
    }
    buffer->buffer[buffer->write_pos] = value;
    buffer->write_pos = (buffer->write_pos + 1) % buffer->capacity;
    buffer->size++;
    return EXIT_SUCCESS;
}

int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value) {
    if (buffer->size == buffer->capacity) {
        buffer->buffer[buffer->write_pos] = value;
        buffer->write_pos = (buffer->write_pos + 1) % buffer->capacity;
        buffer->read_pos = (buffer->read_pos + 1) % buffer->capacity; // Move the read position
    } else {
        write(buffer, value);
    }
    return EXIT_SUCCESS;
}

int16_t read(circular_buffer_t *buffer, buffer_value_t *value) {
    if (buffer->size == 0) {
        errno = ENODATA;
        return EXIT_FAILURE;
    }
    *value = buffer->buffer[buffer->read_pos];
    buffer->read_pos = (buffer->read_pos + 1) % buffer->capacity;
    buffer->size--;
    return EXIT_SUCCESS;
}

void clear_buffer(circular_buffer_t *buffer) {
    buffer->size = 0;
    buffer->read_pos = 0;
    buffer->write_pos = 0;
}
