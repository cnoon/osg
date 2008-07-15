// ***************************************************************************
//
//   Generated automatically by genwrapper.
//   Please DO NOT EDIT this file!
//
// ***************************************************************************

#include <osgIntrospection/ReflectionMacros>
#include <osgIntrospection/TypedMethodInfo>
#include <osgIntrospection/StaticMethodInfo>
#include <osgIntrospection/Attributes>

#include <osg/CopyOp>
#include <osg/Drawable>
#include <osg/Geode>
#include <osg/Object>
#include <osgWidget/Types>
#include <osgWidget/Widget>
#include <osgWidget/Window>
#include <osgWidget/WindowManager>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

TYPE_NAME_ALIAS(std::list< osg::observer_ptr< osgWidget::Window > >, osgWidget::Window::WindowList)

BEGIN_ENUM_REFLECTOR(osgWidget::Window::STRATA)
	I_DeclaringFile("osgWidget/Window");
	I_EnumLabel(osgWidget::Window::STRATA_NONE);
	I_EnumLabel(osgWidget::Window::STRATA_BACKGROUND);
	I_EnumLabel(osgWidget::Window::STRATA_FOREGROUND);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osgWidget::Window::VISIBILITY_MODE)
	I_DeclaringFile("osgWidget/Window");
	I_EnumLabel(osgWidget::Window::VM_FULL);
	I_EnumLabel(osgWidget::Window::VM_PARTIAL);
	I_EnumLabel(osgWidget::Window::VM_ENTIRE);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osgWidget::Window::VERTICAL_ANCHOR)
	I_DeclaringFile("osgWidget/Window");
	I_EnumLabel(osgWidget::Window::VA_NONE);
	I_EnumLabel(osgWidget::Window::VA_CENTER);
	I_EnumLabel(osgWidget::Window::VA_TOP);
	I_EnumLabel(osgWidget::Window::VA_BOTTOM);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osgWidget::Window::HORIZONTAL_ANCHOR)
	I_DeclaringFile("osgWidget/Window");
	I_EnumLabel(osgWidget::Window::HA_NONE);
	I_EnumLabel(osgWidget::Window::HA_CENTER);
	I_EnumLabel(osgWidget::Window::HA_LEFT);
	I_EnumLabel(osgWidget::Window::HA_RIGHT);
END_REFLECTOR

