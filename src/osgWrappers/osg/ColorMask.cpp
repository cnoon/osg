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

#include <osg/ColorMask>
#include <osg/CopyOp>
#include <osg/Object>
#include <osg/State>
#include <osg/StateAttribute>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osg::ColorMask)
	I_BaseType(osg::StateAttribute);
	I_Constructor0();
	I_Constructor4(IN, bool, red, IN, bool, green, IN, bool, blue, IN, bool, alpha);
	I_ConstructorWithDefaults2(IN, const osg::ColorMask &, cm, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY);
	I_Method0(osg::Object *, cloneType);
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop);
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj);
	I_Method0(const char *, libraryName);
	I_Method0(const char *, className);
	I_Method0(osg::StateAttribute::Type, getType);
	I_Method1(int, compare, IN, const osg::StateAttribute &, sa);
	I_Method4(void, setMask, IN, bool, red, IN, bool, green, IN, bool, blue, IN, bool, alpha);
	I_Method1(void, setRedMask, IN, bool, mask);
	I_Method0(bool, getRedMask);
	I_Method1(void, setGreenMask, IN, bool, mask);
	I_Method0(bool, getGreenMask);
	I_Method1(void, setBlueMask, IN, bool, mask);
	I_Method0(bool, getBlueMask);
	I_Method1(void, setAlphaMask, IN, bool, mask);
	I_Method0(bool, getAlphaMask);
	I_Method1(void, apply, IN, osg::State &, state);
	I_Property(bool, AlphaMask);
	I_Property(bool, BlueMask);
	I_Property(bool, GreenMask);
	I_Property(bool, RedMask);
	I_ReadOnlyProperty(osg::StateAttribute::Type, Type);
END_REFLECTOR

