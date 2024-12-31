
#include <iostream>
#include "FST.h" 

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	FST::FST fst1(
		"aaabbbaba",
		4,
		FST::NODE(3, FST::RELATION('a', 0), FST::RELATION('b', 0), FST::RELATION('a', 1)),
		FST::NODE(1, FST::RELATION('b', 2)),
		FST::NODE(1, FST::RELATION('a', 3)),
		FST::NODE()
	);
	if (FST::execute(fst1))
		cout << "Цепочка " << fst1.strin << " распознана\n";
	else
		cout << "Цепочка " << fst1.strin << " не распознана\n";

	FST::FST fst2(
		"aaabbbabba",
		4,
		FST::NODE(3, FST::RELATION('a', 0), FST::RELATION('b', 0), FST::RELATION('a', 1)),
		FST::NODE(1, FST::RELATION('b', 2)),
		FST::NODE(1, FST::RELATION('a', 3)),
		FST::NODE()
	);
	if (FST::execute(fst2))
		cout << "Цепочка " << fst2.strin << " распознана\n";
	else
		cout << "Цепочка " << fst2.strin << " не распознана\n";

	FST::FST fst3(
		"rbcldbcclfb",
		9,
		//return = r 
		// ; = b
		// □ = c
		// calc = d
		// print = e
		// end = f
		// λ = l
		FST::NODE(1, FST::RELATION('r', 1)), // 0
		FST::NODE(1, FST::RELATION('b', 2)), // 1
		FST::NODE(2, FST::RELATION('c', 2), FST::RELATION('l',3)), // 2
		FST::NODE(2, FST::RELATION('d', 4), FST::RELATION('e',4)), // 3
		FST::NODE(2, FST::RELATION('b', 3), FST::RELATION('b',5)), // 4
		FST::NODE(2, FST::RELATION('c', 5), FST::RELATION('l',6)), // 5
		FST::NODE(1, FST::RELATION('f', 7)), // 6
		FST::NODE(1, FST::RELATION('b', 8)), // 7
		FST::NODE() // 8
	);
	if (FST::execute(fst3))
		cout << "Цепочка " << fst3.strin << " распознана\n";
	else
		cout << "Цепочка " << fst3.strin << " не распознана\n";

	FST::FST fst4(
		"rbclebcclfb",
		9,
		//return = r 
		// ; = b
		// □ = c
		// calc = d
		// print = e
		// end = f
		// λ = l
		FST::NODE(1, FST::RELATION('r', 1)), // 0
		FST::NODE(1, FST::RELATION('b', 2)), // 1
		FST::NODE(2, FST::RELATION('c', 2), FST::RELATION('l', 3)), // 2
		FST::NODE(2, FST::RELATION('d', 4), FST::RELATION('e', 4)), // 3
		FST::NODE(2, FST::RELATION('b', 3), FST::RELATION('b', 5)), // 4
		FST::NODE(2, FST::RELATION('c', 5), FST::RELATION('l', 6)), // 5
		FST::NODE(1, FST::RELATION('f', 7)), // 6
		FST::NODE(1, FST::RELATION('b', 8)), // 7
		FST::NODE() // 8
	);
	if (FST::execute(fst4))
		cout << "Цепочка " << fst4.strin << " распознана\n";
	else
		cout << "Цепочка " << fst4.strin << " не распознана\n";

	FST::FST fst5(
		"rbldbdblfb",
		9,
		//return = r 
		// ; = b
		// □ = c
		// calc = d
		// print = e
		// end = f
		// λ = l
		FST::NODE(1, FST::RELATION('r', 1)), // 0
		FST::NODE(1, FST::RELATION('b', 2)), // 1
		FST::NODE(2, FST::RELATION('c', 2), FST::RELATION('l', 3)), // 2
		FST::NODE(2, FST::RELATION('d', 4), FST::RELATION('e', 4)), // 3
		FST::NODE(2, FST::RELATION('b', 3), FST::RELATION('b', 5)), // 4
		FST::NODE(2, FST::RELATION('c', 5), FST::RELATION('l', 6)), // 5
		FST::NODE(1, FST::RELATION('f', 7)), // 6
		FST::NODE(1, FST::RELATION('b', 8)), // 7
		FST::NODE() // 8
	);
	if (FST::execute(fst5))
		cout << "Цепочка " << fst5.strin << " распознана\n";
	else
		cout << "Цепочка " << fst5.strin << " не распознана\n";

	FST::FST fst6(
		"rbcccldbeblfb",
		9,
		//return = r 
		// ; = b
		// □ = c
		// calc = d
		// print = e
		// end = f
		// λ = l
		FST::NODE(1, FST::RELATION('r', 1)), // 0
		FST::NODE(1, FST::RELATION('b', 2)), // 1
		FST::NODE(2, FST::RELATION('c', 2), FST::RELATION('l', 3)), // 2
		FST::NODE(2, FST::RELATION('d', 4), FST::RELATION('e', 4)), // 3
		FST::NODE(2, FST::RELATION('b', 3), FST::RELATION('b', 5)), // 4
		FST::NODE(2, FST::RELATION('c', 5), FST::RELATION('l', 6)), // 5
		FST::NODE(1, FST::RELATION('f', 7)), // 6
		FST::NODE(1, FST::RELATION('b', 8)), // 7
		FST::NODE() // 8
	);
	if (FST::execute(fst6))
		cout << "Цепочка " << fst6.strin << " распознана\n";
	else
		cout << "Цепочка " << fst6.strin << " не распознана\n";

	FST::FST fst7(
		"rbleblfb",
		9,
		//return = r 
		// ; = b
		// □ = c
		// calc = d
		// print = e
		// end = f
		// λ = l
		FST::NODE(1, FST::RELATION('r', 1)), // 0
		FST::NODE(1, FST::RELATION('b', 2)), // 1
		FST::NODE(2, FST::RELATION('c', 2), FST::RELATION('l', 3)), // 2
		FST::NODE(2, FST::RELATION('d', 4), FST::RELATION('e', 4)), // 3
		FST::NODE(2, FST::RELATION('b', 3), FST::RELATION('b', 5)), // 4
		FST::NODE(2, FST::RELATION('c', 5), FST::RELATION('l', 6)), // 5
		FST::NODE(1, FST::RELATION('f', 7)), // 6
		FST::NODE(1, FST::RELATION('b', 8)), // 7
		FST::NODE() // 8
	);
	if (FST::execute(fst7))
		cout << "Цепочка " << fst7.strin << " распознана\n";
	else
		cout << "Цепочка " << fst7.strin << " не распознана\n";

	FST::FST fst8(
		"rbclebebclfb",
		9,
		//return = r 
		// ; = b
		// □ = c
		// calc = d
		// print = e
		// end = f
		// λ = l
		FST::NODE(1, FST::RELATION('r', 1)), // 0
		FST::NODE(1, FST::RELATION('b', 2)), // 1
		FST::NODE(2, FST::RELATION('c', 2), FST::RELATION('l', 3)), // 2
		FST::NODE(2, FST::RELATION('d', 4), FST::RELATION('e', 4)), // 3
		FST::NODE(2, FST::RELATION('b', 3), FST::RELATION('b', 5)), // 4
		FST::NODE(2, FST::RELATION('c', 5), FST::RELATION('l', 6)), // 5
		FST::NODE(1, FST::RELATION('f', 7)), // 6
		FST::NODE(1, FST::RELATION('b', 8)), // 7
		FST::NODE() // 8
	);
	if (FST::execute(fst8))
		cout << "Цепочка " << fst8.strin << " распознана\n";
	else
		cout << "Цепочка " << fst8.strin << " не распознана\n";

	FST::FST fst9(
		"rbcccldbdbdbccclfb",
		9,
		//return = r 
		// ; = b
		// □ = c
		// calc = d
		// print = e
		// end = f
		// λ = l
		FST::NODE(1, FST::RELATION('r', 1)), // 0
		FST::NODE(1, FST::RELATION('b', 2)), // 1
		FST::NODE(2, FST::RELATION('c', 2), FST::RELATION('l', 3)), // 2
		FST::NODE(2, FST::RELATION('d', 4), FST::RELATION('e', 4)), // 3
		FST::NODE(2, FST::RELATION('b', 3), FST::RELATION('b', 5)), // 4
		FST::NODE(2, FST::RELATION('c', 5), FST::RELATION('l', 6)), // 5
		FST::NODE(1, FST::RELATION('f', 7)), // 6
		FST::NODE(1, FST::RELATION('b', 8)), // 7
		FST::NODE() // 8
	);
	if (FST::execute(fst9))
		cout << "Цепочка " << fst9.strin << " распознана\n";
	else
		cout << "Цепочка " << fst9.strin << " не распознана\n";

	FST::FST fst10(
		"rleblfb",
		9,
		//return = r 
		// ; = b
		// □ = c
		// calc = d
		// print = e
		// end = f
		// λ = l
		FST::NODE(1, FST::RELATION('r', 1)), // 0
		FST::NODE(1, FST::RELATION('b', 2)), // 1
		FST::NODE(2, FST::RELATION('c', 2), FST::RELATION('l', 3)), // 2
		FST::NODE(2, FST::RELATION('d', 4), FST::RELATION('e', 4)), // 3
		FST::NODE(2, FST::RELATION('b', 3), FST::RELATION('b', 5)), // 4
		FST::NODE(2, FST::RELATION('c', 5), FST::RELATION('l', 6)), // 5
		FST::NODE(1, FST::RELATION('f', 7)), // 6
		FST::NODE(1, FST::RELATION('b', 8)), // 7
		FST::NODE() // 8
	);
	if (FST::execute(fst10))
		cout << "Цепочка " << fst10.strin << " распознана\n";
	else
		cout << "Цепочка " << fst10.strin << " не распознана\n";

	FST::FST fst11(
		"rbcldbcclf",
		9,
		//return = r 
		// ; = b
		// □ = c
		// calc = d
		// print = e
		// end = f
		// λ = l
		FST::NODE(1, FST::RELATION('r', 1)), // 0
		FST::NODE(1, FST::RELATION('b', 2)), // 1
		FST::NODE(2, FST::RELATION('c', 2), FST::RELATION('l', 3)), // 2
		FST::NODE(2, FST::RELATION('d', 4), FST::RELATION('e', 4)), // 3
		FST::NODE(2, FST::RELATION('b', 3), FST::RELATION('b', 5)), // 4
		FST::NODE(2, FST::RELATION('c', 5), FST::RELATION('l', 6)), // 5
		FST::NODE(1, FST::RELATION('f', 7)), // 6
		FST::NODE(1, FST::RELATION('b', 8)), // 7
		FST::NODE() // 8
	);
	if (FST::execute(fst11))
		cout << "Цепочка " << fst11.strin << " распознана\n";
	else
		cout << "Цепочка " << fst11.strin << " не распознана\n";
	
	return 0;
}