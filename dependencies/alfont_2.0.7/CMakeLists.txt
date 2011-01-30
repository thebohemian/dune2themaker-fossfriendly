# This directory contains a cleaned up alfont 2.0.7 tarball
# and this CMakeLists.txt file building this little
# pile of C code into a library.
INCLUDE_DIRECTORIES("include" "/usr/include/freetype2")

ADD_LIBRARY (alfont
	src/alfont.c
)
TARGET_LINK_LIBRARIES (alfont freetype)

SET_TARGET_PROPERTIES( alfont
        PROPERTIES
                COMPILE_FLAGS "-DUNIX"
)
