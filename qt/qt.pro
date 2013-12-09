TEMPLATE = app
CONFIG += console
CONFIG -= qt

DEPENDPATH += ../src/virtuals/

#DEFINES += -MD

LIBS += -lpthread
LIBS += /usr/lib/libboost_thread.a
LIBS += /usr/lib/libboost_system.a

INCLUDEPATH += ../src/algoritms/
INCLUDEPATH += ../src/boost/
#INCLUDEPATH += ../src/cpp0x/
INCLUDEPATH += ../src/cracking_code_interview/
INCLUDEPATH += ../src/func/
INCLUDEPATH += ../src/virtual/
HEADERS += boosts.h
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
