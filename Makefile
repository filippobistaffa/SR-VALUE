.PHONY: all

ifndef OUT
OUT=./csvalue
endif

CMP=g++
WARN=-Wall -Wno-unused-result -Wno-deprecated-declarations -Wno-sign-compare -Wno-maybe-uninitialized
OPTIM=-Ofast -march=native -funroll-loops -funsafe-loop-optimizations -falign-functions=16 -falign-loops=16 -fopenmp
NOOPTIM=-O0 -march=native -fopenmp
DBG=-g ${NOOPTIM}

COBJSUBDIR=cobj
DEPSUBDIR=dep

ECHOCC=>&2 echo "[\033[01;33m CC \033[0m]"
ECHOLD=>&2 echo "[\033[01;36m LD \033[0m]"

OPT=${NOOPTIM} # Put desired optimisation level here

define compilec
${ECHOCC} $(notdir $<) ;\
mkdir -p ${DEPSUBDIR} ;\
tmp=`mktemp` ;\
${CMP} ${DEFS} ${INC} -MM ${OPT} $< >> $$tmp ;\
if [ $$? -eq 0 ] ;\
then echo -n "${COBJSUBDIR}/" > ${DEPSUBDIR}/$(notdir $<).d ;\
cat $$tmp >> ${DEPSUBDIR}/$(notdir $<).d ;\
rm $$tmp ;\
mkdir -p ${COBJSUBDIR} ;\
cd ${COBJSUBDIR} ;\
${CMP} ${DEFS} -c ${INC} ${OPT} ${WARN} ../$< ;\
else \
ret=$$? ;\
rm $$tmp ;\
exit $$ret ;\
fi
endef

all: csvalue
	@true

-include ${DEPSUBDIR}/*.d

csvalue: ${COBJSUBDIR}/csvalue.o ${COBJSUBDIR}/io.o ${COBJSUBDIR}/sp.o ${COBJSUBDIR}/value.o
	@${ECHOLD} csvalue
	@${CMP} ${OPT} ${LDIR} $^ ${LINK} -o ${OUT}

${COBJSUBDIR}/value.o: value.cpp
	@$(compilec)

${COBJSUBDIR}/io.o: io.cpp
	@$(compilec)

${COBJSUBDIR}/sp.o: sp.cpp
	@$(compilec)

${COBJSUBDIR}/csvalue.o: csvalue.cpp
	@$(compilec)

clean:
	@echo "Removing subdirectories..."
	@rm -rf ${COBJSUBDIR} ${DEPSUBDIR}

run:
	./csvalue.sh test.sol
