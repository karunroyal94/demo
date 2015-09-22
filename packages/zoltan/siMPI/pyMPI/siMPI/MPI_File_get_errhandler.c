/*****************************************************************************
 * CVS File Information :
 *    $RCSfile$
 *    Author: patmiller $
 *    Date: 2007/06/11 14:12:50 $
 *    Revision: 1.2 $
 ****************************************************************************/
/****************************************************************************/
/* FILE  ****************** MPI_File_get_errhandler.c  **********************/
/****************************************************************************/
/* Author : Lisa Alano July 22 2002                                         */
/* Copyright (c) 2002 University of California Regents                      */
/****************************************************************************/

#include "mpi.h"

/* STUB */
int MPI_File_get_errhandler(MPI_File fh, MPI_Errhandler *errhandler)
{
  _MPI_COVERAGE();
  return PMPI_File_get_errhandler(fh, errhandler); 
}

