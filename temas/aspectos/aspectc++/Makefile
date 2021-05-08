ACFLAGS ?= -v1 -k
ACXX    ?= $(PWD)/ag++
export ACXX

%.run: %
	make -C aspectos/$< run

%.clean: %
	make -C aspectos/$< clean
