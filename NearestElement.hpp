auto greater_than_equal_right = [&](int x, int id, int st_sz) {
    /*
    Instructions : 
                *> Create MAX segtree on the vector[v] you want to search
                *> returns if there exist a i such that i >= id ans v[i] >= x, O.W returns -1
                *> CONDITION -> ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    */

    target = x;
    auto i = st.max_right(id, f); // 'st' used !

    return (i == st_sz ? -1ll : i);
};




auto less_than_equal_right = [&](int x, int id, int st_sz) {
    /*
    Instructions :
                *> Create MAX segtree on the negative of the vector[v] you want to search
                *> returns if there exist a i such that i >= id ans v[i] <= x, O.W returns -1
                *> CONDITION -> ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    */
    target = -x;
    auto i = st_neg.max_right(id, f); // 'st_neg' used !

    return (i == st_sz ? -1ll : i);
};



auto greater_than_equal_left = [&](int x, int id, int st_sz) {
    /*
    Instructions :
                *> Create MAX segtree on the reverse of the vector[v] you want to search
                *> returns if there exist a i such that i <= id ans v[i] >= x, O.W returns -1
                *> CONDITION -> ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    */
    target = x;
    id = st_sz - id - 1;
    auto i = st_rev.max_right(id, f);// 'st_rev' used !

    return (i == st_sz ? -1ll : st_sz - 1 - i); // st_sz == n  -> size of the array??
};



auto less_than_equal_left = [&](int x, int id, int st_sz) {
    /*
    Instructions : 
                 *> Create MAX segtree on the reverse of negative of the vector[v] you want to search
                 *> returns if there exist a i such that i <= id ans v[i] <= x, O.W returns -1
                 *> CONDITION -> ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    */
    target = -x;
    id = st_sz - id - 1;
    auto i = st_rev_neg.max_right(id, f);// 'st_rev_neg' used !
    return (i == st_sz ? -1ll : st_sz - 1 - i); // st_sz == n  -> size of the array ??
};
