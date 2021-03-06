##
# $Id: $
#
# (c) Red Pitaya  http://www.redpitaya.com
#
# Test app for library project file. To build executable for acquire utility run:
# 'make all'
#
# This project file is written for GNU/Make software. For more details please 
# visit: http://www.gnu.org/software/make/manual/make.html
# GNU Compiler Collection (GCC) tools are used for the compilation and linkage. 
# For the details about the usage and building please visit:
# http://gcc.gnu.org/onlinedocs/gcc/
#

# Versioning system
VERSION ?= 0.00-0000
REVISION ?= devbuild

# List of compiled object files (not yet linked to executable)
OBJS = test.o

CALIB_C = calibrateApp.c
CALIB2_C = calibrateApp2.c

# Executable name
TARGET=testApp
CALIBRATE=calibrateApp
CALIBRATE2=calibrateApp2

# GCC compiling & linking flags
CFLAGS  =-g -std=gnu99 -Wall -Werror -I../../api/rpbase/src
CFLAGS += -DVERSION=$(VERSION) -DREVISION=$(REVISION)

# Red Pitaya common SW directory
SHARED=../../shared/

# Additional libraries which needs to be dynamically linked to the executable
# -lm - System math library (used by cos(), sin(), sqrt(), ... functions)
LIBPATH= -L ../../api/lib
LIBS= -lm -lpthread -lrp

# Main GCC executable (used for compiling and linking)
CC=$(CROSS_COMPILE)gcc
# Installation directory
INSTALL_DIR ?= .

# Main Makefile target 'all' - it iterates over all targets listed in $(TARGET)
# variable.
all: $(TARGET) $(CALIBRATE) $(CALIBRATE2)

# Target with compilation rules to compile object from source files.
# It applies to all files ending with .o. During partial building only new object
# files are created for the source files (.c) which have newer timestamp then 
# objects (.o) files.
%.o: %.c version.h
	$(CC) -c $(CFLAGS) $< -o $@

# Makefile target with rules how to link executable for each target from $(TARGET)
# list.
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBPATH) $(LIBS)

$(CALIBRATE):
	$(CC) -o $@ $(CALIB_C) $(CFLAGS) $(LIBPATH) $(LIBS)

$(CALIBRATE2):
	$(CC) -o $@ $(CALIB2_C) $(CFLAGS) $(LIBPATH) $(LIBS)

# Version header for traceability
version.h:
	cp $(SHARED)/include/redpitaya/version.h . 

# Clean target - when called it cleans all object files and executables.
clean:
	rm -f $(CALIBRATE) $(CALIBRATE2) $(TARGET) *.o

# Install target - creates 'bin/' sub-directory in $(INSTALL_DIR) and copies all
# executables to that location.
install:
	mkdir -p $(INSTALL_DIR)/bin
	cp $(TARGET)     $(INSTALL_DIR)/bin
	cp $(CALIBRATE)  $(INSTALL_DIR)/bin
	cp $(CALIBRATE2) $(INSTALL_DIR)/bin	
