CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic

all: Dentist_Programme Dentist_Test Quicksort_Test

Dentist_Test: Dentist_Programme.cpp Print_Functions.h
	$(CXX) $(CXXFLAGS) -o $@ $^

Dentist_Programme: main.cpp Person.o Dentist.o Patient.o Appointment.o Quicksort.o CSVSearcher.o AppointmentDisplay.o DentistManager.o AppointmentManager.o DateTimeUtils.o
	$(CXX) $(CXXFLAGS) -o $@ $^

Quicksort_Test: main.cpp Person.o Dentist.o Patient.o Appointment.o Quicksort.o CSVSearcher.o AppointmentDisplay.o DentistManager.o AppointmentManager.o DateTimeUtils.o
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
