//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2023.02
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2023-2023 Seityagiya Terlekchi. All rights reserved.

#include "test.h"
#include "yaya_arithmetic.h"

UT_FUNC_GEN(test_arithmetic_unar) {
    UT_GROUP_BEG(unar) {
        is8_t x = 0;
        UT_ASSERT_NUM_EQ(i8_c(0), x);
        UT_ASSERT_NUM_EQ(i8_c(0), post_add(x));
        UT_ASSERT_NUM_EQ(i8_c(1), post_add(x));
        UT_ASSERT_NUM_EQ(i8_c(2), x);
        UT_ASSERT_NUM_EQ(i8_c(2), post_dif(x));
        UT_ASSERT_NUM_EQ(i8_c(1), post_dif(x));
        UT_ASSERT_NUM_EQ(i8_c(0), x);

        x = 127;
        UT_ASSERT_NUM_EQ(i8_c( 127), post_add(x));
        UT_ASSERT_NUM_EQ(i8_c(-128), post_add(x));

        x = 0;
        UT_ASSERT_NUM_EQ(i8_c(0), x);
        UT_ASSERT_NUM_EQ(i8_c(1), sum(post_add(x), post_add(x)));
        UT_ASSERT_NUM_EQ(i8_c(5), sum(post_add(x), post_add(x)));
        UT_ASSERT_NUM_EQ(i8_c(4), x);
        UT_ASSERT_NUM_EQ(i8_c(7), sum(post_dif(x), post_dif(x)));
        UT_ASSERT_NUM_EQ(i8_c(3), sum(post_dif(x), post_dif(x)));
        UT_ASSERT_NUM_EQ(i8_c(0), x);

        x = 0;
        UT_ASSERT_NUM_EQ(i8_c(0), x);
        UT_ASSERT_NUM_EQ(i8_c(1), pref_add(x));
        UT_ASSERT_NUM_EQ(i8_c(2), pref_add(x));
        UT_ASSERT_NUM_EQ(i8_c(2), x);
        UT_ASSERT_NUM_EQ(i8_c(1), pref_dif(x));
        UT_ASSERT_NUM_EQ(i8_c(0), pref_dif(x));
        UT_ASSERT_NUM_EQ(i8_c(0), x);

        x = 0;
        UT_ASSERT_NUM_EQ(i8_c(0), x);
        UT_ASSERT_NUM_EQ(i8_c(3), sum(pref_add(x), pref_add(x)));
        UT_ASSERT_NUM_EQ(i8_c(7), sum(pref_add(x), pref_add(x)));
        UT_ASSERT_NUM_EQ(i8_c(4), x);
        UT_ASSERT_NUM_EQ(i8_c(5), sum(pref_dif(x), pref_dif(x)));
        UT_ASSERT_NUM_EQ(i8_c(1), sum(pref_dif(x), pref_dif(x)));
        UT_ASSERT_NUM_EQ(i8_c(0), x);
    }UT_GROUP_END;
}
