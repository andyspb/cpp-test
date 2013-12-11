TEMPLATE = app
CONFIG += console
CONFIG -= qt

DEPENDPATH += ../src/virtuals/

#DEFINES += -MD

LIBS += -lpthread
#LIBS += /usr/lib/libboost_thread.a
#LIBS += /usr/lib/libboost_system.a

INCLUDEPATH += ../src/algoritms/
#INCLUDEPATH += ../src/boost/
#INCLUDEPATH += ../src/cpp0x/
INCLUDEPATH += ../src/cracking_code_interview/
INCLUDEPATH += ../src/func/
INCLUDEPATH += ../src/virtual/
INCLUDEPATH += ../src/memory/
INCLUDEPATH += ../src/language/
INCLUDEPATH += ../src/hashcode/
INCLUDEPATH += ../src/facebook/


#HEADERS += boosts.h
HEADERS += mem_test.h \
    ../src/facebook/facebook.h
HEADERS += hash_function_sample.h
HEADERS += hashcodes.h
HEADERS += virtual_method.h
HEADERS += virtual_function_default_param.h
HEADERS += virtual_destr.h
HEADERS += vector_pointer_arithmetic.h
HEADERS += language/union.h
HEADERS += two_dimensional_array.h
HEADERS += trace.h
HEADERS += test_ansi.h
HEADERS += strlen_test.h
HEADERS += language/strlen.h
    HEADERS += string_test.h \
    ../src/language/string_literal.h \
    ../src/language/stl_tests.h \
    ../src/language/stl.h \
    ../src/language/std_qsort.h \
    ../src/language/stdouttest.h \
    ../src/language/std_map.h \
    ../src/language/static_cast.h \
    ../src/language/stack_container.h \
    ../src/language/smartptr_test.h \
    ../src/language/smart_ptr_test.h \
    ../src/language/sizeof_test.h \
    ../src/language/sizeof_class.h \
    ../src/language/sizeof.h \
    ../src/language/set_test.h \
    ../src/language/que_test.h \
    ../src/language/put_char.h \
    ../src/language/pure_virtual_call.h \
    ../src/language/ptr_test.h \
    ../src/language/private_constructor.h \
    ../src/language/printf_test.h \
    ../src/language/prefix_postfix_test.h \
    ../src/language/pointer_as_param.h \
    ../src/language/pointer_2_function.h \
    ../src/language/own_sizeof.h \
    ../src/language/ostream_change.h \
    ../src/language/operator_cast_2.h \
    ../src/language/operator_cast.h \
    ../src/language/namespace_test.h \
    ../src/language/my_stack.h \
    ../src/language/my_queue.h \
    ../src/language/my_limits.h \
    ../src/language/my_header.h \
    ../src/language/my_deque.h \
    ../src/language/mutex_wrap.h \
    ../src/language/multition.h \
    ../src/language/ms_test_3.h \
    ../src/language/ms_strtoi.h \
    ../src/language/ms_nth_node_test.h \
    ../src/language/ms_itoa_3.h \
    ../src/language/method_hiding.h \
    ../src/language/loop_in_switch.h \
    ../src/language/lock_test_1.h \
    ../src/language/list_find.h \
    ../src/language/last_include_index.h \
    ../src/language/language.h \
    ../src/language/ItoaTest.h \
    ../src/language/itoa_test.h \
    ../src/language/iterator.h \
    ../src/language/istringstream.h \
    ../src/language/io_tests.h \
    ../src/language/intialization_test.h \
    ../src/language/int_2_bin.h \
    ../src/language/inner_outer.h \
    ../src/language/initialization_with_this.h \
    ../src/language/initialization_list.h \
    ../src/language/inheritance.h \
    ../src/language/huge_val_duoble.h \
    ../src/language/huge_val.h \
    ../src/language/goto_.h \
    ../src/language/generic_list_test.h \
    ../src/language/functions_test.h \
    ../src/language/function_pointers.h \
    ../src/language/function_parameter.h \
    ../src/language/find_loop_in_slist.h \
    ../src/language/explicit_ctor.h \
    ../src/language/exception_test.h \
    ../src/language/exception_in_destructor.h \