BEGIN_ABSTRACT_OBJECT_REFLECTOR(osgWidget::Window)
	I_DeclaringFile("osgWidget/Window");
	I_BaseType(osg::MatrixTransform);
	I_BaseType(osgWidget::UIObjectParent);
	I_BaseType(osgWidget::EventInterface);
	I_BaseType(osgWidget::StyleInterface);
	I_Method1(, META_UIObject, IN, osgWidget::Window, x,
	          Properties::NON_VIRTUAL,
	          ____META_UIObject__Window,
	          "",
	          "");
	I_ConstructorWithDefaults1(IN, const std::string &, x, "",
	                           Properties::NON_EXPLICIT,
	                           ____Window__C5_std_string_R1,
	                           "",
	                           "");
	I_Constructor2(IN, const osgWidget::Window &, x, IN, const osg::CopyOp &, x,
	               ____Window__C5_Window_R1__C5_osg_CopyOp_R1,
	               "",
	               "");
	I_MethodWithDefaults2(bool, resize, IN, osgWidget::point_type, x, 0.0f, IN, osgWidget::point_type, x, 0.0f,
	                      Properties::NON_VIRTUAL,
	                      __bool__resize__point_type__point_type,
	                      "",
	                      "");
	I_MethodWithDefaults2(bool, resizeAdd, IN, osgWidget::point_type, x, 0.0f, IN, osgWidget::point_type, x, 0.0f,
	                      Properties::NON_VIRTUAL,
	                      __bool__resizeAdd__point_type__point_type,
	                      "",
	                      "");
	I_MethodWithDefaults2(bool, resizePercent, IN, osgWidget::point_type, x, 0.0f, IN, osgWidget::point_type, x, 0.0f,
	                      Properties::NON_VIRTUAL,
	                      __bool__resizePercent__point_type__point_type,
	                      "",
	                      "");
	I_Method0(void, update,
	          Properties::VIRTUAL,
	          __void__update,
	          "",
	          "");
	I_Method1(void, managed, IN, osgWidget::WindowManager *, x,
	          Properties::VIRTUAL,
	          __void__managed__WindowManager_P1,
	          "",
	          "");
	I_Method1(void, unmanaged, IN, osgWidget::WindowManager *, x,
	          Properties::VIRTUAL,
	          __void__unmanaged__WindowManager_P1,
	          "",
	          "");
	I_Method1(bool, addWidget, IN, osgWidget::Widget *, x,
	          Properties::VIRTUAL,
	          __bool__addWidget__Widget_P1,
	          "",
	          "");
	I_Method2(bool, insertWidget, IN, osgWidget::Widget *, x, IN, unsigned, int,
	          Properties::VIRTUAL,
	          __bool__insertWidget__Widget_P1__unsigned,
	          "",
	          "");
	I_Method1(bool, removeWidget, IN, osgWidget::Widget *, x,
	          Properties::VIRTUAL,
	          __bool__removeWidget__Widget_P1,
	          "",
	          "");
	I_Method2(bool, replaceWidget, IN, osgWidget::Widget *, x, IN, osgWidget::Widget *, x,
	          Properties::VIRTUAL,
	          __bool__replaceWidget__Widget_P1__Widget_P1,
	          "",
	          "");
	I_Method1(unsigned int, addDrawableAndGetIndex, IN, osg::Drawable *, x,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__addDrawableAndGetIndex__osg_Drawable_P1,
	          "",
	          "");
	I_Method0(bool, isVisible,
	          Properties::NON_VIRTUAL,
	          __bool__isVisible,
	          "",
	          "");
	I_Method2(bool, isXYWithinVisible, IN, float, x, IN, float, x,
	          Properties::NON_VIRTUAL,
	          __bool__isXYWithinVisible__float__float,
	          "",
	          "");
	I_MethodWithDefaults4(void, setVisibleArea, IN, int, x, 0, IN, int, x, 0, IN, int, x, 0, IN, int, x, 0,
	                      Properties::NON_VIRTUAL,
	                      __void__setVisibleArea__int__int__int__int,
	                      "",
	                      "");
	I_MethodWithDefaults4(void, addVisibleArea, IN, int, x, 0, IN, int, x, 0, IN, int, x, 0, IN, int, x, 0,
	                      Properties::NON_VIRTUAL,
	                      __void__addVisibleArea__int__int__int__int,
	                      "",
	                      "");
	I_Method1(bool, setFocused, IN, const osgWidget::Widget *, x,
	          Properties::NON_VIRTUAL,
	          __bool__setFocused__C5_Widget_P1,
	          "",
	          "");
	I_Method1(bool, setFocused, IN, const std::string &, x,
	          Properties::NON_VIRTUAL,
	          __bool__setFocused__C5_std_string_R1,
	          "",
	          "");
	I_Method0(bool, setFirstFocusable,
	          Properties::NON_VIRTUAL,
	          __bool__setFirstFocusable,
	          "",
	          "");
	I_Method0(bool, setNextFocusable,
	          Properties::NON_VIRTUAL,
	          __bool__setNextFocusable,
	          "",
	          "");
	I_Method1(bool, getFocusList, IN, osgWidget::WidgetList &, x,
	          Properties::NON_VIRTUAL,
	          __bool__getFocusList__WidgetList_R1,
	          "",
	          "");
	I_Method1(bool, getEmbeddedList, IN, osgWidget::Window::WindowList &, x,
	          Properties::NON_VIRTUAL,
	          __bool__getEmbeddedList__WindowList_R1,
	          "",
	          "");
	I_Method1(void, getParentList, IN, osgWidget::Window::WindowList &, x,
	          Properties::NON_VIRTUAL,
	          __void__getParentList__WindowList_R1,
	          "",
	          "");
	I_Method2(osgWidget::XYCoord, localXY, IN, double, x, IN, double, x,
	          Properties::NON_VIRTUAL,
	          __XYCoord__localXY__double__double,
	          "",
	          "");
	I_Method0(osgWidget::XYCoord, getAbsoluteOrigin,
	          Properties::NON_VIRTUAL,
	          __XYCoord__getAbsoluteOrigin,
	          "",
	          "");
	I_Method0(osgWidget::Window::EmbeddedWindow *, embed,
	          Properties::NON_VIRTUAL,
	          __EmbeddedWindow_P1__embed,
	          "",
	          "");
	I_Method0(osgWidget::Widget *, getFocused,
	          Properties::NON_VIRTUAL,
	          __Widget_P1__getFocused,
	          "",
	          "");
	I_Method0(const osgWidget::Widget *, getFocused,
	          Properties::NON_VIRTUAL,
	          __C5_Widget_P1__getFocused,
	          "",
	          "");
	I_Method0(bool, show,
	          Properties::NON_VIRTUAL,
	          __bool__show,
	          "",
	          "");
	I_Method0(bool, hide,
	          Properties::NON_VIRTUAL,
	          __bool__hide,
	          "",
	          "");
	I_Method2(bool, isPointerXYWithinVisible, IN, float, x, IN, float, y,
	          Properties::NON_VIRTUAL,
	          __bool__isPointerXYWithinVisible__float__float,
	          "",
	          "");
	I_Method0(osg::Geode *, getGeode,
	          Properties::NON_VIRTUAL,
	          __osg_Geode_P1__getGeode,
	          "",
	          "");
	I_Method0(const osg::Geode *, getGeode,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Geode_P1__getGeode,
	          "",
	          "");
	I_Method0(osgWidget::Widget *, getBackground,
	          Properties::NON_VIRTUAL,
	          __Widget_P1__getBackground,
	          "",
	          "");
	I_Method0(const osgWidget::Widget *, getBackground,
	          Properties::NON_VIRTUAL,
	          __C5_Widget_P1__getBackground,
	          "",
	          "");
	I_Method0(osgWidget::WindowManager *, getWindowManager,
	          Properties::NON_VIRTUAL,
	          __WindowManager_P1__getWindowManager,
	          "",
	          "");
	I_Method0(const osgWidget::WindowManager *, getWindowManager,
	          Properties::NON_VIRTUAL,
	          __C5_WindowManager_P1__getWindowManager,
	          "",
	          "");
	I_Method0(osgWidget::Window *, getParent,
	          Properties::NON_VIRTUAL,
	          __Window_P1__getParent,
	          "",
	          "");
	I_Method0(const osgWidget::Window *, getParent,
	          Properties::NON_VIRTUAL,
	          __C5_Window_P1__getParent,
	          "",
	          "");
	I_Method0(osgWidget::Window *, getTopmostParent,
	          Properties::NON_VIRTUAL,
	          __Window_P1__getTopmostParent,
	          "",
	          "");
	I_Method0(const osgWidget::Window *, getTopmostParent,
	          Properties::NON_VIRTUAL,
	          __C5_Window_P1__getTopmostParent,
	          "",
	          "");
	I_Method0(unsigned int, getIndex,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getIndex,
	          "",
	          "");
	I_Method0(osgWidget::matrix_type, getX,
	          Properties::NON_VIRTUAL,
	          __matrix_type__getX,
	          "",
	          "");
	I_Method0(osgWidget::matrix_type, getY,
	          Properties::NON_VIRTUAL,
	          __matrix_type__getY,
	          "",
	          "");
	I_Method0(osgWidget::matrix_type, getZ,
	          Properties::NON_VIRTUAL,
	          __matrix_type__getZ,
	          "",
	          "");
	I_Method0(osgWidget::point_type, getWidth,
	          Properties::NON_VIRTUAL,
	          __point_type__getWidth,
	          "",
	          "");
	I_Method0(osgWidget::point_type, getHeight,
	          Properties::NON_VIRTUAL,
	          __point_type__getHeight,
	          "",
	          "");
	I_Method0(osgWidget::point_type, getMinWidth,
	          Properties::NON_VIRTUAL,
	          __point_type__getMinWidth,
	          "",
	          "");
	I_Method0(osgWidget::point_type, getMinHeight,
	          Properties::NON_VIRTUAL,
	          __point_type__getMinHeight,
	          "",
	          "");
	I_Method0(osgWidget::Window::VERTICAL_ANCHOR, getAnchorVertical,
	          Properties::NON_VIRTUAL,
	          __VERTICAL_ANCHOR__getAnchorVertical,
	          "",
	          "");
	I_Method0(osgWidget::Window::HORIZONTAL_ANCHOR, getAnchorHorizontal,
	          Properties::NON_VIRTUAL,
	          __HORIZONTAL_ANCHOR__getAnchorHorizontal,
	          "",
	          "");
	I_Method0(osgWidget::XYCoord, getOrigin,
	          Properties::NON_VIRTUAL,
	          __XYCoord__getOrigin,
	          "",
	          "");
	I_Method0(osgWidget::XYCoord, getSize,
	          Properties::NON_VIRTUAL,
	          __XYCoord__getSize,
	          "",
	          "");
	I_Method0(osgWidget::XYCoord, getMinSize,
	          Properties::NON_VIRTUAL,
	          __XYCoord__getMinSize,
	          "",
	          "");
	I_Method0(osgWidget::matrix_type, getZRange,
	          Properties::NON_VIRTUAL,
	          __matrix_type__getZRange,
	          "",
	          "");
	I_Method0(osgWidget::Window::STRATA, getStrata,
	          Properties::NON_VIRTUAL,
	          __STRATA__getStrata,
	          "",
	          "");
	I_Method0(const osgWidget::Quad &, getVisibleArea,
	          Properties::NON_VIRTUAL,
	          __C5_Quad_R1__getVisibleArea,
	          "",
	          "");
	I_Method0(osgWidget::Window::VISIBILITY_MODE, getVisibilityMode,
	          Properties::NON_VIRTUAL,
	          __VISIBILITY_MODE__getVisibilityMode,
	          "",
	          "");
	I_Method0(osgWidget::Point, getPosition,
	          Properties::NON_VIRTUAL,
	          __Point__getPosition,
	          "",
	          "");
	I_Method0(osgWidget::matrix_type, getRotate,
	          Properties::NON_VIRTUAL,
	          __matrix_type__getRotate,
	          "",
	          "");
	I_Method0(osgWidget::matrix_type, getScale,
	          Properties::NON_VIRTUAL,
	          __matrix_type__getScale,
	          "",
	          "");
	I_Method0(osgWidget::matrix_type, getScaleDenominator,
	          Properties::NON_VIRTUAL,
	          __matrix_type__getScaleDenominator,
	          "",
	          "");
	I_Method1(void, setX, IN, osgWidget::matrix_type, x,
	          Properties::NON_VIRTUAL,
	          __void__setX__matrix_type,
	          "",
	          "");
	I_Method1(void, setY, IN, osgWidget::matrix_type, y,
	          Properties::NON_VIRTUAL,
	          __void__setY__matrix_type,
	          "",
	          "");
	I_Method3(void, setPosition, IN, osgWidget::matrix_type, x, IN, osgWidget::matrix_type, y, IN, osgWidget::matrix_type, z,
	          Properties::NON_VIRTUAL,
	          __void__setPosition__matrix_type__matrix_type__matrix_type,
	          "",
	          "");
	I_Method1(void, setPosition, IN, const osgWidget::Point &, p,
	          Properties::NON_VIRTUAL,
	          __void__setPosition__C5_Point_R1,
	          "",
	          "");
	I_Method2(void, setOrigin, IN, osgWidget::matrix_type, x, IN, osgWidget::matrix_type, y,
	          Properties::NON_VIRTUAL,
	          __void__setOrigin__matrix_type__matrix_type,
	          "",
	          "");
	I_Method1(void, setRotate, IN, osgWidget::matrix_type, r,
	          Properties::NON_VIRTUAL,
	          __void__setRotate__matrix_type,
	          "",
	          "");
	I_Method1(void, setScale, IN, osgWidget::matrix_type, s,
	          Properties::NON_VIRTUAL,
	          __void__setScale__matrix_type,
	          "",
	          "");
	I_Method1(void, setScaleDenominator, IN, osgWidget::matrix_type, sd,
	          Properties::NON_VIRTUAL,
	          __void__setScaleDenominator__matrix_type,
	          "",
	          "");
	I_Method1(void, setAnchorVertical, IN, osgWidget::Window::VERTICAL_ANCHOR, va,
	          Properties::NON_VIRTUAL,
	          __void__setAnchorVertical__VERTICAL_ANCHOR,
	          "",
	          "");
	I_Method1(void, setAnchorHorizontal, IN, osgWidget::Window::HORIZONTAL_ANCHOR, ha,
	          Properties::NON_VIRTUAL,
	          __void__setAnchorHorizontal__HORIZONTAL_ANCHOR,
	          "",
	          "");
	I_Method1(void, setStrata, IN, osgWidget::Window::STRATA, s,
	          Properties::NON_VIRTUAL,
	          __void__setStrata__STRATA,
	          "",
	          "");
	I_Method1(void, setVisibilityMode, IN, osgWidget::Window::VISIBILITY_MODE, v,
	          Properties::NON_VIRTUAL,
	          __void__setVisibilityMode__VISIBILITY_MODE,
	          "",
	          "");
	I_Method1(void, addX, IN, osgWidget::matrix_type, x,
	          Properties::NON_VIRTUAL,
	          __void__addX__matrix_type,
	          "",
	          "");
	I_Method1(void, addY, IN, osgWidget::matrix_type, y,
	          Properties::NON_VIRTUAL,
	          __void__addY__matrix_type,
	          "",
	          "");
	I_Method1(void, addZ, IN, osgWidget::matrix_type, z,
	          Properties::NON_VIRTUAL,
	          __void__addZ__matrix_type,
	          "",
	          "");
	I_Method1(void, addRotate, IN, osgWidget::matrix_type, r,
	          Properties::NON_VIRTUAL,
	          __void__addRotate__matrix_type,
	          "",
	          "");
	I_Method1(void, addScale, IN, osgWidget::matrix_type, s,
	          Properties::NON_VIRTUAL,
	          __void__addScale__matrix_type,
	          "",
	          "");
	I_Method2(void, addOrigin, IN, osgWidget::matrix_type, x, IN, osgWidget::matrix_type, y,
	          Properties::NON_VIRTUAL,
	          __void__addOrigin__matrix_type__matrix_type,
	          "",
	          "");
	I_Method0(void, attachMoveCallback,
	          Properties::NON_VIRTUAL,
	          __void__attachMoveCallback,
	          "",
	          "");
	I_Method0(void, attachRotateCallback,
	          Properties::NON_VIRTUAL,
	          __void__attachRotateCallback,
	          "",
	          "");
	I_Method0(void, attachScaleCallback,
	          Properties::NON_VIRTUAL,
	          __void__attachScaleCallback,
	          "",
	          "");
	I_Method0(void, attachTabFocusCallback,
	          Properties::NON_VIRTUAL,
	          __void__attachTabFocusCallback,
	          "",
	          "");
	I_ProtectedMethod2(void, _setWidthAndHeightUnknownSizeError, IN, const std::string &, x, IN, osgWidget::point_type, x,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void___setWidthAndHeightUnknownSizeError__C5_std_string_R1__point_type,
	                   "",
	                   "");
	I_ProtectedMethod2(void, _setWidthAndHeightNotPAError, IN, const std::string &, x, IN, osgWidget::point_type, x,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void___setWidthAndHeightNotPAError__C5_std_string_R1__point_type,
	                   "",
	                   "");
	I_ProtectedMethod0(void, _setWidthAndHeight,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void___setWidthAndHeight,
	                   "",
	                   "");
	I_ProtectedMethod1(void, _removeFromGeode, IN, osgWidget::Widget *, x,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void___removeFromGeode__Widget_P1,
	                   "",
	                   "");
	I_ProtectedMethod0(osgWidget::Widget *, _getBackground,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __Widget_P1___getBackground,
	                   "",
	                   "");
	I_ProtectedMethod0(osgWidget::Window *, _getTopmostParent,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __Window_P1___getTopmostParent,
	                   "",
	                   "");
	I_ProtectedMethod0(osg::Geode *, _geode,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __osg_Geode_P1___geode,
	                   "",
	                   "");
	I_ProtectedMethod0(const osg::Geode *, _geode,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __C5_osg_Geode_P1___geode,
	                   "",
	                   "");
	I_ProtectedMethod0(osgWidget::Widget *, _bg,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __Widget_P1___bg,
	                   "",
	                   "");
	I_ProtectedMethod0(const osgWidget::Widget *, _bg,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __C5_Widget_P1___bg,
	                   "",
	                   "");
	I_ProtectedMethod0(osg::Scissor *, _scissor,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __osg_Scissor_P1___scissor,
	                   "",
	                   "");
	I_ProtectedMethodWithDefaults2(bool, _setWidget, IN, osgWidget::Widget *, x, , IN, int, x, -1,
	                               Properties::NON_VIRTUAL,
	                               Properties::NON_CONST,
	                               __bool___setWidget__Widget_P1__int,
	                               "",
	                               "");
	I_ProtectedMethod1(bool, _setVisible, IN, bool, x,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __bool___setVisible__bool,
	                   "",
	                   "");
	I_ProtectedMethod1(void, _setFocused, IN, osgWidget::Widget *, x,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void___setFocused__Widget_P1,
	                   "",
	                   "");
	I_ProtectedMethod1(void, _setStyled, IN, osgWidget::Widget *, x,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void___setStyled__Widget_P1,
	                   "",
	                   "");
	I_ProtectedMethodWithDefaults2(void, _setParented, IN, osgWidget::Widget *, x, , IN, bool, x, false,
	                               Properties::NON_VIRTUAL,
	                               Properties::NON_CONST,
	                               __void___setParented__Widget_P1__bool,
	                               "",
	                               "");
	I_ProtectedMethodWithDefaults2(void, _setManaged, IN, osgWidget::Widget *, x, , IN, bool, x, false,
	                               Properties::NON_VIRTUAL,
	                               Properties::NON_CONST,
	                               __void___setManaged__Widget_P1__bool,
	                               "",
	                               "");
	I_ProtectedMethod3(void, _positionWidget, IN, osgWidget::Widget *, x, IN, osgWidget::point_type, x, IN, osgWidget::point_type, x,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void___positionWidget__Widget_P1__point_type__point_type,
	                   "",
	                   "");
	I_ProtectedMethodWithDefaults3(osgWidget::point_type, _getMinWidgetWidth, IN, int, x, 0, IN, int, x, 0, IN, int, x, 1,
	                               Properties::NON_VIRTUAL,
	                               Properties::CONST,
	                               __point_type___getMinWidgetWidth__int__int__int,
	                               "",
	                               "");
	I_ProtectedMethodWithDefaults3(osgWidget::point_type, _getMinWidgetHeight, IN, int, x, 0, IN, int, x, 0, IN, int, x, 1,
	                               Properties::NON_VIRTUAL,
	                               Properties::CONST,
	                               __point_type___getMinWidgetHeight__int__int__int,
	                               "",
	                               "");
	I_ProtectedMethodWithDefaults3(osgWidget::point_type, _getMaxWidgetWidth, IN, int, x, 0, IN, int, x, 0, IN, int, x, 1,
	                               Properties::NON_VIRTUAL,
	                               Properties::CONST,
	                               __point_type___getMaxWidgetWidth__int__int__int,
	                               "",
	                               "");
	I_ProtectedMethodWithDefaults3(osgWidget::point_type, _getMaxWidgetHeight, IN, int, x, 0, IN, int, x, 0, IN, int, x, 1,
	                               Properties::NON_VIRTUAL,
	                               Properties::CONST,
	                               __point_type___getMaxWidgetHeight__int__int__int,
	                               "",
	                               "");
	I_ProtectedMethodWithDefaults3(osgWidget::point_type, _getMinWidgetMinWidth, IN, int, x, 0, IN, int, x, 0, IN, int, x, 1,
	                               Properties::NON_VIRTUAL,
	                               Properties::CONST,
	                               __point_type___getMinWidgetMinWidth__int__int__int,
	                               "",
	                               "");
	I_ProtectedMethodWithDefaults3(osgWidget::point_type, _getMinWidgetMinHeight, IN, int, x, 0, IN, int, x, 0, IN, int, x, 1,
	                               Properties::NON_VIRTUAL,
	                               Properties::CONST,
	                               __point_type___getMinWidgetMinHeight__int__int__int,
	                               "",
	                               "");
	I_ProtectedMethodWithDefaults3(osgWidget::point_type, _getMaxWidgetMinWidth, IN, int, x, 0, IN, int, x, 0, IN, int, x, 1,
	                               Properties::NON_VIRTUAL,
	                               Properties::CONST,
	                               __point_type___getMaxWidgetMinWidth__int__int__int,
	                               "",
	                               "");
	I_ProtectedMethodWithDefaults3(osgWidget::point_type, _getMaxWidgetMinHeight, IN, int, x, 0, IN, int, x, 0, IN, int, x, 1,
	                               Properties::NON_VIRTUAL,
	                               Properties::CONST,
	                               __point_type___getMaxWidgetMinHeight__int__int__int,
	                               "",
	                               "");
	I_ProtectedMethodWithDefaults3(osgWidget::point_type, _getMinWidgetWidthTotal, IN, int, x, 0, IN, int, x, 0, IN, int, x, 1,
	                               Properties::NON_VIRTUAL,
	                               Properties::CONST,
	                               __point_type___getMinWidgetWidthTotal__int__int__int,
	                               "",
	                               "");
	I_ProtectedMethodWithDefaults3(osgWidget::point_type, _getMinWidgetHeightTotal, IN, int, x, 0, IN, int, x, 0, IN, int, x, 1,
	                               Properties::NON_VIRTUAL,
	                               Properties::CONST,
	                               __point_type___getMinWidgetHeightTotal__int__int__int,
	                               "",
	                               "");
	I_ProtectedMethodWithDefaults3(osgWidget::point_type, _getMaxWidgetWidthTotal, IN, int, x, 0, IN, int, x, 0, IN, int, x, 1,
	                               Properties::NON_VIRTUAL,
	                               Properties::CONST,
	                               __point_type___getMaxWidgetWidthTotal__int__int__int,
	                               "",
	                               "");
	I_ProtectedMethodWithDefaults3(osgWidget::point_type, _getMaxWidgetHeightTotal, IN, int, x, 0, IN, int, x, 0, IN, int, x, 1,
	                               Properties::NON_VIRTUAL,
	                               Properties::CONST,
	                               __point_type___getMaxWidgetHeightTotal__int__int__int,
	                               "",
	                               "");
	I_ProtectedMethodWithDefaults3(osgWidget::point_type, _getMinWidgetMinWidthTotal, IN, int, x, 0, IN, int, x, 0, IN, int, x, 1,
	                               Properties::NON_VIRTUAL,
	                               Properties::CONST,
	                               __point_type___getMinWidgetMinWidthTotal__int__int__int,
	                               "",
	                               "");
	I_ProtectedMethodWithDefaults3(osgWidget::point_type, _getMinWidgetMinHeightTotal, IN, int, x, 0, IN, int, x, 0, IN, int, x, 1,
	                               Properties::NON_VIRTUAL,
	                               Properties::CONST,
	                               __point_type___getMinWidgetMinHeightTotal__int__int__int,
	                               "",
	                               "");
	I_ProtectedMethodWithDefaults3(osgWidget::point_type, _getMaxWidgetMinWidthTotal, IN, int, x, 0, IN, int, x, 0, IN, int, x, 1,
	                               Properties::NON_VIRTUAL,
	                               Properties::CONST,
	                               __point_type___getMaxWidgetMinWidthTotal__int__int__int,
	                               "",
	                               "");
	I_ProtectedMethodWithDefaults3(osgWidget::point_type, _getMaxWidgetMinHeightTotal, IN, int, x, 0, IN, int, x, 0, IN, int, x, 1,
	                               Properties::NON_VIRTUAL,
	                               Properties::CONST,
	                               __point_type___getMaxWidgetMinHeightTotal__int__int__int,
	                               "",
	                               "");
	I_ProtectedMethodWithDefaults3(osgWidget::point_type, _getMinWidgetPadHorizontal, IN, int, x, 0, IN, int, x, 0, IN, int, x, 1,
	                               Properties::NON_VIRTUAL,
	                               Properties::CONST,
	                               __point_type___getMinWidgetPadHorizontal__int__int__int,
	                               "",
	                               "");
	I_ProtectedMethodWithDefaults3(osgWidget::point_type, _getMinWidgetPadVertical, IN, int, x, 0, IN, int, x, 0, IN, int, x, 1,
	                               Properties::NON_VIRTUAL,
	                               Properties::CONST,
	                               __point_type___getMinWidgetPadVertical__int__int__int,
	                               "",
	                               "");
	I_ProtectedMethodWithDefaults3(osgWidget::point_type, _getMaxWidgetPadHorizontal, IN, int, x, 0, IN, int, x, 0, IN, int, x, 1,
	                               Properties::NON_VIRTUAL,
	                               Properties::CONST,
	                               __point_type___getMaxWidgetPadHorizontal__int__int__int,
	                               "",
	                               "");
	I_ProtectedMethodWithDefaults3(osgWidget::point_type, _getMaxWidgetPadVertical, IN, int, x, 0, IN, int, x, 0, IN, int, x, 1,
	                               Properties::NON_VIRTUAL,
	                               Properties::CONST,
	                               __point_type___getMaxWidgetPadVertical__int__int__int,
	                               "",
	                               "");
	I_ProtectedMethodWithDefaults3(osgWidget::point_type, _getNumFill, IN, int, x, 0, IN, int, x, 0, IN, int, x, 1,
	                               Properties::NON_VIRTUAL,
	                               Properties::CONST,
	                               __point_type___getNumFill__int__int__int,
	                               "",
	                               "");
	I_ProtectedMethod2(void, _resizeImplementation, IN, osgWidget::point_type, x, IN, osgWidget::point_type, x,
	                   Properties::PURE_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void___resizeImplementation__point_type__point_type,
	                   "",
	                   "");
	I_ProtectedMethod0(osgWidget::Window::Sizes, _getWidthImplementation,
	                   Properties::VIRTUAL,
	                   Properties::CONST,
	                   __Sizes___getWidthImplementation,
	                   "",
	                   "");
	I_ProtectedMethod0(osgWidget::Window::Sizes, _getHeightImplementation,
	                   Properties::VIRTUAL,
	                   Properties::CONST,
	                   __Sizes___getHeightImplementation,
	                   "",
	                   "");
	I_SimpleProperty(osgWidget::XYCoord, AbsoluteOrigin, 
	                 __XYCoord__getAbsoluteOrigin, 
	                 0);
	I_SimpleProperty(osgWidget::Window::HORIZONTAL_ANCHOR, AnchorHorizontal, 
	                 __HORIZONTAL_ANCHOR__getAnchorHorizontal, 
	                 __void__setAnchorHorizontal__HORIZONTAL_ANCHOR);
	I_SimpleProperty(osgWidget::Window::VERTICAL_ANCHOR, AnchorVertical, 
	                 __VERTICAL_ANCHOR__getAnchorVertical, 
	                 __void__setAnchorVertical__VERTICAL_ANCHOR);
	I_SimpleProperty(osgWidget::Widget *, Background, 
	                 __Widget_P1__getBackground, 
	                 0);
	I_SimpleProperty(const osgWidget::Widget *, Focused, 
	                 __C5_Widget_P1__getFocused, 
	                 __bool__setFocused__C5_Widget_P1);
	I_SimpleProperty(osg::Geode *, Geode, 
	                 __osg_Geode_P1__getGeode, 
	                 0);
	I_SimpleProperty(osgWidget::point_type, Height, 
	                 __point_type__getHeight, 
	                 0);
	I_SimpleProperty(unsigned int, Index, 
	                 __unsigned_int__getIndex, 
	                 0);
	I_SimpleProperty(osgWidget::point_type, MinHeight, 
	                 __point_type__getMinHeight, 
	                 0);
	I_SimpleProperty(osgWidget::XYCoord, MinSize, 
	                 __XYCoord__getMinSize, 
	                 0);
	I_SimpleProperty(osgWidget::point_type, MinWidth, 
	                 __point_type__getMinWidth, 
	                 0);
	I_SimpleProperty(osgWidget::XYCoord, Origin, 
	                 __XYCoord__getOrigin, 
	                 0);
	I_SimpleProperty(osgWidget::Window *, Parent, 
	                 __Window_P1__getParent, 
	                 0);
	I_SimpleProperty(osgWidget::Point, Position, 
	                 __Point__getPosition, 
	                 __void__setPosition__C5_Point_R1);
	I_SimpleProperty(osgWidget::matrix_type, Rotate, 
	                 __matrix_type__getRotate, 
	                 __void__setRotate__matrix_type);
	I_SimpleProperty(osgWidget::matrix_type, Scale, 
	                 __matrix_type__getScale, 
	                 __void__setScale__matrix_type);
	I_SimpleProperty(osgWidget::matrix_type, ScaleDenominator, 
	                 __matrix_type__getScaleDenominator, 
	                 __void__setScaleDenominator__matrix_type);
	I_SimpleProperty(osgWidget::XYCoord, Size, 
	                 __XYCoord__getSize, 
	                 0);
	I_SimpleProperty(osgWidget::Window::STRATA, Strata, 
	                 __STRATA__getStrata, 
	                 __void__setStrata__STRATA);
	I_SimpleProperty(osgWidget::Window *, TopmostParent, 
	                 __Window_P1__getTopmostParent, 
	                 0);
	I_SimpleProperty(osgWidget::Window::VISIBILITY_MODE, VisibilityMode, 
	                 __VISIBILITY_MODE__getVisibilityMode, 
	                 __void__setVisibilityMode__VISIBILITY_MODE);
	I_SimpleProperty(const osgWidget::Quad &, VisibleArea, 
	                 __C5_Quad_R1__getVisibleArea, 
	                 0);
	I_SimpleProperty(osgWidget::point_type, Width, 
	                 __point_type__getWidth, 
	                 0);
	I_SimpleProperty(osgWidget::WindowManager *, WindowManager, 
	                 __WindowManager_P1__getWindowManager, 
	                 0);
	I_SimpleProperty(osgWidget::matrix_type, X, 
	                 __matrix_type__getX, 
	                 __void__setX__matrix_type);
	I_SimpleProperty(osgWidget::matrix_type, Y, 
	                 __matrix_type__getY, 
	                 __void__setY__matrix_type);
	I_SimpleProperty(osgWidget::matrix_type, Z, 
	                 __matrix_type__getZ, 
	                 0);
	I_SimpleProperty(osgWidget::matrix_type, ZRange, 
	                 __matrix_type__getZRange, 
	                 0);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgWidget::Window::EmbeddedWindow)
	I_DeclaringFile("osgWidget/Window");
	I_BaseType(osgWidget::Widget);
	I_Method0(osg::Object *, cloneType,
	          Properties::VIRTUAL,
	          __osg_Object_P1__cloneType,
	          "Clone the type of an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop,
	          Properties::VIRTUAL,
	          __osg_Object_P1__clone__C5_osg_CopyOp_R1,
	          "Clone an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj,
	          Properties::VIRTUAL,
	          __bool__isSameKindAs__C5_osg_Object_P1,
	          "",
	          "");
	I_Method0(const char *, libraryName,
	          Properties::VIRTUAL,
	          __C5_char_P1__libraryName,
	          "return the name of the object's library. ",
	          "Must be defined by derived classes. The OpenSceneGraph convention is that the namespace of a library is the same as the library name. ");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "return the name of the object's class type. ",
	          "Must be defined by derived classes. ");
	I_Method1(, META_UIObject, IN, osgWidget::Window::EmbeddedWindow, x,
	          Properties::NON_VIRTUAL,
	          ____META_UIObject__EmbeddedWindow,
	          "",
	          "");
	I_ConstructorWithDefaults3(IN, const std::string &, x, "", IN, osgWidget::point_type, x, 0.0f, IN, osgWidget::point_type, x, 0.0f,
	                           ____EmbeddedWindow__C5_std_string_R1__point_type__point_type,
	                           "",
	                           "");
	I_Constructor2(IN, const osgWidget::Window::EmbeddedWindow &, x, IN, const osg::CopyOp &, x,
	               ____EmbeddedWindow__C5_EmbeddedWindow_R1__C5_osg_CopyOp_R1,
	               "",
	               "");
	I_Method1(void, parented, IN, osgWidget::Window *, x,
	          Properties::VIRTUAL,
	          __void__parented__Window_P1,
	          "",
	          "");
	I_Method1(void, unparented, IN, osgWidget::Window *, x,
	          Properties::VIRTUAL,
	          __void__unparented__Window_P1,
	          "",
	          "");
	I_Method1(void, managed, IN, osgWidget::WindowManager *, x,
	          Properties::VIRTUAL,
	          __void__managed__WindowManager_P1,
	          "",
	          "");
	I_Method1(void, unmanaged, IN, osgWidget::WindowManager *, x,
	          Properties::VIRTUAL,
	          __void__unmanaged__WindowManager_P1,
	          "",
	          "");
	I_Method0(void, positioned,
	          Properties::VIRTUAL,
	          __void__positioned,
	          "",
	          "");
	I_Method1(bool, setWindow, IN, osgWidget::Window *, x,
	          Properties::NON_VIRTUAL,
	          __bool__setWindow__Window_P1,
	          "",
	          "");
	I_Method0(osgWidget::Window *, getWindow,
	          Properties::NON_VIRTUAL,
	          __Window_P1__getWindow,
	          "",
	          "");
	I_Method0(const osgWidget::Window *, getWindow,
	          Properties::NON_VIRTUAL,
	          __C5_Window_P1__getWindow,
	          "",
	          "");
	I_SimpleProperty(osgWidget::Window *, Window, 
	                 __Window_P1__getWindow, 
	                 __bool__setWindow__Window_P1);
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osgWidget::Window::Sizes)
	I_DeclaringFile("osgWidget/Window");
	I_ConstructorWithDefaults2(IN, osgWidget::point_type, c, -1.0f, IN, osgWidget::point_type, m, -1.0f,
	                           ____Sizes__point_type__point_type,
	                           "",
	                           "");
	I_PublicMemberProperty(osgWidget::point_type, cur);
	I_PublicMemberProperty(osgWidget::point_type, min);
