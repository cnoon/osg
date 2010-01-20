/* -*-c++-*- OpenSceneGraph - Copyright (C) 1998-2010 Robert Osfield
 *
 * This library is open source and may be redistributed and/or modified under
 * the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or
 * (at your option) any later version.  The full license is in LICENSE file
 * included with this distribution, and on the openscenegraph.org website.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * OpenSceneGraph Public License for more details.
*/
// Written by Wang Rui, (C) 2010

#include <osg/Notify>
#include <osg/ImageSequence>
#include <osgDB/ReadFile>
#include <osgDB/XmlParser>
#include <osgDB/FileNameUtils>
#include <osgDB/ObjectWrapper>

using namespace osgDB;

static std::string s_lastSchema;

InputStream::InputStream( std::istream* istream, const osgDB::Options* options )
:   _readMode(READ_BINARY), _byteSwap(0), _useFloatMatrix(false),
    _in(istream)
{
    if ( !_in )
        throw InputException(_currentField, "InputStream: Null stream specified.");
    if ( !options ) return;
    
    std::string schema;
    StringList optionList;
    split( options->getOptionString(), optionList );
    for ( StringList::iterator itr=optionList.begin(); itr!=optionList.end(); ++itr )
    {
        const std::string& option = *itr;
        if ( option=="Ascii" )
            _readMode = READ_ASCII;
        else
        {
            StringList keyAndValues;
            split( option, keyAndValues, '=' );
            if ( keyAndValues.size()<2 ) continue;
            
            if ( keyAndValues[0]=="SchemaFile" )
            {
                schema = keyAndValues[1];
                if ( s_lastSchema!=schema )
                {
                    osgDB::ifstream schemaStream( schema.c_str(), std::ios::in );
                    if ( !schemaStream.fail() ) readSchema( schemaStream );
                    schemaStream.close();
                    s_lastSchema = schema;
                }
            }
            else
                osg::notify(osg::WARN) << "InputStream: Unknown option " << option << std::endl;
        }
    }
    if ( schema.empty() )
    {
        resetSchema();
        s_lastSchema.clear();
    }
}

InputStream::~InputStream()
{
}

InputStream& InputStream::operator>>( osg::Vec2b& v )
{
    char x, y; *this >> x >> y;
    v.set( x, y );
    return *this;
}

InputStream& InputStream::operator>>( osg::Vec3b& v )
{
    char x, y, z; *this >> x >> y >> z;
    v.set( x, y, z );
    return *this;
}

InputStream& InputStream::operator>>( osg::Vec4b& v )
{
    char x, y, z, w; *this >> x >> y >> z >> w;
    v.set( x, y, z, w );
    return *this;
}

InputStream& InputStream::operator>>( osg::Vec4ub& v )
{
    char r, g, b, a; *this >> r >> g >> b >> a;
    v.set( r, g, b, a );
    return *this;
}

InputStream& InputStream::operator>>( osg::Vec2s& v )
{ *this >> v.x() >> v.y(); return *this; }

InputStream& InputStream::operator>>( osg::Vec3s& v )
{ *this >> v.x() >> v.y() >> v.z(); return *this; }

InputStream& InputStream::operator>>( osg::Vec4s& v )
{ *this >> v.x() >> v.y() >> v.z() >> v.w(); return *this; }

InputStream& InputStream::operator>>( osg::Vec2f& v )
{ *this >> v.x() >> v.y(); return *this; }

InputStream& InputStream::operator>>( osg::Vec3f& v )
{ *this >> v.x() >> v.y() >> v.z(); return *this; }

InputStream& InputStream::operator>>( osg::Vec4f& v )
{ *this >> v.x() >> v.y() >> v.z() >> v.w(); return *this; }

InputStream& InputStream::operator>>( osg::Vec2d& v )
{ *this >> v.x() >> v.y(); return *this; }

InputStream& InputStream::operator>>( osg::Vec3d& v )
{ *this >> v.x() >> v.y() >> v.z(); return *this; }

