#include "V10.H"
#include "V11.H"


/**
 *
 * \brief unit tests for List<T>
 *
 *
 */
namespace V12{ // namespace for testing the list implementation of the ring buffer

using namespace V11;  // unit test implementation namespace

using namespace V10; //  ring buffer mplementation namespace

class TC13 : public TestCase{
	TC13() : TestCase(){};
public:
	TC13(string s) : TestCase(s){};
	virtual bool testRun(){
		List<int> l;
		int output;
		l.prepend(-1);
		l.prepend(0);
		l.prepend(1);

		try{
			output = l.removeLast();
			if(output == -1){
				;;
			}else{
				return false;
			}

			output = l.removeLast();
			if(output == 0){
				;;
			}else{
				return false;
			}

			output = l.removeLast();
			if(output == 1){
				;;
			}else{
				return false;
			}

			return true;
		}catch(...){
			return false;
		}
	}
};

class TC12 : public TestCase{
	TC12() : TestCase(){};
public:
	TC12(string s) : TestCase(s){};
	virtual bool testRun(){
		List<int> l;
		int output;
		l.prepend(-1);
		l.prepend(0);
		l.prepend(1);

		try{
			output = l.removeFirst();
			if(output == 1){
				;;
			}else{
				return false;
			}

			output = l.removeFirst();
			if(output == 0){
				;;
			}else{
				return false;
			}

			output = l.removeFirst();
			if(output == -1){
				;;
			}else{
				return false;
			}

			return true;
		}catch(...){
			return false;
		}
	}
};

class TC11 : public TestCase{
	TC11() : TestCase(){};
public:
	TC11(string s) : TestCase(s){};
	virtual bool testRun(){
		List<int> l;
		int output;
		l.append(-1);
		l.append(0);
		l.append(1);

		try{
			output = l.removeLast();
			if(output == 1){
				;;
			}else{
				return false;
			}

			output = l.removeLast();
			if(output == 0){
				;;
			}else{
				return false;
			}

			output = l.removeLast();
			if(output == -1){
				;;
			}else{
				return false;
			}

			return true;
		}catch(...){
			return false;
		}
	}
};


class TC10 : public TestCase{
	TC10() : TestCase(){};
public:
	TC10(string s) : TestCase(s){};
	virtual bool testRun(){
		List<int> l;
		int output;
		l.append(-1);
		l.append(0);
		l.append(1);

		try{
			output = l.removeFirst();
			if(output == -1){
				;;
			}else{
				return false;
			}

			output = l.removeFirst();
			if(output == 0){
				;;
			}else{
				return false;
			}

			output = l.removeFirst();
			if(output == 1){
				;;
			}else{
				return false;
			}

			return true;
		}catch(...){
			return false;
		}
	}
};


class TC9 : public TestCase{
	TC9() : TestCase(){};
public:
	TC9(string s) : TestCase(s){};
	virtual bool testRun(){
		List<int> l;
		int input = 12331;
		int output;
		l.append(input);
		try{
			output = l.removeLast();
			if(input == output){
				return true;
			}else{
				return false;
			}
		}catch(...){
			return false;
		}
	}
};


class TC8 : public TestCase{
	TC8() : TestCase(){};
public:
	TC8(string s) : TestCase(s){};
	virtual bool testRun(){
		List<int> l;
		l.prepend(1);
		try{
			l.removeLast();
			return true;
		}catch(...){
			return false;
		}
	}
};

class TC7 : public TestCase{
	TC7() : TestCase(){};
public:
	TC7(string s) : TestCase(s){};
	virtual bool testRun(){
		List<int> l;

		try{
			l.removeLast();
			return false;
		}catch(string s){
			return true;
		}catch(...){
			return false;
		}
	}
};






class TC6 : public TestCase{
	TC6() : TestCase(){};
public:
	TC6(string s) : TestCase(s){};
	virtual bool testRun(){
		List<int> l;
		int input = 12331;
		int output;
		l.prepend(input);
		try{
			output = l.removeFirst();
			if(input == output){
				return true;
			}else{
				return false;
			}
		}catch(...){
			return false;
		}
	}
};


class TC5 : public TestCase{
	TC5() : TestCase(){};
public:
	TC5(string s) : TestCase(s){};
	virtual bool testRun(){
		List<int> l;
		l.append(1);
		try{
			l.removeFirst();
			return true;
		}catch(...){
			return false;
		}
	}
};

class TC4 : public TestCase{
	TC4() : TestCase(){};
public:
	TC4(string s) : TestCase(s){};
	virtual bool testRun(){
		List<int> l;

		try{
			l.removeFirst();
			return false;
		}catch(string s){
			return true;
		}catch(...){
			return false;
		}
	}
};

class TC1 : public TestCase{
	TC1() : TestCase(){};
public:
	TC1(string s) : TestCase(s){};
	virtual bool testRun(){
		List<int> l;

		try{
			if(l.isEmpty()){
				return true;
			}else{
				return false;
			}
		}catch(...){
			return false;
		}

	}
};

class TC2 : public TestCase{
	TC2() : TestCase(){};
public:
	TC2(string s) : TestCase(s){};
	virtual bool testRun(){
		List<int> l;

		try{
			l.append(1);

			if(l.isEmpty()){
				return false;
			}else{
				return true;
			}
		}catch(...){
			return false;
		}

	}
};

class TC3 : public TestCase{
	TC3() : TestCase(){};
public:
	TC3(string s) : TestCase(s){};
	virtual bool testRun(){
		List<int> l;

		try{
			l.append(1);
			l.removeFirst();

			if(l.isEmpty()){
				return true;
			}else{
				return false;
			}
		}catch(...){
			return false;
		}

	}
};

}

