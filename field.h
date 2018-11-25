#pragma once
#include "base.h"

void field_init(Field* f);
void field_init_fill(Field* f, U32 height, U32 width, Term fill_char);
void field_resize_raw(Field* f, U32 height, U32 width);
void field_deinit(Field* f);
void field_copy_subrect(Field* src, Field* dest, U32 src_y, U32 src_x,
                        U32 dest_y, U32 dest_x, U32 height, U32 width);
void field_fill_subrect(Field* f, U32 y, U32 x, U32 height, U32 width,
                        Term fill_char);
Term field_peek(Field* f, U32 y, U32 x);
void field_poke(Field* f, U32 y, U32 x, Term term);

void field_fput(Field* f, FILE* stream);

typedef enum {
  Field_load_error_ok = 0,
  Field_load_error_cant_open_file = 1,
  Field_load_error_too_many_columns = 2,
  Field_load_error_no_rows_read = 3,
  Field_load_error_not_a_rectangle = 4,
} Field_load_error;

Field_load_error field_load_file(char const* filepath, Field* field);