InputStream& InputStream::operator>>( osg::Vec4d& v )
{ *this >> v.x() >> v.y() >> v.z() >> v.w(); return *this; }

InputStream& InputStream::operator>>( osg::Quat& q )
{ *this >> q.x() >> q.y() >> q.z() >> q.w(); return *this; }

InputStream& InputStream::operator>>( osg::Plane& p )
{
    double p0, p1, p2, p3; *this >> p0 >> p1 >> p2 >> p3;
    p.set( p0, p1, p2, p3 ); return *this;
}

InputStream& InputStream::operator>>( osg::Matrixf& mat )
{
    *this >> PROPERTY("Matrixf") >> BEGIN_BRACKET;
    for ( int r=0; r<4; ++r )
    {
        *this >> mat(r, 0) >> mat(r, 1) >> mat(r, 2) >> mat(r, 3);
    }
    *this >> END_BRACKET;
    return *this;
}

InputStream& InputStream::operator>>( osg::Matrixd& mat )
{
    *this >> PROPERTY("Matrixd") >> BEGIN_BRACKET;
    for ( int r=0; r<4; ++r )
    {
        *this >> mat(r, 0) >> mat(r, 1) >> mat(r, 2) >> mat(r, 3);
    }
    *this >> END_BRACKET;
    return *this;
}

InputStream& InputStream::operator>>( ObjectGLenum& value )
{
    GLenum e = 0;
    if ( isBinary() )
    {
        _in->read( (char*)&e, GLENUM_SIZE ); checkStream();
        if ( _byteSwap ) osg::swapBytes( (char*)&e, GLENUM_SIZE );
    }
    else
    {
        std::string enumString;
        *this >> enumString;
        e = GlobalLookupTable::instance()->getValue("GL", enumString);
    }
    value.set( e );
    return *this;
}

InputStream& InputStream::operator>>( ObjectProperty& prop )
{
    int value = 0;
    if ( isBinary() )
    {
        if ( prop._mapProperty )
        {
            _in->read( (char*)&value, INT_SIZE ); checkStream();
            if ( _byteSwap ) osg::swapBytes( (char*)&value, INT_SIZE );
        }
    }
    else
    {
        std::string enumString;
        *this >> enumString;
        if ( prop._mapProperty )
        {
            value =
                GlobalLookupTable::instance()->getValue(prop._name, enumString);
        }
        else
        {
            if ( prop._name!=enumString )
            {
                osg::notify(osg::WARN) << "InputStream::operator>>(ObjectProperty&): Unmatched property "
                                       << enumString << ", expecting " << prop._name
                                       << ". At " << _currentField << std::endl;
            }
            prop._name = enumString;
        }
    }
    prop.set( value );
    return *this;
}

InputStream& InputStream::operator>>( ObjectMark& mark )
{
    if ( !isBinary() )
    {
        std::string markString;
        *this >> markString;
    }
    return *this;
}

