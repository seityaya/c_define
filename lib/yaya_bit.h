///Author                 : Seityagiya Terlekchi
///Contacts               : seityaya@ukr.net
///Creation Date          : 2020.05
///License Link           : https: spdx.org/licenses/LGPL-2.1-or-later.html
///SPDX-License-Identifier: LGPL-2.1-or-later
///Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_BIT_H
#define YAYA_BIT_H

#include "yaya_cdeclaration.h"
BEG_C_DECLARATION

#include "limits.h"
#include "stddef.h"

#include "yaya_number.h"
#include "yaya_chek.h"

/*
 * В данных операциях биты нумеруются с 1, если указан 0, то изменений не происходит
 * Если функция возвращает результат, то он тоже нумерует биты c 1
*/

/* = ОПРЕДЕЛЕНИЕ ФУНКЦИЙ ========================================================================================================================== */

imax_t ___bit_0_beg(umax_t x, umax_t s);
imax_t ___bit_0_end(umax_t x, umax_t s);
imax_t ___bit_0_cnt(umax_t x, umax_t s);
imax_t ___bit_0_pos(umax_t x, umax_t s);

imax_t ___bit_1_beg(umax_t x);
imax_t ___bit_1_end(umax_t x);
imax_t ___bit_1_cnt(umax_t x);
imax_t ___bit_1_pos(umax_t x);

umax_t ___bit_revers(umax_t x, umax_t s);
umax_t ___bit_sequence(void *ptr, umax_t offset, umax_t len);

/* = ПОДСЧЕТ И ПОИСК БИТОВ ======================================================================================================================== */

/*
 * Возвращет количество битов в числе
*/
#define bit_cnt(x)        typecast(umax_t, sizeof(x) * CHAR_BIT)

/*
 * Опустить все биты в 0
*/
#define bit_0_all(x)      typecast((x), umax_c(0))

/*
 * Вернуть позицию первого опущеного бита
*/
#define bit_0_beg(x)      ___bit_0_beg((umax_t)(x), sizeof(x))

/*
 * Вернуть позицию последнего опущеного бита
*/
#define bit_0_end(x)      ___bit_0_end((umax_t)(x), sizeof(x))

/*
 * Подсчитать количество опущеных битов
*/
#define bit_0_cnt(x)      ___bit_0_cnt((umax_t)(x), sizeof(x))

/*
 * Вернуть позицию одного опущенного бита, если битов несколько, то -1
*/
#define bit_0_pos(x)      ___bit_0_pos((umax_t)(x), sizeof(x))

/*
 * Поднять все биты в 1
*/
#define bit_1_all(x)      typecast((x), (umax_c(0) - umax_c(1)))

/*
 * Вернуть позицию первого взведенного бита
*/
#define bit_1_beg(x)      ___bit_1_beg((umax_t)(x))

/*
 * Вернуть позицию последнего взведенного бита
*/
#define bit_1_end(x)      ___bit_1_end((umax_t)(x))

/*
 * Подсчитать количество взведенных битов
*/
#define bit_1_cnt(x)      ___bit_1_cnt((umax_t)(x))

/*
 * Вернуть позицию одного единичного бита, если битов несколько, то -1
*/
#define bit_1_pos(x)      ___bit_1_pos((umax_t)(x))

/* = ВЫСТАВЛЕНИЕ И ВОЗВРАТ БИТОВ ================================================================================================================== */

/*
 * Чтение бита на позии
*/
#define bit_get(x, n)    typecast((x), (n) == (0) ? typecast((x), (0)) : typecast((x), (typecast(umax_t, x) &  (typecast(umax_t, 1) << ((typecast(umax_t, n) - 1) % bit_cnt(x))))))

/*
 * Выставление бита  на позии
*/
#define bit_set(x, n)    typecast((x), (n) == (0) ? typecast((x), (x)) : typecast((x), (typecast(umax_t, x) |  (typecast(umax_t, 1) << ((typecast(umax_t, n) - 1) % bit_cnt(x))))))

/*
 * Сброс бита на позии
*/
#define bit_res(x, n)    typecast((x), (n) == (0) ? typecast((x), (x)) : typecast((x), (typecast(umax_t, x) & ~(typecast(umax_t, 1) << ((typecast(umax_t, n) - 1) % bit_cnt(x))))))

/*
 * Переключение бита на позиции
*/
#define bit_tog(x, n)    typecast((x), (n) == (0) ? typecast((x), (x)) : typecast((x), (typecast(umax_t, x) ^  (typecast(umax_t, 1) << ((typecast(umax_t, n) - 1) % bit_cnt(x))))))

