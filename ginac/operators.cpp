/** @file operators.cpp
 *
 *  Implementation of GiNaC's overloaded operators. */

/*
 *  GiNaC Copyright (C) 1999-2000 Johannes Gutenberg University Mainz, Germany
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

#include <iostream>
#include <stdexcept>

#include "operators.h"
#include "basic.h"
#include "ex.h"
#include "numeric.h"
#include "power.h"
#include "relational.h"
#include "input_lexer.h"
#include "debugmsg.h"
#include "utils.h"

#ifndef NO_NAMESPACE_GINAC
namespace GiNaC {
#endif // ndef NO_NAMESPACE_GINAC

// binary arithmetic operators ex with ex

ex operator+(const ex & lh, const ex & rh)
{
    debugmsg("operator+(ex,ex)",LOGLEVEL_OPERATOR);
    return lh.exadd(rh);
}

ex operator-(const ex & lh, const ex & rh)
{
    debugmsg("operator-(ex,ex)",LOGLEVEL_OPERATOR);
    return lh.exadd(rh.exmul(_ex_1()));
}

ex operator*(const ex & lh, const ex & rh)
{
    debugmsg("operator*(ex,ex)",LOGLEVEL_OPERATOR);
    return lh.exmul(rh);
}

ex operator/(const ex & lh, const ex & rh)
{
    debugmsg("operator*(ex,ex)",LOGLEVEL_OPERATOR);
    return lh.exmul(power(rh,_ex_1()));
}

ex operator%(const ex & lh, const ex & rh)
{
    debugmsg("operator%(ex,ex)",LOGLEVEL_OPERATOR);
    return lh.exncmul(rh);
}


// binary arithmetic operators numeric with numeric

numeric operator+(const numeric & lh, const numeric & rh)
{
    debugmsg("operator+(numeric,numeric)",LOGLEVEL_OPERATOR);
    return lh.add(rh);
}

numeric operator-(const numeric & lh, const numeric & rh)
{
    debugmsg("operator-(numeric,numeric)",LOGLEVEL_OPERATOR);
    return lh.sub(rh);
}

numeric operator*(const numeric & lh, const numeric & rh)
{
    debugmsg("operator*(numeric,numeric)",LOGLEVEL_OPERATOR);
    return lh.mul(rh);
}

numeric operator/(const numeric & lh, const numeric & rh)
{
    debugmsg("operator/(numeric,ex)",LOGLEVEL_OPERATOR);
    return lh.div(rh);
}


// binary arithmetic assignment operators with ex

const ex & operator+=(ex & lh, const ex & rh)
{
    debugmsg("operator+=(ex,ex)",LOGLEVEL_OPERATOR);
    return (lh=lh+rh);
}

const ex & operator-=(ex & lh, const ex & rh)
{
    debugmsg("operator-=(ex,ex)",LOGLEVEL_OPERATOR);
    return (lh=lh-rh);
}

const ex & operator*=(ex & lh, const ex & rh)
{
    debugmsg("operator*=(ex,ex)",LOGLEVEL_OPERATOR);
    return (lh=lh*rh);
}

const ex & operator/=(ex & lh, const ex & rh)
{
    debugmsg("operator/=(ex,ex)",LOGLEVEL_OPERATOR);
    return (lh=lh/rh);
}

const ex & operator%=(ex & lh, const ex & rh)
{
    debugmsg("operator%=(ex,ex)",LOGLEVEL_OPERATOR);
    return (lh=lh%rh);
}


// binary arithmetic assignment operators with numeric

const numeric & operator+=(numeric & lh, const numeric & rh)
{
    debugmsg("operator+=(numeric,numeric)",LOGLEVEL_OPERATOR);
    return (lh=lh.add(rh));
}

const numeric & operator-=(numeric & lh, const numeric & rh)
{
    debugmsg("operator-=(numeric,numeric)",LOGLEVEL_OPERATOR);
    return (lh=lh.sub(rh));
}

const numeric & operator*=(numeric & lh, const numeric & rh)
{
    debugmsg("operator*=(numeric,numeric)",LOGLEVEL_OPERATOR);
    return (lh=lh.mul(rh));
}

const numeric & operator/=(numeric & lh, const numeric & rh)
{
    debugmsg("operator/=(numeric,numeric)",LOGLEVEL_OPERATOR);
    return (lh=lh.div(rh));
}

// unary operators

ex operator+(const ex & lh)
{
    return lh;
}

ex operator-(const ex & lh)
{
    return lh.exmul(_ex_1());
}

numeric operator+(const numeric & lh)
{
    return lh;
}

numeric operator-(const numeric & lh)
{
    return _num_1()*lh;
}

/** Numeric prefix increment.  Adds 1 and returns incremented number. */
numeric& operator++(numeric & rh)
{
    rh = rh+_num1();
    return rh;
}

/** Numeric prefix decrement.  Subtracts 1 and returns decremented number. */
numeric& operator--(numeric & rh)
{
    rh = rh-_num1();
    return rh;
}

/** Numeric postfix increment.  Returns the number and leaves the original
 *  incremented by 1. */
