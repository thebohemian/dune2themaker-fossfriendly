# This directory contains a cleaned up tarball of almp3 and
# a CMakeLists.txt which compiles this into a library to be
# used by the Dune2 The Maker build.

ADD_LIBRARY(almp3 
	src/almp3.c
	decoder/tabinit.c
	decoder/common.c
	decoder/decode_i386.c
	decoder/layer3.c
	decoder/dct64_i386.c
	decoder/interface.c
	decoder/layer2.c
)

INCLUDE_DIRECTORIES ( include decoder )
