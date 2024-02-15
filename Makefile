CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic

Dentist_Programme: Dentist_Programme.cpp Print_Functions.h
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: clean
clean:
	$(RM) *.o Dentist_Programme