#    ../src/language/errno.h \
    ../src/language/embar_test.h \
    ../src/language/dynamic_cast.h \
    ../src/language/dino_test.h \
    ../src/language/delete.h \
    ../src/language/db_test.h \
    ../src/language/ctor_test.h \
    ../src/language/cout.h \
    ../src/language/const_test.h \
    ../src/language/constructor_exception.h \
    ../src/language/const_method.h \
    ../src/language/const_const.h \
    ../src/language/const_char_test.h \
    ../src/language/condition_x_0_or_1.h \
    ../src/language/class_initialization.h \
    ../src/language/char_array.h \
    ../src/language/cast_2.h \
    ../src/language/cast_1.h \
    ../src/language/brainbench_2.h \
    ../src/language/brainbench_1.h \
    ../src/language/blo.h \
    ../src/language/bits_arithmetic.h \
    ../src/language/binder2nd.h \
    ../src/language/binder1st.h \
    ../src/language/bind2nd.h \
    ../src/language/bind1st.h \
    ../src/language/binary.h \
    ../src/lock-free/lock_free1.h \
    ../src/lock-free/lock_free.h \
    ../src/patterns/visitor_templ.h \
    ../src/patterns/visitor_2.h \
    ../src/patterns/visitor.h \
    ../src/patterns/template_method.h \
    ../src/patterns/strategy.h \
    ../src/patterns/state.h \
    ../src/patterns/resource_acquisition_is_initialization.h \
    ../src/patterns/ProxyPatternTest.h \
    ../src/patterns/proxy.h \
    ../src/patterns/prototype.h \
    ../src/patterns/profiler.h \
    ../src/patterns/patterns.h \
    ../src/patterns/observer_test.h \
    ../src/patterns/observer.h \
    ../src/patterns/null_object.h \
    ../src/patterns/memento.h \
    ../src/patterns/mediator.h \
    ../src/patterns/lazy_initialization.h \
    ../src/patterns/interpreter.h \
    ../src/patterns/flyweight.h \
    ../src/patterns/factory_method.h \
    ../src/patterns/facade.h \
    ../src/patterns/decorator.h \
    ../src/patterns/composite.h \
    ../src/patterns/command.h \
    ../src/patterns/chain_of_responsibility.h \
    ../src/patterns/builder.h \
    ../src/patterns/bridge.h \
    ../src/patterns/adapter.h \
    ../src/patterns/abstract_factory.h
HEADERS += functors.h
HEADERS += tree_traversal.h
HEADERS += sum_1_to_N.h
HEADERS += substr_search.h
HEADERS += string_unique_chars.h
HEADERS += square_root.h
HEADERS += singleton_with_mutex.h
HEADERS += singleton.h
HEADERS += search_test.h
HEADERS += revert_slist.h
HEADERS += reverse_words_in_sentense.h
HEADERS += reverse_string_1.h
HEADERS += reverse_string.h
HEADERS += reverse_sentense.h
HEADERS += reverse_llist_1.h
HEADERS += reverse_llist.h
HEADERS += reverse_linked_list_old.h
HEADERS += reverse_linked_list2.h
HEADERS += reverse_linked_list.h
HEADERS += reverse_integer.h
HEADERS += reverse_chars2.h
HEADERS += reverse_chars.h \
    repeat_number_in_array.h \
    remove_substr_in_str.h \
    remove_Nth_from_dlist.h \
    remove_from_list.h \
    remove_elem_from_dlist.h \
    radixsort.h \
    quicksort.h \
    power_of_two_2.h \
    power_of_two.h \
    power_of_2.h \
    power_of2_2.h \
    power_of2.h \
    palindrom_rec.h \
    palindrome.h \
    num_to_str.h \
    my_atoi.h \
    multiply_by_7.h \
    multiply_7.h \
    merge_sort_linked_list.h \
    merge_sort.h \
    insertsort.h \
    insert_into_sorted_list.h \
    heapsort.h \
    google_test.h \
    free_linked_list.h \
    find_largest_sum_in_array.h \
    fibbonachi.h \
    encode_string_google2.h \
    encode_string_google.h \
    duplication.h \
    drawcircle.h \
    dining_philosophers.h \
    count_1_in_binary.h \
    compare_linked_list.h \
    common_data.h \
    circular_que.h \
    byte_array_2_string.h \
    bubblesort.h \
    btree_depth.h \
    big_little_endian.h \
    array_find_duplicates.h \
    array_characters_reverse.h \
    algoritms/algoritms.h
HEADERS += cpp0x.h
HEADERS += cracking.h
HEADERS += func.h

#virtuals
HEADERS += virtuals.h
HEADERS += virt_access.h
HEADERS += virt_cast_1.h
HEADERS += virt_cast_2.h
HEADERS += virt_func_1.h
HEADERS += virt_func_2.h
HEADERS += virt_func_3.h
HEADERS += virt_func_4.h
HEADERS += virt_func_5.h
HEADERS += virt_func_6.h
HEADERS += virt_func_7.h
HEADERS += virt_func_8.h
HEADERS += virt_func_9.h


SOURCES += main.cpp
