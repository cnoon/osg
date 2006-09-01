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
#include <osg/NodeVisitor>
#include <osg/Object>
#include <osgParticle/ModularProgram>
#include <osgParticle/Operator>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osgParticle::ModularProgram)
	I_BaseType(osgParticle::Program);
	I_Constructor0();
	I_ConstructorWithDefaults2(IN, const osgParticle::ModularProgram &, copy, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY);
	I_Method0(osg::Object *, cloneType);
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop);
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj);
	I_Method0(const char *, className);
	I_Method0(const char *, libraryName);
	I_Method1(void, accept, IN, osg::NodeVisitor &, nv);
	I_Method0(int, numOperators);
	I_Method1(void, addOperator, IN, osgParticle::Operator *, o);
	I_Method1(osgParticle::Operator *, getOperator, IN, int, i);
	I_Method1(const osgParticle::Operator *, getOperator, IN, int, i);
	I_Method1(void, removeOperator, IN, int, i);
END_REFLECTOR

