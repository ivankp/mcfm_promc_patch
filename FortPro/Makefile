ifneq ($(MAKECMDGOALS),clean)
  ifndef PROMC
    $(error PROMC env variable is not set. Run setup.sh first)
  endif
endif

OBJ_FORT := obj/interface.o obj/promcfortran.o
OBJ_PRO  := obj/ProMCBook.o obj/ProMCDescription.pb.o obj/ProMCHeader.pb.o obj/ProMC.pb.o obj/ProMCStat.pb.o
OBJ := $(OBJ_PRO) $(OBJ_FORT)

.PHONY: all clean

all: libFortPro.a

libFortPro.a: $(OBJ)
	ar rcs $@ $^

$(OBJ_FORT): obj/%.o: src/%.cxx | obj
	g++ -O3 -Wall -fPIC -Isrc -I${PROMC}/include -Isrc_promc -o $@ -c $<

$(OBJ_PRO): obj/%.o: src_promc/%.cc | obj
	g++ -O3 -Wall -fPIC -Isrc -I${PROMC}/include -Isrc_promc -o $@ -c $<
	
obj:
	mkdir $@

clean:
	rm -rf obj libFortPro.a