osg::Array* InputStream::readArray()
{
    osg::ref_ptr<osg::Array> array = NULL;
    
    unsigned int id = 0;
    *this >> PROPERTY("ArrayID") >> id;
    
    ArrayMap::iterator itr = _arrayMap.find( id );
    if ( itr!=_arrayMap.end() ) return itr->second.get();
    
    DEF_MAPPEE(ArrayType, type);
    *this >> type;
    switch ( type.get() )
    {
    case ID_BYTE_ARRAY:
        {
            osg::ByteArray* ba = new osg::ByteArray;
            readArrayImplementation( ba, CHAR_SIZE, true );
            array = ba;
        }
        break;
    case ID_UBYTE_ARRAY:
        {
            osg::UByteArray* uba = new osg::UByteArray;
            readArrayImplementation( uba, CHAR_SIZE, true );
            array = uba;
        }
        break;
    case ID_SHORT_ARRAY:
        {
            osg::ShortArray* sa = new osg::ShortArray;
            readArrayImplementation( sa, SHORT_SIZE, true );
            array = sa;
        }
        break;
    case ID_USHORT_ARRAY:
        {
            osg::UShortArray* usa = new osg::UShortArray;
            readArrayImplementation( usa, SHORT_SIZE, true );
            array = usa;
        }
        break;
    case ID_INT_ARRAY:
        {
            osg::IntArray* ia = new osg::IntArray;
            readArrayImplementation( ia, INT_SIZE, true );
            array = ia;
        }
        break;
    case ID_UINT_ARRAY:
        {
            osg::UIntArray* uia = new osg::UIntArray;
            readArrayImplementation( uia, INT_SIZE, true );
            array = uia;
        }
        break;
    case ID_FLOAT_ARRAY:
        {
            osg::FloatArray* fa = new osg::FloatArray;
            readArrayImplementation( fa, FLOAT_SIZE, true );
            array = fa;
        }
        break;
    case ID_DOUBLE_ARRAY:
        {
            osg::DoubleArray* da = new osg::DoubleArray;
            readArrayImplementation( da, DOUBLE_SIZE, true );
            array = da;
        }
        break;
    case ID_VEC2B_ARRAY:
        {
            osg::Vec2bArray* va = new osg::Vec2bArray;
            readArrayImplementation( va, 2*CHAR_SIZE );
            array = va;
        }
        break;
    case ID_VEC3B_ARRAY:
        {
            osg::Vec3bArray* va = new osg::Vec3bArray;
            readArrayImplementation( va, 3*CHAR_SIZE );
            array = va;
        }
        break;
    case ID_VEC4B_ARRAY:
        {
            osg::Vec4bArray* va = new osg::Vec4bArray;
            readArrayImplementation( va, 4*CHAR_SIZE );
            array = va;
        }
        break;
    case ID_VEC4UB_ARRAY:
        {
            osg::Vec4ubArray* va = new osg::Vec4ubArray;
            readArrayImplementation( va, 4*CHAR_SIZE );
            array = va;
        }
        break;
    case ID_VEC2S_ARRAY:
        {
            osg::Vec2sArray* va = new osg::Vec2sArray;
            readArrayImplementation( va, 2*SHORT_SIZE );
            array = va;
        }
        break;
    case ID_VEC3S_ARRAY:
        {
            osg::Vec3sArray* va = new osg::Vec3sArray;
            readArrayImplementation( va, 3*SHORT_SIZE );
            array = va;
        }
        break;
    case ID_VEC4S_ARRAY:
        {
            osg::Vec4sArray* va = new osg::Vec4sArray;
            readArrayImplementation( va, 4*SHORT_SIZE );
            array = va;
        }
        break;
    case ID_VEC2_ARRAY:
        {
            osg::Vec2Array* va = new osg::Vec2Array;
            readArrayImplementation( va, 2*FLOAT_SIZE );
            array = va;
        }
        break;
    case ID_VEC3_ARRAY:
        {
            osg::Vec3Array* va = new osg::Vec3Array;
            readArrayImplementation( va, 3*FLOAT_SIZE );
            array = va;
        }
        break;
    case ID_VEC4_ARRAY:
        {
            osg::Vec4Array* va = new osg::Vec4Array;
            readArrayImplementation( va, 4*FLOAT_SIZE );
            array = va;
        }
        break;
    case ID_VEC2D_ARRAY:
        {
            osg::Vec2dArray* va = new osg::Vec2dArray;
            readArrayImplementation( va, 2*DOUBLE_SIZE );
            array = va;
        }
        break;
    case ID_VEC3D_ARRAY:
        {
            osg::Vec3dArray* va = new osg::Vec3dArray;
            readArrayImplementation( va, 3*DOUBLE_SIZE );
            array = va;
        }
        break;
    case ID_VEC4D_ARRAY:
        {
            osg::Vec4dArray* va = new osg::Vec4dArray;
            readArrayImplementation( va, 4*DOUBLE_SIZE );
            array = va;
        }
        break;
    default:
        throw InputException(_currentField, "InputStream::readArray(): Unsupported array type.");
    }
    
    _arrayMap[id] = array;
    return array.release();
}

