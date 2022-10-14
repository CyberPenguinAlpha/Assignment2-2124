stackLinkedList: stackLinkedList.o stackDemo.o
								 gcc stackLinkedList.o  stackDemo.o -o stackLinkedList

stackLinkedList.o: stackLinkedList.c
									 gcc -c stackLinkedList.c -o stackLinkedList.o
 
stackDemo.o: stackDemo.c
						 gcc -c stackDemo.c -o stackDemo.o

clean:
			rm *.o
			rm stackLinkedList