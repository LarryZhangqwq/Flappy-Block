FLAGS = -pedantic-errors -std=c++11

bin/Ranklist_process_function.o : src/Ranklist_process_function.cpp src/Ranklist_process_function.h
	g++ $(FLAGS) -c $< -o $@

bin/Start_and_end_function.o : src/Start_and_end_function.cpp src/Start_and_end_function.h
	g++ $(FLAGS) -c $< -o $@

bin/Skill.o : src/Skill.cpp src/Skill.h
	g++ $(FLAGS) -c $< -o $@

bin/Count_marks.o : src/Count_marks.cpp src/Count_marks.h
	g++ $(FLAGS) -c $< -o $@

bin/Wall_create_function.o : src/Wall_create_function.cpp src/Wall_create_function.h
	g++ $(FLAGS) -c $< -o $@

bin/Refresh_scoreboard.o : src/Refresh_scoreboard.cpp src/Refresh_scoreboard.h
	g++ $(FLAGS) -c $< -o $@

bin/Display_function.o : src/Display_functions.cpp src/Display_functions.h
	g++ $(FLAGS) -c $< -o $@

bin/main.o : src/main.cpp src/Display_functions.h src/Refresh_scoreboard.h src/Wall_create_function.h src/Count_marks.h src/Skill.h src/Start_and_end_function.h src/Ranklist_process_function.h
	g++ $(FLAGS) -c $< -o $@
	
main : bin/main.o bin/Display_function.o bin/Refresh_scoreboard.o bin/Wall_create_function.o bin/Count_marks.o bin/Skill.o Start_and_end_function.o bin/Ranklist_process_function.o
	g++ $(FLAGS) $^ -o main