osg::PrimitiveSet* InputStream::readPrimitiveSet()
{
    osg::ref_ptr<osg::PrimitiveSet> primitive = NULL;
    
    DEF_MAPPEE(PrimitiveType, type);
    DEF_MAPPEE(PrimitiveType, mode);
    *this >> type >> mode;
    
    switch ( type.get() )
    {
    case ID_DRAWARRAYS:
        {
            int first = 0, count = 0;
            *this >> first >> count;
            osg::DrawArrays* da = new osg::DrawArrays( mode.get(), first, count );
            primitive = da;
        }
        break;
    case ID_DRAWARRAY_LENGTH:
        {
            int first = 0, value = 0; unsigned int size = 0;
            *this >> first >> size >> BEGIN_BRACKET;
            osg::DrawArrayLengths* dl = new osg::DrawArrayLengths( mode.get(), first );
            for ( unsigned int i=0; i<size; ++i )
            {
                *this >> value;
                dl->push_back( value );
            }
            *this >> END_BRACKET;
            primitive = dl;
        }
        break;
    case ID_DRAWELEMENTS_UBYTE:
        {
            osg::DrawElementsUByte* de = new osg::DrawElementsUByte( mode.get() );
            unsigned int size = 0; unsigned char value = 0;
            *this >> size >> BEGIN_BRACKET;
            for ( unsigned int i=0; i<size; ++i )
            {
                *this >> value;
                de->push_back( value );
            }
            *this >> END_BRACKET;
            primitive = de;
        }
        break;
    case ID_DRAWELEMENTS_USHORT:
        {
            osg::DrawElementsUShort* de = new osg::DrawElementsUShort( mode.get() );
            unsigned int size = 0; unsigned short value = 0;
            *this >> size >> BEGIN_BRACKET;
            for ( unsigned int i=0; i<size; ++i )
            {
                *this >> value;
                de->push_back( value );
            }
            *this >> END_BRACKET;
            primitive = de;
        }
        break;
    case ID_DRAWELEMENTS_UINT:
        {
            osg::DrawElementsUInt* de = new osg::DrawElementsUInt( mode.get() );
            unsigned int size = 0, value = 0;
            *this >> size >> BEGIN_BRACKET;
            for ( unsigned int i=0; i<size; ++i )
            {
                *this >> value;
                de->push_back( value );
            }
            *this >> END_BRACKET;
            primitive = de;
        }
        break;
    default:
        throw InputException(_currentField, "InputStream::readPrimitiveSet(): Unsupported array type.");
    }
    return primitive.release();
}

