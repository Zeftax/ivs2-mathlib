###################################################
# Project name: ivs2-mathlib
# Date:         2023-04-23
# File:         Makefile
#
# Author: Zdeněk Borovec <xborov08@vutbr.cz>
# Author: Tomáš Krejčí   <xkrejc84@vutbr.cz>
# Author: Jan Lozrt      <xlozrt00@vutbr.cz>
# Author: Jakub Mitrenga <xmitre07@vutbr.cz>
#
# Description: 
#   This library aims to serve the needs of our second IVS project in the
#   academic year of 2022/2023 on BUT.
# 
###################################################

ROOTDIR    = .
BUILDDIR   = _build


# == INSTALLATION TARGETS ==
.PHONY: all test mathlib

# compiles the project
all: mathlib

# runs math library tests
test: mathlib
	cd $(ROOTDIR)/$(BUILDDIR) && make test

# installs the library
mathlib:
	mkdir -p $(ROOTDIR)/$(BUILDDIR) && cd $(ROOTDIR)/$(BUILDDIR) &&\
		cmake .. && cmake --build . --target install


# == CLEAN TARGETS == 
.PHONY: clean

# removes all built files
clean:
	rm -R -f $(ROOTDIR)/$(BUILDDIR)
	rm -R -f $(ROOTDIR)/install

