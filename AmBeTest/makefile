Target  = run_AmBeTest
Objects = XenonDataReader.o XenonDataReaderT3.o XenonDataReaderT1.o AmBeTest.o

ROOTFLAGS = $(shell root-config --cflags)
ROOTLIBS  = $(shell root-config --libs)
READERDIR =/home/manfredini/Xenon/DataReader/

all:$(Target)

run_AmBeTest: main.C $(Objects)
	g++ -o $@ main.C $(Objects) $(ROOTFLAGS) $(ROOTLIBS) -I$(READERDIR) 

XenonDataReader.o: $(READERDIR)XenonDataReader.C  $(READERDIR)XenonDataReader.h $(READERDIR)XenonDataReaderT3.h $(READERDIR)XenonDataReaderT1.h $(READERDIR)XenonDataReaderT3.C $(READERDIR)XenonDataReaderT1.C
	g++ -o $@  $(READERDIR)XenonDataReader.C -c $(ROOTFLAGS)

XenonDataReaderT3.o: $(READERDIR)XenonDataReaderT3.C $(READERDIR)XenonDataReaderT3.h
	g++ -o $@ $(READERDIR)XenonDataReaderT3.C -c $(ROOTFLAGS) 

XenonDataReaderT1.o: $(READERDIR)XenonDataReaderT1.C $(READERDIR)XenonDataReaderT1.h
	g++ -o $@ $(READERDIR)XenonDataReaderT1.C -c $(ROOTFLAGS)

AmBeTest.o: AmBeTest.C AmBeTest.h $(READERDIR)XenonDataReader.C $(READERDIR)XenonDataReader.h
	g++ -o $@ AmBeTest.C -c $(ROOTFLAGS) -I$(READERDIR)