END_REFLECTOR

TYPE_NAME_ALIAS(osgWidget::Window::WindowList, osgWidget::WindowList)

BEGIN_OBJECT_REFLECTOR(osg::observer_ptr< osgWidget::Window >)
	I_DeclaringFile("osg/observer_ptr");
	I_BaseType(osg::Observer);
	I_Constructor0(____observer_ptr,
	               "",
	               "");
	I_Constructor1(IN, osgWidget::Window *, t,
	               Properties::NON_EXPLICIT,
	               ____observer_ptr__T_P1,
	               "",
	               "");
	I_Constructor1(IN, const osg::observer_ptr< osgWidget::Window > &, rp,
	               Properties::NON_EXPLICIT,
	               ____observer_ptr__C5_observer_ptr_R1,
	               "",
	               "");
	I_Method1(void, objectDeleted, IN, void *, x,
	          Properties::VIRTUAL,
	          __void__objectDeleted__void_P1,
	          "",
	          "");
	I_Method0(osgWidget::Window *, get,
	          Properties::NON_VIRTUAL,
	          __T_P1__get,
	          "",
	          "");
	I_Method0(bool, valid,
	          Properties::NON_VIRTUAL,
	          __bool__valid,
	          "",
	          "");
	I_SimpleProperty(osgWidget::Window *, , 
	                 __T_P1__get, 
	                 0);
END_REFLECTOR

STD_LIST_REFLECTOR(std::list< osg::observer_ptr< osgWidget::Window > >)

