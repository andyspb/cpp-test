#ifndef ARRAYS_AND_STRINGS_H_
#define ARRAYS_AND_STRINGS_H_

#include <assert.h>
#include "test_1_1_string_has_all_unique_characters.h"
#include "test_1_2_reverse_c_string.h"
#include "test_1_3_remove_duplicates_form_string.h"
#include "test_1_4_strings_are_anagram.h"
#include "test_1_5_replace_all_spaces_in_string_with_pers20.h"
#include "test_1_6_rotate_image.h"
#include "test_1_7_if_element_matrix_is_0_entire_row_and_column_set_0.h"
#include "test_1_8_check_string_rotation_if_has_substr.h"

namespace arrays_and_strings {
int test() {
  assert(test_1_1_string_has_all_unique_characters::test());
  assert(test_1_2_reverse_c_string::test());
  assert(test_1_3_remove_duplicates_form_string::test());
  assert(test_1_4_strings_are_anagram::test());
  assert(test_1_5_replace_all_spaces_in_string_with_pers20::test());
  assert(test_1_6_rotate_image::test());
  assert(test_1_7_if_element_matrix_is_0_entire_row_and_column_set_0::test());
  assert(test_1_8_check_string_rotation_if_has_substr::test());
  return 1;
}
} // arrays_and_strings

#endif /* ARRAYS_AND_STRINGS_H_ */
