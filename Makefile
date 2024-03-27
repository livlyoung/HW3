all:
	g++ -Wall TimeCode.cpp TimeCodeTests.cpp -o time-code
	g++ -Wall TimeCode.cpp NASALaunchAnalysis.cpp -o nasa
	g++ -Wall TimeCode.cpp PaintDryTimerStarter.cpp -o pdt
run:
	./nasa
	./pdt

try: all run