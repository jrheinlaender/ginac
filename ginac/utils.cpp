/** @file utils.cpp
 *
 *  Implementation of several small and furry utilities needed within GiNaC
 *  but not of any interest to the user of the library. */

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

#include "ex.h"
#include "numeric.h"
#include "utils.h"

#ifndef NO_GINAC_NAMESPACE
namespace GiNaC {
#endif // ndef NO_GINAC_NAMESPACE

/** Integer binary logarithm */
unsigned log2(unsigned n)
{
    unsigned k;
    for (k = 0; n > 1; n >>= 1) ++k;
    return k;
}

/** Compare two pointers (just to establish some sort of canonical order).
 *  @return -1, 0, or 1 */
int compare_pointers(void const * a, void const * b)
{
    if (a<b) {
        return -1;
    } else if (a>b) {
        return 1;
    }
    return 0;
}

//////////
// `construct on first use' chest of numbers
//////////

// numeric -12
numeric const & _num_12(void)
{
    const static ex e = ex(numeric(-12));
    const static numeric * n = static_cast<const numeric *>(e.bp);
    return *n;
}

ex const & _ex_12(void)
{
    static ex * e = new ex(_num_12());
    return *e;
}

// numeric -11
numeric const & _num_11(void)
{
    const static ex e = ex(numeric(-11));
    const static numeric * n = static_cast<const numeric *>(e.bp);
    return *n;
}

ex const & _ex_11(void)
{
    static ex * e = new ex(_num_11());
    return *e;
}

// numeric -10
numeric const & _num_10(void)
{
    const static ex e = ex(numeric(-10));
    const static numeric * n = static_cast<const numeric *>(e.bp);
    return *n;
}

ex const & _ex_10(void)
{
    static ex * e = new ex(_num_10());
    return *e;
}

// numeric -9
numeric const & _num_9(void)
{
    const static ex e = ex(numeric(-9));
    const static numeric * n = static_cast<const numeric *>(e.bp);
    return *n;
}

ex const & _ex_9(void)
{
    static ex * e = new ex(_num_9());
    return *e;
}

// numeric -8
numeric const & _num_8(void)
{
    const static ex e = ex(numeric(-8));
    const static numeric * n = static_cast<const numeric *>(e.bp);
    return *n;
}

ex const & _ex_8(void)
{
    static ex * e = new ex(_num_8());
    return *e;
}

// numeric -7
numeric const & _num_7(void)
{
    const static ex e = ex(numeric(-7));
    const static numeric * n = static_cast<const numeric *>(e.bp);
    return *n;
}

ex const & _ex_7(void)
{
    static ex * e = new ex(_num_7());
    return *e;
}

// numeric -6
numeric const & _num_6(void)
{
    const static ex e = ex(numeric(-6));
    const static numeric * n = static_cast<const numeric *>(e.bp);
    return *n;
}

ex const & _ex_6(void)
{
    static ex * e = new ex(_num_6());
    return *e;
}

// numeric -5
numeric const & _num_5(void)
{
    const static ex e = ex(numeric(-5));
    const static numeric * n = static_cast<const numeric *>(e.bp);
    return *n;
}

ex const & _ex_5(void)
{
    static ex * e = new ex(_num_5());
    return *e;
}

// numeric -4
numeric const & _num_4(void)
{
    const static ex e = ex(numeric(-4));
    const static numeric * n = static_cast<const numeric *>(e.bp);
    return *n;
}

ex const & _ex_4(void)
{
    static ex * e = new ex(_num_4());
    return *e;
}

// numeric -3
numeric const & _num_3(void)
{
    const static ex e = ex(numeric(-3));
    const static numeric * n = static_cast<const numeric *>(e.bp);
    return *n;
}

ex const & _ex_3(void)
{
    static ex * e = new ex(_num_3());
    return *e;
}

// numeric -2
numeric const & _num_2(void)
{
    const static ex e = ex(numeric(-2));
    const static numeric * n = static_cast<const numeric *>(e.bp);
    return *n;
}

ex const & _ex_2(void)
{
    static ex * e = new ex(_num_2());
    return *e;
}

// numeric -1
numeric const & _num_1(void)
{
    const static ex e = ex(numeric(-1));
    const static numeric * n = static_cast<const numeric *>(e.bp);
    return *n;
}

ex const & _ex_1(void)
{
    static ex * e = new ex(_num_1());
    return *e;
}

// numeric -1/2
numeric const & _num_1_2(void)
{
    const static ex e = ex(numeric(-1,2));
    const static numeric * n = static_cast<const numeric *>(e.bp);
    return *n;
}

ex const & _ex_1_2(void)
{
    static ex * e = new ex(_num_1_2());
    return *e;
}    

// numeric -1/3
numeric const & _num_1_3(void)
{
    const static ex e = ex(numeric(-1,3));
    const static numeric * n = static_cast<const numeric *>(e.bp);
    return *n;
}

ex const & _ex_1_3(void)
{
    static ex * e = new ex(_num_1_3());
    return *e;
}    

// numeric  0
numeric const & _num0(void)
{
    const static ex e = ex(numeric(0));
    const static numeric * n = static_cast<const numeric *>(e.bp);
    return *n;
}

ex const & _ex0(void)
{
    static ex * e = new ex(_num0());
    return *e;
}

// numeric  1/3
numeric const & _num1_3(void)
{
    const static ex e = ex(numeric(1,3));
    const static numeric * n = static_cast<const numeric *>(e.bp);
    return *n;
}

ex const & _ex1_3(void)
{
    static ex * e = new ex(_num1_3());
    return *e;
}    

// numeric  1/2
numeric const & _num1_2(void)
{
    const static ex e = ex(numeric(1,2));
    const static numeric * n = static_cast<const numeric *>(e.bp);
    return *n;
}

ex const & _ex1_2(void)
{
    static ex * e = new ex(_num1_2());
    return *e;
}    

// numeric  1
numeric const & _num1(void)
{
    const static ex e = ex(numeric(1));
    const static numeric * n = static_cast<const numeric *>(e.bp);
    return *n;
}

ex const & _ex1(void)
{
    static ex * e = new ex(_num1());
    return *e;
}

// numeric  2
numeric const & _num2(void)
{
    const static ex e = ex(numeric(2));
    const static numeric * n = static_cast<const numeric *>(e.bp);
    return *n;
}

ex const & _ex2(void)
{
    static ex * e = new ex(_num2());
    return *e;
}

// numeric  3
numeric const & _num3(void)
{
    const static ex e = ex(numeric(3));
    const static numeric * n = static_cast<const numeric *>(e.bp);
    return *n;
}

ex const & _ex3(void)
{
    static ex * e = new ex(_num3());
    return *e;
}

// numeric  4
numeric const & _num4(void)
{
    const static ex e = ex(numeric(4));
    const static numeric * n = static_cast<const numeric *>(e.bp);
    return *n;
}

ex const & _ex4(void)
{
    static ex * e = new ex(_num4());
    return *e;
}

// numeric  5
numeric const & _num5(void)
{
    const static ex e = ex(numeric(5));
    const static numeric * n = static_cast<const numeric *>(e.bp);
    return *n;
}

ex const & _ex5(void)
{
    static ex * e = new ex(_num5());
    return *e;
}

// numeric  6
numeric const & _num6(void)
{
    const static ex e = ex(numeric(6));
    const static numeric * n = static_cast<const numeric *>(e.bp);
    return *n;
}

ex const & _ex6(void)
{
    static ex * e = new ex(_num6());
    return *e;
}

// numeric  7
numeric const & _num7(void)
{
    const static ex e = ex(numeric(7));
    const static numeric * n = static_cast<const numeric *>(e.bp);
    return *n;
}

ex const & _ex7(void)
{
    static ex * e = new ex(_num7());
    return *e;
}

// numeric  8
numeric const & _num8(void)
{
    const static ex e = ex(numeric(8));
    const static numeric * n = static_cast<const numeric *>(e.bp);
    return *n;
}

ex const & _ex8(void)
{
    static ex * e = new ex(_num8());
    return *e;
}

// numeric  9
numeric const & _num9(void)
{
    const static ex e = ex(numeric(9));
    const static numeric * n = static_cast<const numeric *>(e.bp);
    return *n;
}

ex const & _ex9(void)
{
    static ex * e = new ex(_num9());
    return *e;
}

// numeric  10
numeric const & _num10(void)
{
    const static ex e = ex(numeric(10));
    const static numeric * n = static_cast<const numeric *>(e.bp);
    return *n;
}

ex const & _ex10(void)
{
    static ex * e = new ex(_num10());
    return *e;
}

// numeric  11
numeric const & _num11(void)
{
    const static ex e = ex(numeric(11));
    const static numeric * n = static_cast<const numeric *>(e.bp);
    return *n;
}

ex const & _ex11(void)
{
    static ex * e = new ex(_num11());
    return *e;
}

// numeric  12
numeric const & _num12(void)
{
    const static ex e = ex(numeric(12));
    const static numeric * n = static_cast<const numeric *>(e.bp);
    return *n;
}

ex const & _ex12(void)
{
    static ex * e = new ex(_num12());
    return *e;
}

// comment skeleton for header files


// member functions

    // default constructor, destructor, copy constructor assignment operator and helpers
    // none

    // other constructors
    // none

    // functions overriding virtual functions from bases classes
    // none
    
    // new virtual functions which can be overridden by derived classes
    // none

    // non-virtual functions in this class
    // none

// member variables
// none
    


// comment skeleton for implementation files


//////////
// default constructor, destructor, copy constructor assignment operator and helpers
//////////

// public
// protected

//////////
// other constructors
//////////

// public
// none

//////////
// functions overriding virtual functions from bases classes
//////////

// public
// protected
// none

//////////
// new virtual functions which can be overridden by derived classes
//////////

// public
// protected
// none

//////////
// non-virtual functions in this class
//////////

// public
// protected
// none

//////////
// static member variables
//////////

// protected
// private
// none


#ifndef NO_GINAC_NAMESPACE
} // namespace GiNaC
#endif // ndef NO_GINAC_NAMESPACE
