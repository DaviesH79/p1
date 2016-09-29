driver: driver.o statemodel.o state.o system.o accepting.o processing.o manufacturing.o shipping.o
				gcc -pthread driver.o statemodel.o state.o system.o accepting.o processing.o manufacturing.o shipping.o -o driver

driver.o: driver.c system.h statemodel.h
				gcc -c driver.c

statemodel.o: statemodel.c statemodel.h system.h
				gcc -c statemodel.c

state.o: state.c state.h
				gcc -c state.c

system.o: system.c system.h
				gcc -c system.c

accepting.o: accepting.c accepting.h system.h state.h statemodel.h
				gcc -c accepting.c

processing.o: processing.c processing.h system.h state.h statemodel.h 	
				gcc -c processing.c

manufacturing.o: manufacturing.c manufacturing.h  system.h state.h statemodel.h
				gcc -c manufacturing.c

shipping.o: shipping.c shipping.h system.h state.h statemodel.h
				gcc -c shipping.c

clean: 
				rm *.o ; rm driver	
