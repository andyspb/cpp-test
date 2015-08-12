#ifndef CPP1X_SELECTION_SORT_H_
#define CPP1X_SELECTION_SORT_H_


namespace cpp1y_selection_sort {

template<class FwdIt, class Compare = std::less<>>
void selection_sort(FwdIt first, FwdIt last, Compare cmp = Compare{})
{
    for (auto it = first; it != last; ++it) {
        auto const selection = std::min_element(it, last, cmp);
        std::iter_swap(selection, it); 
        assert(std::is_sorted(first, std::next(it), cmp));
    }
}

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;

  RETURN_OK();
}


}  // namespace cpp1y_selection_sort

#endif
