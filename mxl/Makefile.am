AM_CPPFLAGS= $(all_includes)
lib_LTLIBRARIES=libMXL.la
libMXL_includedir=$(includedir)/mxl
libMXL_include_HEADERS=mxl.hpp symbol.hpp
libMXL_la_SOURCES=mxl.cpp lex.mxl.cc parser.tab.cpp
libMXL_la_CXXFLAGS=-std=c++11 -Wno-deprecated-register
include_dir=mxl/
pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = ../mxl.pc
