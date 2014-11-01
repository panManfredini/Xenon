Target  = do.exe
Objects = XenonDataReader.o XenonDataReaderT3.o XenonDataReaderT1.o

ROOTFLAGS = $(shell root-config --cflags)
ROOTLIBS  = $(shell root-config --libs)
READERDIR = /srv01/xenon/manfredi/CODE/Xenon/DataReader/

all:$(Target)

do.exe: main.C $(Objects)
	g++ -o $@ main.C $(Objects) $(ROOTFLAGS) $(ROOTLIBS)

XenonDataReader.o: $(READERDIR)XenonDataReader.C $(READERDIR)XenonDataReader.h
	g++ -o $@ $(READERDIR)XenonDataReader.C -c $(ROOTFLAGS)

XenonDataReaderT3.o: $(READERDIR)XenonDataReaderT3.C $(READERDIR)XenonDataReaderT3.h
	g++ -o $@ $(READERDIR)XenonDataReaderT3.C -c $(ROOTFLAGS)

XenonDataReaderT1.o: $(READERDIR)XenonDataReaderT1.C $(READERDIR)XenonDataReaderT1.h
	g++ -o $@ $(READERDIR)XenonDataReaderT1.C -c $(ROOTFLAGS)
