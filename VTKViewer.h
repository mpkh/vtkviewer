// VTK Viewer
// Written 2012 Hal Canary <http://cs.unc.edu/~hal>
// Copyright 2012 University of North Carolina at Chapel Hill.
//
// Licensed under the Apache License, Version 2.0 (the "License"); you
// may not use this file except in compliance with the License.  You
// may obtain a copy of the License at
//
//   LICENSE.md in this repository or
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
// implied.  See the License for the specific language governing
// permissions and limitations under the License.

#ifndef VTKVIEWER_H
#define VTKVIEWER_H

#include <cassert>

#include <QTimer>

#include <QVTKWidget.h>
#include <vtkRenderer.h>
#include <vtkSmartPointer.h>
#include <vtkTextActor.h>
#include <vtkActor.h>
class vtkPolyData;

class VTKViewer : public QVTKWidget {
  Q_OBJECT
public:
  VTKViewer();
  void add(vtkPolyData * polyData);
  void add(const char * file_name);
  void start();

  static vtkTextActor* m_TextActor;
  static char m_textBuff[128];

public slots:
  void updateFPS();
  void rotate();
  void toggleRotate();
  void toggleStereo();
  void setStereoType(int vtkStereoType);
  void nextStereoType();
  void screenshot();
private:
  static void CallbackFunction(vtkObject* caller, long unsigned int vtkNotUsed(eventId), void* vtkNotUsed(clientData), void* vtkNotUsed(callData) );
  QTimer m_timer;
  QTimer m_FPStimer;
  vtkSmartPointer < vtkRenderer > m_renderer;
};

#endif /* VTKVIEWER_H */
