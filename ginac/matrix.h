/** @file matrix.h
 *
 *  Interface to symbolic matrices */

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

#ifndef __GINAC_MATRIX_H__
#define __GINAC_MATRIX_H__

#include <vector>
#include "basic.h"
#include "ex.h"

#ifndef NO_NAMESPACE_GINAC
namespace GiNaC {
#endif // ndef NO_NAMESPACE_GINAC

/** Symbolic matrices. */
class matrix : public basic
{
    GINAC_DECLARE_REGISTERED_CLASS(matrix, basic)

// friends
// (none)
// member functions

    // default constructor, destructor, copy constructor, assignment operator
    // and helpers:
public:
    matrix();
    ~matrix();
    matrix(const matrix & other);
    const matrix & operator=(const matrix & other);
protected:
    void copy(const matrix & other);
    void destroy(bool call_parent);

    // other constructors
public:
    matrix(unsigned r, unsigned c);
    matrix(unsigned r, unsigned c, const exvector & m2);
   
    // functions overriding virtual functions from bases classes
public:
    basic * duplicate() const;
    void print(ostream & os, unsigned upper_precedence=0) const;
    void printraw(ostream & os) const;
    unsigned nops() const;
    ex op(int i) const;
    ex & let_op(int i);
    ex expand(unsigned options=0) const;
    bool has(const ex & other) const;
    ex eval(int level=0) const;
    ex evalf(int level=0) const;
    // ex subs(const lst & ls, const lst & lr) const;
protected:
    int compare_same_type(const basic & other) const;
    unsigned return_type(void) const { return return_types::noncommutative; };
    // new virtual functions which can be overridden by derived classes
    // (none)
    
    // non-virtual functions in this class
public:
    unsigned rows(void) const        //! get number of rows.
        { return row; }
    unsigned cols(void) const        //! get number of columns.
        { return col; }
    matrix add(const matrix & other) const;
    matrix sub(const matrix & other) const;
    matrix mul(const matrix & other) const;
    const ex & operator() (unsigned ro, unsigned co) const;
    matrix & set(unsigned ro, unsigned co, ex value);
    matrix transpose(void) const;
    ex determinant(void) const;
    ex trace(void) const;
    ex charpoly(const ex & lambda) const;
    matrix inverse(void) const;
    matrix fraction_free_elim(const matrix & vars, const matrix & v) const;
    matrix solve(const matrix & vars, const matrix & rhs) const;
    matrix old_solve(const matrix & v) const;  // FIXME: may be removed
protected:
    ex determinant_numeric(void) const;
    ex determinant_minor_sparse(void) const;
    ex determinant_minor_dense(void) const;
    ex determinant_bareiss(void) const;
    ex determinant_perm(void) const;
    int gauss_elimination(void);
    int fraction_free_elimination(void);
    int division_free_elimination(void);
    int pivot(unsigned ro, bool symbolic=true);
private:  // FIXME: these should be obsoleted
    void ffe_swap(unsigned r1, unsigned c1, unsigned r2 ,unsigned c2);
    void ffe_set(unsigned r, unsigned c, ex e);
    ex ffe_get(unsigned r, unsigned c) const;
    
// member variables
protected:
    unsigned row;             /**< number of rows      */
    unsigned col;             /**< number of columns   */
    exvector m;               /**< representation (cols indexed first) */
    static unsigned precedence;
};

// global constants
extern const matrix some_matrix;
extern const type_info & typeid_matrix;

// wrapper functions around member functions

inline unsigned nops(const matrix & m)
{ return m.nops(); }

inline ex expand(const matrix & m, unsigned options=0)
{ return m.expand(options); }

inline bool has(const matrix & m, const ex & other)
{ return m.has(other); }

inline ex eval(const matrix & m, int level=0)
{ return m.eval(level); }

inline ex evalf(const matrix & m, int level=0)
{ return m.evalf(level); }

inline unsigned rows(const matrix & m)
{ return m.rows(); }

inline unsigned cols(const matrix & m)
{ return m.cols(); }

inline matrix transpose(const matrix & m)
{ return m.transpose(); }

inline ex determinant(const matrix & m)
{ return m.determinant(); }

inline ex trace(const matrix & m)
{ return m.trace(); }

inline ex charpoly(const matrix & m, const ex & lambda)
{ return m.charpoly(lambda); }

inline matrix inverse(const matrix & m)
{ return m.inverse(); }

// utility functions
inline const matrix &ex_to_matrix(const ex &e)
{
	return static_cast<const matrix &>(*e.bp);
}

extern ex lst_to_matrix(const ex &l);

#ifndef NO_NAMESPACE_GINAC
} // namespace GiNaC
#endif // ndef NO_NAMESPACE_GINAC

#endif // ndef __GINAC_MATRIX_H__
