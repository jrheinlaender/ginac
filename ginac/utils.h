/** @file utils.h
 *
 *  Interface to several small and furry utilities needed within GiNaC but not
 *  of any interest to the user of the library. */

/*
 *  GiNaC Copyright (C) 1999 Johannes Gutenberg University Mainz, Germany
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __GINAC_UTILS_H__
#define __GINAC_UTILS_H__

#include <strstream>
#include <string>
#include "config.h"
#include "assertion.h"

#ifndef NO_GINAC_NAMESPACE
namespace GiNaC {
#endif // ndef NO_GINAC_NAMESPACE

template<class T>
string ToString(T const & t)
{
    char buf[256];
    ostrstream(buf,sizeof(buf)) << t << ends;
    return buf;
}

/** Exception thrown by classes which provide their own series expansion to
 *  signal that ordinary Taylor expansion is safe. */
class do_taylor {};

unsigned log2(unsigned n);

int compare_pointers(void const * a, void const * b);

/** Rotate lower 31 bits of unsigned value by one bit to the left
 *  (upper bits get cleared). */
inline unsigned rotate_left_31(unsigned n)
{
    // clear highest bit and shift 1 bit to the left
    n=(n & 0x7FFFFFFFU) << 1;

    // overflow? clear highest bit and set lowest bit
    if (n & 0x80000000U) {
        n=(n & 0x7FFFFFFFU) | 0x00000001U;
    }
    GINAC_ASSERT(n<0x80000000U);

    return n;
}

/** Golden ratio hash function. */
inline unsigned golden_ratio_hash(unsigned n)
{
	// This function requires arithmetic with at least 64 significant bits
#if SIZEOF_LONG_DOUBLE > 8
	// If "long double" is bigger than 64 bits, we assume that the mantissa
	// has at least 64 bits. This is not guaranteed but it's a good guess.
    const static long double golden_ratio = .618033988749894848204586834370;
    long double m = golden_ratio * n;
    return unsigned((m - int(m)) * 0x80000000);
#elif SIZEOF_LONG >= 8
	// "long" has 64 bits, so we prefer it because it might be more efficient
	// than "long long"
	unsigned long l = n * 0x4f1bbcddL;
	return (l & 0x7fffffffU) ^ (l >> 32);
#elif SIZEOF_LONG_LONG >= 8
	// This requires �long long� (or an equivalent 64 bit type)---which is,
    // unfortunately, not ANSI-compliant:
	unsigned long long l = n * 0x4f1bbcddLL;
	return (l & 0x7fffffffU) ^ (l >> 32);
#else
#error "No 64 bit data type. You lose."
#endif
}

// modified from stl_algo.h: always do com(*first1,*first2) instead of comp(*first2,*first1)
template <class InputIterator1, class InputIterator2, class OutputIterator,
          class Compare>
OutputIterator mymerge(InputIterator1 first1, InputIterator1 last1,
                       InputIterator2 first2, InputIterator2 last2,
                       OutputIterator result, Compare comp) {
    while (first1 != last1 && first2 != last2) {
        if (comp(*first1, *first2)) {
            *result = *first1;
            ++first1;
        }
        else {
            *result = *first2;
            ++first2;
        }
        ++result;
    }
    return copy(first2, last2, copy(first1, last1, result));
}

// like merge(), but three lists with *last2<*first3
template <class InputIterator1, class InputIterator2, class InputIterator3,
          class OutputIterator, class Compare>
OutputIterator mymerge3(InputIterator1 first1, InputIterator1 last1,
                        InputIterator2 first2, InputIterator2 last2,
                        InputIterator3 first3, InputIterator3 last3,
                        OutputIterator result, Compare comp) {
    while (first1 != last1 && first2 != last2) {
        if (comp(*first1, *first2)) {
            *result = *first1;
            ++first1;
        }
        else {
            *result = *first2;
            ++first2;
        }
        ++result;
    }
    
    if (first1==last1) {
        // list1 empty, copy rest of list2, then list3
        return copy(first3, last3, copy(first2, last2, result));
    } else {
        // list2 empty, merge rest of list1 with list3
        return mymerge(first1,last1,first3,last3,result,comp);
    }
}

// Collection of `construct on first use' wrappers for safely avoiding
// internal object replication without running into the `static
// initialization order fiasco'.  This chest of numbers helps speed up
// the library but should not be used outside it since it is
// potentially confusing.

class numeric;
class ex;
                       
numeric const & _num_12(void);    // -12
numeric const & _num_11(void);    // -11
numeric const & _num_10(void);    // -10
numeric const & _num_9(void);     // -9
numeric const & _num_8(void);     // -8
numeric const & _num_7(void);     // -7
numeric const & _num_6(void);     // -6
numeric const & _num_5(void);     // -5
numeric const & _num_4(void);     // -4
numeric const & _num_3(void);     // -3
numeric const & _num_2(void);     // -2
numeric const & _num_1(void);     // -1
numeric const & _num_1_2(void);   // -1/2
numeric const & _num_1_3(void);   // -1/3
numeric const & _num0(void);      //  0
numeric const & _num1_3(void);    //  1/3
numeric const & _num1_2(void);    //  1/2
numeric const & _num1(void);      //  1
numeric const & _num2(void);      //  2
numeric const & _num3(void);      //  3
numeric const & _num4(void);      //  4
numeric const & _num5(void);      //  5
numeric const & _num6(void);      //  6
numeric const & _num7(void);      //  7
numeric const & _num8(void);      //  8
numeric const & _num9(void);      //  9
numeric const & _num10(void);     //  10
numeric const & _num11(void);     //  11
numeric const & _num12(void);     //  12
ex const & _ex_12(void);          // -12
ex const & _ex_11(void);          // -11
ex const & _ex_10(void);          // -10
ex const & _ex_9(void);           // -9
ex const & _ex_8(void);           // -8
ex const & _ex_7(void);           // -7
ex const & _ex_6(void);           // -6
ex const & _ex_5(void);           // -5
ex const & _ex_4(void);           // -4
ex const & _ex_3(void);           // -3
ex const & _ex_2(void);           // -2
ex const & _ex_1(void);           // -1
ex const & _ex_1_2(void);         // -1/2
ex const & _ex_1_3(void);         // -1/3
ex const & _ex0(void);            //  0
ex const & _ex1_3(void);          //  1/3
ex const & _ex1_2(void);          //  1/2
ex const & _ex1(void);            //  1
ex const & _ex2(void);            //  2
ex const & _ex3(void);            //  3
ex const & _ex4(void);            //  4
ex const & _ex5(void);            //  5
ex const & _ex6(void);            //  6
ex const & _ex7(void);            //  7
ex const & _ex8(void);            //  8
ex const & _ex9(void);            //  9
ex const & _ex10(void);           //  10
ex const & _ex11(void);           //  11
ex const & _ex12(void);           //  12

#ifndef NO_GINAC_NAMESPACE
} // namespace GiNaC
#endif // ndef NO_GINAC_NAMESPACE

#endif // ndef __GINAC_UTILS_H__
