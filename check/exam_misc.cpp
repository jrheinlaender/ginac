/** @file exam_misc.cpp
 *
 */
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


#include "exams.h"

#define VECSIZE 30
static unsigned exam_expand_subs(void)
{
    unsigned result = 0;
    symbol a1("a1");
    symbol a[VECSIZE];
    ex e, aux;
    
    a[1] = a1;
    for (unsigned i=0; i<VECSIZE; ++i) {
        e = e + a[i];
    }
    
    // prepare aux so it will swallow anything but a1^2:
    aux = -e + a[0] + a[1];
    e = expand(subs(expand(pow(e, 2)), a[0] == aux));
    
    if (e != pow(a1,2)) {
        clog << "Denny Fliegner's quick consistency check erroneously returned "
             << e << "." << endl;
        ++result;
    }
    
    return result;
}

/*  A simple modification of Denny Fliegner's three step consistency test:
 *  1)  e = (a0 + a1)^200
 *  2)  expand e
 *  3)  substitute a0 by -a1 in e
 *  after which e should return 0 (without expanding). */
static unsigned exam_expand_subs2(void)
{
    unsigned result = 0;
    symbol a("a"), b("b");
    ex e, f;
    
    e = pow(a+b,200).expand();
    f = e.subs(a == -b);

    if (f != 0) {
        clog << "e = pow(a+b,200).expand(); f = e.subs(a == -b); erroneously returned "
             << f << " instead of simplifying to 0." << endl;
        ++result;
    }
    
    return result;
}

unsigned exam_misc(void)
{
    unsigned result = 0;
    
    cout << "examining miscellaneous other things" << flush;
    clog << "----------miscellaneous other things:" << endl;
    
    result += exam_expand_subs();  cout << '.' << flush;
    result += exam_expand_subs2();  cout << '.' << flush;
    
    if (!result) {
        cout << " passed " << endl;
        clog << "(no output)" << endl;
    } else {
        cout << " failed " << endl;
    }
    
    return result;
}