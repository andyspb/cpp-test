/*
 * language.h
 *
 *  Created on: May 23, 2012
 *      Author: Andy
 */

#ifndef LANGUAGE_H_
#define LANGUAGE_H_

#include <assert.h>
#include <iostream>

#include "array.h"
#include "atomic.h"
#include "binary.h"
#include "bind1st.h"
#include "bind2nd.h"
#include "binder1st.h"
#include "binder2nd.h"
#include "bits_arithmetic.h"
#include "cast_1.h"
#include "cast_2.h"
#include "cast_sidecast.h"
#include "char_array.h"
#include "class_initialization.h"
#include "const_char_test.h"
#include "const_method.h"
#include "constexpr_test.h"
#include "constructor_exception.h"
#include "copy.h"
#include "cout.h"
#include "delete.h"
#include "dynamic_cast.h"
#include "dynamic_cast_2.h"
#include "dynamic_cast_3.h"
#include "generic_list_test.h"
#include "goto_.h"
#include "que_test.h"
#include "cast_const.h"
#include "ctor_test.h"
#include "function_parameter.h"
#include "function_pointers.h"
#include "hash_map.h"
#include "initialization_with_this.h"
#include "inheritance.h"
#include "iterator.h"
#include "lambda.h"
#include "namespace_test.h"
#include "my_queue.h"
#include "stl_tests.h"
#include "method_hiding.h"
#include "my_stack.h"
#include "pointer_as_param.h"
#include "pointer_2_function.h"
#include "private_constructor.h"
#include "pure_virtual_call.h"
#include "set_test.h"
#include "sizeof.h"
#include "stack_container.h"
#include "static_cast.h"
#include "string_literal.h"
#include "strlen_test.h"
#include "type_traits.h"
#include "union.h"
#include "va_args.h"
#include "vector_pointer_arithmetic.h"
#include "virtual_destr.h"
#include "virtual_method.h"
#include "virtual_function_default_param.h"
#include "virtual_method_2.h"

namespace language {
TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;

//  assert(atomic_::test());
//  assert(binary::test());
//  assert(bind1st_::test());
//  assert(bind2nd_::test());
//  assert(binder1st_::test());
//  assert(binder2nd_::test());
//  assert(bits_arithmetic::test());
//  assert(cast_1::test());
//  assert(cast_2::test());
//  assert(cast_sidecast::test());
//  assert(char_array::test());
//  assert(class_initialization::test());
//  assert(generic_list_test::test());
//  assert(const_method::test());
//  assert(container_stack_test::test());
//  assert(const_char_test::test());

//  assert(cast_const::test());
//  assert(constexpr_test::test());
  //	assert(constructor_exception::test());

//  assert(copy_::test());

//  assert(cout_::test());
//  assert(delete_::test());
//  assert(dynamic_cast_::test());
//  assert(dynamic_cast_2::test());
//  assert(dynamic_cast_3::test());
//  assert(function_parameter::test());

//  assert(goto_::test());

//  assert(function_pointers::test());
//  assert(intialization_with_this::test());
  //	assert(inheritance::test());

//  assert(language_lambda::test());

  //    assert(namespace_test::test());
//  assert(method_hiding::test());
//  assert(my_queue::test());
//  assert(my_stack::test());

//  assert(que_test::test());

//  assert(pointer_as_param::test());
//  assert(pointer_to_function::test());

//  assert(private_constructor::test());
//  assert(pure_virt_call::test());
//  assert(set_test::test());

//    assert(static_cast_::test());
//	assert(string_literal::test());
//	assert(size_of::test());
//  assert(stl_tests::test());
//	assert(strlen_test::test());

//  assert(type_traits::test());

//  assert(union_::test());
  assert(va_args::test());
//  assert(vector_pointer_arithmetic::test());
//  assert(virtual_destr::test());
//  assert(virtual_method::test());
//  assert(virtual_function_default_param::test());
//  assert(virtuals::test());
	RETURN_OK();
}
} // namespace language

#endif /* LANGUAGE_H_ */
