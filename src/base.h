/* $Id: base.h,v 1.5 2001/01/10 19:40:15 bates Exp $

   header file for the nlme package

   Copyright 1999-2001  Saikat DebRoy <saikat@stat.wisc.edu>

   This file is part of the nlme library for S and related languages
   and is made available under the terms of the GNU General Public
   License, version 2, or at your option, any later version,
   incorporated herein by reference.

   This program is distributed in the hope that it will be
   useful, but WITHOUT ANY WARRANTY; without even the implied
   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
   PURPOSE.  See the GNU General Public License for more
   details.

   You should have received a copy of the GNU General Public
   License along with this program; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
   MA 02111-1307, USA
 
*/

#ifndef NLME_BASE_H
#define NLME_BASE_H

#include "S.h"								     
#include <stdlib.h>

#ifdef R_S_H
#include <R.h>
#include <R_ext/Mathlib.h>
#include <R_ext/Applic.h>
#else
#include "nonlin.h"
#endif

#define DNULLP (double *) 0
				
#ifndef SPLUS_VERSION		/* F77_CALL and F77_NAME used as in S-PLUS */
#ifdef S_VERSION		/* S VERSION 4 */
#define F77_CALL F77_SUB
#define F77_NAME F77_SUB
#endif /* S_VERSION */
#endif /* SPLUS_VERSION */

#ifndef R_S_H
extern void F77_NAME(dtrsl)();
extern void F77_NAME(dqrsl)();
#define longint long int
#endif /* R_S_H */

#ifdef R_S_H
#define MOD , model
#define aMOD , SEXP model
#else
#define MOD
#define aMOD
#endif /* R_S_H */

#if( defined(SPLUS_VERSION) && SPLUS_VERSION >= 5000 )
#define  SEV , S_evaluator
#define aSEV , s_evaluator *S_evaluator
#else
#define  SEV
#define aSEV
#define S_EVALUATOR
#endif /* SPLUS_VERSION */

extern double sqrt_eps;
extern double xlower;

#endif /* NLME_BASE_H */
