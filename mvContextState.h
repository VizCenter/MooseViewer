#ifndef MVCONTEXTSTATE_H
#define MVCONTEXTSTATE_H

#include <GL/GLObject.h>

// VTK includes
#include <vtkNew.h>

// Forward declarations
class ExternalVTKWidget;
class vtkActor;
class vtkCheckerboardSplatter;
class vtkColorTransferFunction;
class vtkCompositeDataGeometryFilter;
class vtkCompositePolyDataMapper;
class vtkExternalOpenGLRenderer;
class vtkLookupTable;
class vtkPiecewiseFunction;
class vtkPolyDataMapper;
class vtkSmartVolumeMapper;
class vtkTextActor;
class vtkVolume;

/**
 * @brief The mvContextState class holds shared context state.
 *
 * mvContextState holds per-context state that is shared between mvGLObjects.
 */
class mvContextState : public GLObject::DataItem
{
public:
  mvContextState();
  ~mvContextState();

  // These aren't const-correct bc VTK is not const-correct.
  vtkLookupTable& colorMap() const { return *m_colorMap.Get(); }
  vtkExternalOpenGLRenderer& renderer() const { return *m_renderer.Get(); }
  ExternalVTKWidget& widget() const { return *m_widget.Get(); }

  // These need to be refactored into mvGLObject context data.
  vtkNew<vtkActor> actor;
  vtkNew<vtkActor> actorOutline;
  vtkNew<vtkCompositeDataGeometryFilter> compositeFilter;
  vtkNew<vtkPolyDataMapper> mapper;

  vtkNew<vtkCheckerboardSplatter> gaussian;
  vtkNew<vtkVolume> actorVolume;
  vtkNew<vtkSmartVolumeMapper> mapperVolume;
  vtkNew<vtkColorTransferFunction> colorFunction;
  vtkNew<vtkPiecewiseFunction> opacityFunction;

  vtkNew<vtkTextActor> framerate;

private:
  // VTK components
  vtkNew<vtkLookupTable> m_colorMap;
  vtkNew<vtkExternalOpenGLRenderer> m_renderer;
  vtkNew<ExternalVTKWidget> m_widget;
};

#endif // MVCONTEXTSTATE_H