numeric operator++(numeric & lh, int)
{
    numeric tmp = lh;
    lh = lh+_num1();
    return tmp;
}

/** Numeric Postfix decrement.  Returns the number and leaves the original
 *  decremented by 1. */
numeric operator--(numeric & lh, int)
{
    numeric tmp = lh;
    lh = lh-_num1();
    return tmp;
}

// binary relational operators ex with ex

relational operator==(const ex & lh, const ex & rh)
{
    debugmsg("operator==(ex,ex)",LOGLEVEL_OPERATOR);
    return relational(lh,rh,relational::equal);
}

relational operator!=(const ex & lh, const ex & rh)
{
    debugmsg("operator!=(ex,ex)",LOGLEVEL_OPERATOR);
    return relational(lh,rh,relational::not_equal);
}

relational operator<(const ex & lh, const ex & rh)
{
    debugmsg("operator<(ex,ex)",LOGLEVEL_OPERATOR);
    return relational(lh,rh,relational::less);
}

relational operator<=(const ex & lh, const ex & rh)
{
    debugmsg("operator<=(ex,ex)",LOGLEVEL_OPERATOR);
    return relational(lh,rh,relational::less_or_equal);
}

relational operator>(const ex & lh, const ex & rh)
{
    debugmsg("operator>(ex,ex)",LOGLEVEL_OPERATOR);
    return relational(lh,rh,relational::greater);
}

relational operator>=(const ex & lh, const ex & rh)
{
    debugmsg("operator>=(ex,ex)",LOGLEVEL_OPERATOR);
    return relational(lh,rh,relational::greater_or_equal);
}

/*

// binary relational operators ex with numeric

relational operator==(const ex & lh, const numeric & rh)
{
    debugmsg("operator==(ex,numeric)",LOGLEVEL_OPERATOR);
    return relational(lh,rh,relational::equal);
}

relational operator!=(const ex & lh, const numeric & rh)
{
    debugmsg("operator!=(ex,numeric)",LOGLEVEL_OPERATOR);
    return relational(lh,rh,relational::not_equal);
}

relational operator<(const ex & lh, const numeric & rh)
{
    debugmsg("operator<(ex,numeric)",LOGLEVEL_OPERATOR);
    return relational(lh,rh,relational::less);
}

relational operator<=(const ex & lh, const numeric & rh)
{
    debugmsg("operator<=(ex,numeric)",LOGLEVEL_OPERATOR);
    return relational(lh,rh,relational::less_or_equal);
}

relational operator>(const ex & lh, const numeric & rh)
{
    debugmsg("operator>(ex,numeric)",LOGLEVEL_OPERATOR);
    return relational(lh,rh,relational::greater);
}

relational operator>=(const ex & lh, const numeric & rh)
{
    debugmsg("operator>=(ex,numeric)",LOGLEVEL_OPERATOR);
    return relational(lh,rh,relational::greater_or_equal);
}

// binary relational operators numeric with ex

relational operator==(const numeric & lh, const ex & rh)
{
    debugmsg("operator==(numeric,ex)",LOGLEVEL_OPERATOR);
    return relational(lh,rh,relational::equal);
}

relational operator!=(const numeric & lh, const ex & rh)
{
    debugmsg("operator!=(numeric,ex)",LOGLEVEL_OPERATOR);
    return relational(lh,rh,relational::not_equal);
}

relational operator<(const numeric & lh, const ex & rh)
{
    debugmsg("operator<(numeric,ex)",LOGLEVEL_OPERATOR);
    return relational(lh,rh,relational::less);
}

relational operator<=(const numeric & lh, const ex & rh)
{
    debugmsg("operator<=(numeric,ex)",LOGLEVEL_OPERATOR);
    return relational(lh,rh,relational::less_or_equal);
}

relational operator>(const numeric & lh, const ex & rh)
{
    debugmsg("operator>(numeric,ex)",LOGLEVEL_OPERATOR);
    return relational(lh,rh,relational::greater);
}

relational operator>=(const numeric & lh, const ex & rh)
{
    debugmsg("operator>=(numeric,ex)",LOGLEVEL_OPERATOR);
    return relational(lh,rh,relational::greater_or_equal);
}

*/

// input/output stream operators

ostream & operator<<(ostream & os, const ex & e)
{
    e.print(os);
    return os;
}

/** Input (parse) expression from stream. The input grammar is similar to the
 *  GiNaC output format. If 'e' contains a list of symbols upon entry, these
 *  symbols are used in the parsed expression in all places where symbols with
 *  the same names appear. All other encountered symbols will be newly created. */
istream & operator>>(istream & is, ex & e)
{
	string s;
	getline(is, s);
	set_lexer_string(s);
	set_lexer_symbols(e);
	ginac_yyrestart(NULL);
	if (yyparse())
		throw (std::runtime_error(get_parser_error()));
	else
		e = parsed_ex;
}

#ifndef NO_NAMESPACE_GINAC
} // namespace GiNaC
#endif // ndef NO_NAMESPACE_GINAC
