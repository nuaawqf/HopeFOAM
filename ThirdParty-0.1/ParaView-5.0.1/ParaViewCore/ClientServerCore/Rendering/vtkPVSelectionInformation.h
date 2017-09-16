/*=========================================================================

  Program:   ParaView
  Module:    vtkPVSelectionInformation.h

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkPVSelectionInformation - Used to gather selection information
// .SECTION Description
// Used to get information about selection from server to client.
// The results are stored in a vtkSelection. 
// .SECTION See Also
// vtkSelection

#ifndef vtkPVSelectionInformation_h
#define vtkPVSelectionInformation_h

#include "vtkPVClientServerCoreRenderingModule.h" //needed for exports
#include "vtkPVInformation.h"

class vtkClientServerStream;
class vtkPVXMLElement;
class vtkSelection;

class VTKPVCLIENTSERVERCORERENDERING_EXPORT vtkPVSelectionInformation : public vtkPVInformation
{
public:
  static vtkPVSelectionInformation* New();
  vtkTypeMacro(vtkPVSelectionInformation, vtkPVInformation);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Copy information from a selection to internal datastructure.
  virtual void CopyFromObject(vtkObject*);

  // Description:
  // Merge another information object.
  virtual void AddInformation(vtkPVInformation*);

  //BTX
  // Description:
  // Manage a serialized version of the information.
  virtual void CopyToStream(vtkClientServerStream*);
  virtual void CopyFromStream(const vtkClientServerStream*);
  //ETX

  // Description:
  // Returns the selection. Selection is created and populated
  // at the end of GatherInformation.
  vtkGetObjectMacro(Selection, vtkSelection);

protected:
  vtkPVSelectionInformation();
  ~vtkPVSelectionInformation();

  void Initialize();
  vtkSelection* Selection;

private:
  vtkPVSelectionInformation(const vtkPVSelectionInformation&); // Not implemented
  void operator=(const vtkPVSelectionInformation&); // Not implemented
};

#endif