/*
 * Выставление определенного бита на позии
*/
#define bit_wrt(x, n, b) typecast((x), ((b) ? bit_set((x), (n)) : bit_res((x), (n))))

/*
 * Инверсия битов в числе
*/
#define bit_inv(x)       typecast((x), (~((umax_t)(x))))

/*
 * Смена порядка битов то начала к концу
*/
#define bit_rev(x)       typecast((x), ___bit_revers((x), sizeof(x)))

/*
 * Возвращает значение по смещению и длинне последовательности
*/
#define bit_seq(p, o, l) ___bit_sequence(p, o, l)

/* = БИТОВЫЕ СДВИГИ =============================================================================================================================== */

/*
 * Арифметический сдвиг вправо
*/
#define bit_ari_rig(x, n) typecast((x), typecast(umax_t, x) >> typecast(umax_t, n))

/*
 * Арифметический сдвиг влево
*/
#define bit_ari_lef(x, n) typecast((x), typecast(umax_t, x) << typecast(umax_t, n))

/*
 * Арифметический сдвиг относительно знака числа
 * +n - влево
 * -n - вправо
*/
#define bit_ari_vec(x, n) typecast((x), (n) < (0) ? bit_ari_rig((x), (-(n))) : bit_ari_lef((x), (n)))


/*
 * Логический сдвиг вправо
*/
#define bit_shf_rig(x, n) typecast((x), ((x) > (0)) || ((x) == (0)) || ((n) == (0)) ? \
    bit_ari_rig(x, n) : bit_set(bit_res(x, bit_cnt(x)) >> typecast(umax_t, n), bit_cnt(x) - n))

/*
 * Логический сдвиг влево
*/
#define bit_shf_lef(x, n) typecast((x), typecast(umax_t, x) << typecast(umax_t, n))

/*
 * Логический сдвиг относительно знака числа
         * +n - влево
         * -n - вправо
*/
#define bit_shf_vec(x, n) typecast((x), (n) < (0) ? bit_shf_rig((x), (-(n))) : bit_shf_lef((x), (n)))


/*
 * Циклический сдвиг вправо
*/
#define bit_cyc_rig(x, n) typecast((x), (n) == (0) ? (x) : ((x) >> ((n) % bit_cnt(x))) | ((x) << ((bit_cnt(x) - (n)) % (bit_cnt(x)))))

/*
 * Циклический сдвиг влево
*/
#define bit_cyc_lef(x, n) typecast((x), (n) == (0) ? (x) : ((x) << ((n) % bit_cnt(x))) | ((x) >> ((bit_cnt(x) - (n)) % (bit_cnt(x)))))

/*
 * Циклический сдвиг относительно знака числа
 * +n - влево
 * -n - вправо
*/
#define bit_cyc_vec(x, n) typecast((x), (n) < (0) ? bit_cyc_rig((x), (-(n))) : bit_cyc_lef((x), (n)))

/* = БИТОВЫЕ МАСКИ ================================================================================================================================ */

/*
 * Выставление битов по единичной маске
*/
#define bit_mask_up(x, y) COMPILE_WCHDOG_2((x), (y), _x, _y, ((_x) | (_y)))

/*
 * Обнуление битов по единичной маске
*/
#define bit_mask_dw(x, y) COMPILE_WCHDOG_2((x), (y), _x, _y, ((_x) & (_y)))

/* = БИТОВЫЕ ОПЕРРАЦИИ ============================================================================================================================ */

/*
 * Битовое НЕ
*/
#define bit_not(x)        (~(x))

/*
 * Битовое ИЛИ
*/
#define bit_or(x, y)      COMPILE_WCHDOG_2((x), (y), _x, _y, ((_x) | (_y)))

/*
 * Битовое И
*/
#define bit_and(x, y)     COMPILE_WCHDOG_2((x), (y), _x, _y, ((_x) & (_y)))

/*
 * Битовое ИСЛЮЧАЮЩЕЕ ИЛИ
 * (Операторы не равны)
*/
#define bit_xor(x, y)     COMPILE_WCHDOG_2((x), (y), _x, _y, ((_x) ^ (_y)))

/*
 * Битовое ИЛИ-НЕ
*/
#define bit_nor(x, y)     bit_not(bit_or((x), (y)))

/*
 * Битовое И-НЕ
*/
#define bit_nand(x, y)    bit_not(bit_and((x), (y)))

/*
 * Битовое ИСКЛЮЧАЮЩЕЕ ИЛИ-НЕ
*/
#define bit_xnor(x, y)    bit_not(bit_xor((x), (y)))

/* ================================================================================================================================================ */

END_C_DECLARATION
#endif /*YAYA_BIT_H*/
