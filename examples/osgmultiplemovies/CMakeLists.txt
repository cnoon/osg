# INCLUDE_DIRECTORIES( ${OPENAL_INCLUDE_DIR} )
# SET(TARGET_EXTERNAL_LIBRARIES ${OPENAL_LIBRARY} alut)

IF (SDL_FOUND)
    SET(TARGET_EXTERNAL_LIBRARIES ${SDL_LIBRARY} )
    INCLUDE_DIRECTORIES(${SDL_INCLUDE_DIR} )
    ADD_DEFINITIONS(-DUSE_SDL)
    IF (MINGW)
        SET(TARGET_EXTERNAL_LIBRARIES ${TARGET_EXTERNAL_LIBRARIES} winmm dinput ddraw dxguid)
    ENDIF()
ENDIF(SDL_FOUND)

SET(TARGET_SRC osgmultiplemovies.cpp )
SET(TARGET_ADDED_LIBRARIES osgGA )



#### end var setup  ###
SETUP_EXAMPLE(osgmultiplemovies)
