/*****************************************************************************
 * CVS File Information :
 *    $RCSfile$
 *    Author: patmiller $
 *    Date: 2007/06/11 14:12:49 $
 *    Revision: 1.2 $
 ****************************************************************************/
/****************************************************************************/
/* FILE  ******************     MPI_Comm_dup.c       ************************/
/****************************************************************************/
/* Author : Lisa Alano July 18 2002                                         */
/* Copyright (c) 2002 University of California Regents                      */
/****************************************************************************/

#include "mpi.h"

/* STUB */
int MPI_Comm_dup ( 
        MPI_Comm comm, 
        MPI_Comm *comm_out )
{
  _MPI_COVERAGE();
  return PMPI_Comm_dup (comm, comm_out); 
}

