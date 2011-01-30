# This directory contains a heavily stripped down variant of
# fblend. I threw away the assember variants of the blending functions
# as getting them to build involved some higher magic.

ADD_LIBRARY(fblend
	src/rtrans.c
	src/fade.c
	src/radd.c
	src/ctrans.c
	src/csub.c
	src/2xstretch.c
	src/cadd.c
)

INCLUDE_DIRECTORIES(include)

