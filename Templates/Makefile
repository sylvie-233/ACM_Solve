compile: ACM_Template_C++.cpp
	clang-format -i -style=google $(<)
	clang++ -c $(<) -std=c++23 -v

format: ACM_Template_C++.cpp
	clang-format -i -style=google $(<)

clean:
	pwsh -c "Remove-Item *.o"