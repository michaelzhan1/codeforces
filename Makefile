CXX = g++
CXXFLAGS = -Wall

# Pattern rule: target matches directory name
# Use a FORCE phony dependency so the rule runs even if a directory with
# the same name as the target exists (which makes make think the target
# is up-to-date). Compile to a.out and run with the corresponding input.
%: %.cpp
	$(CXX) $(CXXFLAGS) $< && ./a.out < $*.txt
