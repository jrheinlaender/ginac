/** @file exam_archive.cpp
 *
 *  Here we test GiNaC's archiving system. */

/*
 *  GiNaC Copyright (C) 1999-2001 Johannes Gutenberg University Mainz, Germany
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

#include <fstream>

unsigned exam_archive(void)
{
	unsigned result = 0;
	
	cout << "examining archiving system" << flush;
	clog << "----------archiving system:" << endl;

	symbol x("x"), y("y"), mu("mu"), dim("dim", "\\Delta");
	ex e, f;

	// This expression is complete nonsense but it contains every type of
	// GiNaC object
	e = -42 * x * pow(y, sin(y*Catalan)) * dirac_ONE()
	    * epsilon_tensor(idx(fail(), 3), idx(0, 3), idx(y/2, 3))
	  + lorentz_g(
	      varidx(lst(x, -11*y, acos(2*x).series(x==3-5*I, 3)) * color_ONE()
	        * metric_tensor(spinidx(0, 5, false, true), varidx(2, 4)), zeta(3)),
	      varidx(diag_matrix(lst(-1, Euler, atan(x/y==-15*I/17)))
	        * delta_tensor(idx(x, 2), idx(wild(7), 3)), log(cos(128.0/(x*y))), true),
	      true
	    )
	  + dirac_gamma(varidx(mu, dim)) * dirac_gamma(varidx(mu, 4-dim, true))
	    * color_T(idx(x, 8), 1) * color_h(idx(x, 8), idx(y, 8), idx(2, 8))
	    * indexed(x, sy_anti(), idx(2*y+1, x), varidx(-mu, 5))
	  - 2 * spinor_metric(spinidx(x), spinidx(y))
	  + 0.775;

	archive ar;
	ar.archive_ex(e, "expr 1");
	{
		std::ofstream fout("exam.gar");
		fout << ar;
	}
	ar.clear();
	{
		std::ifstream fin("exam.gar");
		fin >> ar;
	}
	f = ar.unarchive_ex(lst(x, y, mu, dim), "expr 1");

	if (!f.is_equal(e)) {
		clog << "archiving/unarchiving " << e << endl
		     << "erroneously returned " << f << endl;
		++result;
	}

	cout << '.' << flush;
	
	if (!result) {
		cout << " passed " << endl;
		clog << "(no output)" << endl;
	} else {
		cout << " failed " << endl;
	}
	
	return result;
}
