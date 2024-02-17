CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic

all: Dentist_Programme Quicksort_Test

Dentist_Programme: Dentist_Programme.cpp Print_Functions.h
	$(CXX) $(CXXFLAGS) -o $@ $^

Quicksort_Test: main.cpp Person.o Dentist.o Patient.o Appointment.o Quicksort.o
	$(CXX) $(CXXFLAGS) -o $@ $^

Person.o: Person.cpp Person.h
	$(CXX) $(CXXFLAGS) -c $<

Dentist.o: Dentist.cpp Dentist.h
	$(CXX) $(CXXFLAGS) -c $<

Patient.o: Patient.cpp Patient.h
	$(CXX) $(CXXFLAGS) -c $<

Appointment.o: Appointment.cpp Appointment.h
	$(CXX) $(CXXFLAGS) -c $<

Quicksort.o: Quicksort.cpp Quicksort.h
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: clean
clean:
	$(RM) *.o Dentist_Programme
