/*
 * CDE - Common Desktop Environment
 *
 * Copyright (c) 1993-2012, The Open Group. All rights reserved.
 *
 * These libraries and programs are free software; you can
 * redistribute them and/or modify them under the terms of the GNU
 * Lesser General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * These libraries and programs are distributed in the hope that
 * they will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE. See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with these librararies and programs; if not, write
 * to the Free Software Foundation, Inc., 51 Franklin Street, Fifth
 * Floor, Boston, MA 02110-1301 USA
 */
/* $XConsortium: emptyfil.c /main/3 1995/11/08 10:30:15 rswiston $ */
/* Copyright (c) 1988, 1989 Hewlett-Packard Co. */
/* Creates a file with nothing in it */
#include <stdio.h>
#if defined(MSDOS)
#include <process.h>
#endif
#include "basic.h"

void main(
#if defined(M_PROTO)
  int argc, char **argv
#endif
  ) ;

void main(argc, argv)
  int argc ;
  char **argv ;
  {
    if (argc != 2) {
      fprintf(stderr, "Usage: emptyfil filename\n") ;
      exit(1) ;
      }
    if (! fopen(argv[1], "w"))
      fprintf(stderr, "Unable to open %s\n", argv[1]) ;
    return 0;
    }