void demoV11_TestList(){

	/**
	 * Test cases
	 *
	 */
	V12::TC1 tc1("isEmpty - empty List");
	V12::TC2 tc2("isEmpty - non empty List");
	V12::TC3 tc3("isEmpty - empty List again");

	V12::TC4 tc4("removeFirst - empty List");
	V12::TC5 tc5("removeFirst - non empty List");
	V12::TC6 tc6("removeFirst - compare result");

	V12::TC7 tc7("removeLast - empty List");
	V12::TC8 tc8("removeLast - non empty List");
	V12::TC9 tc9("removeLast - compare result");

	V12::TC10 tc10("append - removeFirst");
	V12::TC11 tc11("append - removeLast");

	V12::TC12 tc12("prepend - removeFirst");
	V12::TC13 tc13("prepend - removeLast");


	/**
	 *
	 * Test Suites
	 *
	 */
	V11::TestSuite tsIsEmpty("isEmpty");
	tsIsEmpty.addTestItem(&tc1);
	tsIsEmpty.addTestItem(&tc2);
	tsIsEmpty.addTestItem(&tc3);

	V11::TestSuite tsRemoveFirst("removeFirst");
	tsRemoveFirst.addTestItem(&tc4);
	tsRemoveFirst.addTestItem(&tc5);
	tsRemoveFirst.addTestItem(&tc6);

	V11::TestSuite tsRemoveLast("removeLast");
	tsRemoveLast.addTestItem(&tc7);
	tsRemoveLast.addTestItem(&tc8);
	tsRemoveLast.addTestItem(&tc9);

	V11::TestSuite tsPrepend("Prepend");
	tsPrepend.addTestItem(&tc12);
	tsPrepend.addTestItem(&tc13);

	V11::TestSuite tsAppend("Append");
	tsAppend.addTestItem(&tc10);
	tsAppend.addTestItem(&tc11);


	/**
	 *
	 * unit test
	 *
	 */
	V11::UnitTest unit("V10DL::List");
	unit.addTestItem(&tsIsEmpty);
	unit.addTestItem(&tsRemoveFirst);
	unit.addTestItem(&tsRemoveLast);
	unit.addTestItem(&tsPrepend);
	unit.addTestItem(&tsAppend);

	unit.testExecution();
	unit.writeResultsToFile("out.xml");



}