osg::Image* InputStream::readImage()
{
    std::string name;
    int writeHint, decision = IMAGE_EXTERNAL;
    *this >> PROPERTY("FileName"); readWrappedString(name);
    *this >> PROPERTY("WriteHint") >> writeHint >> decision;
    
    osg::ref_ptr<osg::Image> image = NULL;
    bool readFromExternal = true;
    switch ( decision )
    {
    case IMAGE_INLINE_DATA:
        if ( isBinary() )
        {
            image = new osg::Image;
            
            // _origin, _s & _t & _r, _internalTextureFormat
            int origin, s, t, r, internalFormat;
            *this >> origin >> s >> t >> r >> internalFormat;
            
            // _pixelFormat, _dataType, _packing, _allocationMode
            int pixelFormat, dataType, packing, mode;
            *this >> pixelFormat >> dataType >> packing >> mode;
            
            // _data
            unsigned int size = 0; *this >> size;
            if ( size )
            {
                char* data = new char[size];
                if ( !data )
                    throw InputException(_currentField, "InputStream::readImage() Out of memory.");
                readCharArray( data, size );
                image->setOrigin( (osg::Image::Origin)origin );
                image->setImage( s, t, r, internalFormat, pixelFormat, dataType,
                    (unsigned char*)data, (osg::Image::AllocationMode)mode, packing );
            }
            
            // _mipmapData
            unsigned int levelSize = 0; *this >> levelSize;
            osg::Image::MipmapDataType levels(levelSize);
            for ( unsigned int i=0; i<levelSize; ++i )
            {
                *this >> levels[i];
            }
            if ( levelSize>0 )
                image->setMipmapLevels( levels );
            readFromExternal = false;
        }
        break;
    case IMAGE_INLINE_FILE:
        if ( isBinary() )
        {
            unsigned int size = 0; *this >> size;
            if ( size>0 )
            {
                char* data = new char[size];
                if ( !data )
                    throw InputException(_currentField, "InputStream::readImage(): Out of memory.");
                readCharArray( data, size );
                
                std::string ext = osgDB::getFileExtension( name );
                osgDB::ReaderWriter* reader =
                    osgDB::Registry::instance()->getReaderWriterForExtension( ext );
                if ( reader )
                {
                    std::stringstream inputStream;
                    inputStream.write( data, size );
                    
                    osgDB::ReaderWriter::ReadResult rr = reader->readImage( inputStream );
                    if ( rr.validImage() )
                        image = rr.takeImage();
                    else
                    {
                        osg::notify(osg::WARN) << "InputStream::readImage(): "
                                               << rr.message() << std::endl;
                    }
                }
                else
                {
                    osg::notify(osg::WARN) << "InputStream::readImage(): Unable to find a plugin for "
                                           << ext << std::endl;
                }
                delete[] data;
            }
            readFromExternal = false;
        }
        break;
    case IMAGE_EXTERNAL: case IMAGE_WRITE_OUT:
        break;
    default:
        break;
    }
    
    if ( readFromExternal )
        image = osgDB::readImageFile( name );
    if ( image.valid() )
    {
        image->setFileName( name );
        image->setWriteHint( (osg::Image::WriteHint)writeHint );
    }
    
    image = static_cast<osg::Image*>( readObject(image.get()) );
    return image.release();
}

osg::Object* InputStream::readObject( osg::Object* existingObj )
{
    std::string className;
    unsigned int id = 0;
    *this >> className >> BEGIN_BRACKET >> PROPERTY("UniqueID") >> id;
    
    IdentifierMap::iterator itr = _identifierMap.find( id );
    if ( itr!=_identifierMap.end() )
    {
        advanceToCurrentEndBracket();
        return itr->second.get();
    }
    
    ObjectWrapper* wrapper = ObjectRegistry::instance()->findWrapper( className );
    if ( !wrapper )
    {
        osg::notify(osg::WARN) << "InputStream::readObject(): Unsupported wrapper class "
                               << className << std::endl;
        advanceToCurrentEndBracket();
        return NULL;
    }
    osg::ref_ptr<osg::Object> obj = existingObj ? existingObj : wrapper->getProto()->cloneType();
    if ( obj.valid() )
    {
        _identifierMap[id] = obj;
        
        const StringList& associates = wrapper->getAssociates();
        for ( StringList::const_iterator itr=associates.begin(); itr!=associates.end(); ++itr )
        {
            ObjectWrapper* assocWrapper = ObjectRegistry::instance()->findWrapper(*itr);
            if ( !assocWrapper )
            {
                osg::notify(osg::WARN) << "InputStream::readObject(): Unsupported associated class "
                                       << *itr << std::endl;
                continue;
            }
            
            _currentField = assocWrapper->getName();
            assocWrapper->read( *this, *obj );
        }
    }
    advanceToCurrentEndBracket();
    return obj.release();
}

void InputStream::readSchema( std::istream& fin )
{
    // Read from external ascii stream
    std::string line;
    while ( std::getline(fin, line) )
    {
        if ( line[0]=='#' ) continue;  // Comment
        
        StringList keyAndValue;
        split( line, keyAndValue, '=' );
        if ( keyAndValue.size()<2 ) continue;
        
        setWrapperSchema( osgDB::trimEnclosingSpaces(keyAndValue[0]),
                          osgDB::trimEnclosingSpaces(keyAndValue[1]) );
    }
}

