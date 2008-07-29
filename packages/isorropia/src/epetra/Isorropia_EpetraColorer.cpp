//@HEADER
/*
************************************************************************

              Isorropia: Partitioning and Load Balancing Package
                Copyright (2006) Sandia Corporation

Under terms of Contract DE-AC04-94AL85000, there is a non-exclusive
license for use of this work by or on behalf of the U.S. Government.

This library is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as
published by the Free Software Foundation; either version 2.1 of the
License, or (at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
USA
Questions? Contact Alan Williams (william@sandia.gov)
                or Erik Boman    (egboman@sandia.gov)

************************************************************************
*/
//@HEADER

#include <Isorropia_EpetraColorer.hpp>
#ifdef HAVE_ISORROPIA_ZOLTAN
#include <Isorropia_Zoltan_Repartition.hpp>
#include <Isorropia_EpetraZoltanLib.hpp>
#endif
#include <Isorropia_Exception.hpp>
#include <Isorropia_Epetra.hpp>
#include <Isorropia_EpetraCostDescriber.hpp>

#include <Teuchos_RefCountPtr.hpp>
#include <Teuchos_ParameterList.hpp>

#ifdef HAVE_EPETRA
#include <Epetra_Comm.h>
#include <Epetra_Map.h>
#include <Epetra_Import.h>
#include <Epetra_Vector.h>
#include <Epetra_MultiVector.h>
#include <Epetra_CrsGraph.h>
#include <Epetra_CrsMatrix.h>
#include <Epetra_LinearProblem.h>

#endif

#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <ctype.h>

namespace Isorropia {

#ifdef HAVE_EPETRA

namespace Epetra {


Colorer::Colorer(Teuchos::RefCountPtr<const Epetra_CrsGraph> input_graph,
		 const Teuchos::ParameterList& paramlist,
		 bool compute_now):
  Operator (input_graph, paramlist) {
  lib_ = Teuchos::rcp(new ZoltanLibClass(input_graph));
  lib_->setInputType("GRAPH");

  if (compute_now)
    color(true);
}


void
Colorer::color(bool force_coloring)
{
  if (alreadyComputed() && !force_coloring)
    return;
  lib_->color(paramlist_, myNewElements_, exports_, imports_);
  operation_already_computed_ = true;
}



} // namespace EPETRA

#endif //HAVE_EPETRA

}//namespace Isorropia

