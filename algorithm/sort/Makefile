all: bubble_sort quick_sort merge_sort heap_sort

test: all
	@echo "========== Bubble Sort =========="
	@time -p ./bubble_sort < test1.txt
	@time -p ./bubble_sort < test2.txt
	@time -p ./bubble_sort < test3.txt
	@echo "========== Quick Sort =========="
	@time -p ./quick_sort < test1.txt
	@time -p ./quick_sort < test2.txt
	@time -p ./quick_sort < test3.txt
	@echo "========== Merge Sort =========="
	@time -p ./merge_sort < test1.txt
	@time -p ./merge_sort < test2.txt
	@time -p ./merge_sort < test3.txt
	@echo "========== Heap Sort =========="
	@time -p ./heap_sort < test1.txt
	@time -p ./heap_sort < test2.txt
	@time -p ./heap_sort < test3.txt

bubble_sort:
	g++ -std=c++11 -o bubble_sort main.cpp bubble_sort.cpp

quick_sort:
	g++ -std=c++11 -o quick_sort main.cpp quick_sort.cpp

merge_sort:
	g++ -std=c++11 -o merge_sort main.cpp merge_sort.cpp

heap_sort:
	g++ -std=c++11 -o heap_sort main.cpp heap_sort.cpp

clean:
	rm -f bubble_sort quick_sort merge_sort heap_sort