InputStream::ReadType InputStream::start()
{
    ReadType type = READ_UNKNOWN;
    _currentField = "Header";
    
    // Check OSG header information
    unsigned int version = 0;
    if ( isBinary() )
    {
        unsigned int headerLow = 0, headerHigh = 0;
        *this >> headerLow >> headerHigh;
        if ( headerLow!=OSG_HEADER_LOW || headerHigh!=OSG_HEADER_HIGH )
        {
            _in->seekg( 0, std::ios::beg );
            _readMode = READ_ASCII;
        }
        else
        {
            unsigned int typeValue;
            *this >> typeValue >> version;
            type = static_cast<ReadType>(typeValue);
            
            unsigned int matrixValueType; *this >> matrixValueType;
            if ( matrixValueType==0 ) _useFloatMatrix = true;
            else _useFloatMatrix = false;
        }
    }
    if ( !isBinary() )
    {
        DEF_PROPERTY("#Ascii", header); *this >> header;
        if ( header._name!="#Ascii" ) return READ_UNKNOWN;
        
        std::string typeString; *this >> typeString;
        if ( typeString=="Scene" ) type = READ_SCENE;
        else if ( typeString=="Image" ) type = READ_IMAGE;
        
        std::string osgName, osgVersion;
        *this >> PROPERTY("#Version") >> version;
        *this >> PROPERTY("#Generator") >> osgName >> osgVersion;
    }
    
    // Check file version
    if ( version!=PLUGIN_VERSION )
    {
        osg::notify(osg::WARN) << "InputStream: Input data version " << version
                               << " may be incompatible with current reader version "
                               << PLUGIN_VERSION << std::endl;
    }
    return type;
}

void InputStream::decompress()
{
    _currentField = "Decompression";
    if ( !isBinary() ) return;
    
    std::string compressorName; *this >> compressorName;
    if ( compressorName=="0" ) return;
    
    BaseCompressor* compressor =
        ObjectRegistry::instance()->findCompressor(compressorName);
    if ( !compressor )
    {
        osg::notify(osg::WARN) << "InputStream::decompress(): No such compressor "
                               << compressorName << std::endl;
    }
    
    std::string data;
    if ( !compressor->decompress(*_in, data) )
        throw InputException(_currentField, "InputStream: Failed to decompress stream.");
    _in = new std::stringstream(data);
}

// PROTECTED METHODS

void InputStream::setWrapperSchema( const std::string& name, const std::string& properties )
{
    ObjectWrapper* wrapper = ObjectRegistry::instance()->findWrapper(name);
    if ( !wrapper )
    {
        osg::notify(osg::WARN) << "InputStream::setSchema(): Unsupported wrapper class "
                               << name << std::endl;
        return;
    }
    
    StringList schema;
    split( properties, schema );
    wrapper->readSchema( schema );
}

void InputStream::resetSchema()
{
    const ObjectRegistry::WrapperMap& wrappers = ObjectRegistry::instance()->getWrapperMap();
    for ( ObjectRegistry::WrapperMap::const_iterator itr=wrappers.begin();
          itr!=wrappers.end(); ++itr )
    {
        ObjectWrapper* wrapper = itr->second.get();
        wrapper->resetSchema();
    }
}

template<typename T>
void InputStream::readArrayImplementation( T* a, int readSize, bool useByteSwap )
{
    int size = 0;
    *this >> size >> BEGIN_BRACKET;
    if ( size )
    {
        a->resize( size );
        if ( isBinary() )
        {
            _in->read( (char*)&((*a)[0]), readSize*size ); checkStream();
            if ( useByteSwap && _byteSwap )
            {
                for ( int i=0; i<size; ++i )
                    osg::swapBytes( (char*)&((*a)[i]), readSize );
            }
        }
        else
        {
            for ( int i=0; i<size; ++i )
                *this >> (*a)[i];
        }
    }
    *this >> END_BRACKET;
}
